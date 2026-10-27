/**
 * @file        main.c
 *
 * @brief       Main program body
 *
 * @version     V1.0.1
 *
 * @date        2026-07-31
 *
 * @attention
 *
 *  Copyright (C) 2025 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be useful and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */

/* Includes ***************************************************************/
#include "main.h"

/* Private includes *******************************************************/
#include <stdio.h>

/* Private macro **********************************************************/
#define DEBUG_USART COM2_PORT

#define SPI_CLK_PIN   DDL_GPIO_PIN_9
#define SPI_CLK_PORT  GPIOC
#define SPI_CLK_AF    DDL_GPIO_AF_3

#define SPI_MISO_PIN  DDL_GPIO_PIN_2
#define SPI_MISO_PORT GPIOD
#define SPI_MISO_AF   DDL_GPIO_AF_3

/* BS parameters */
#define BS_IDL  0x05     /* Fixed ID for BS slave */

/* Private typedef ********************************************************/
/* Encoder parameters structure */
typedef struct
{
    /* Final output angle */
    uint32_t angle;
    /* Electrical angle */
    uint32_t ele_angle;
    /* Mechanical angle */
    uint32_t mach_angle;
    uint8_t status;
    uint8_t crc;
    /* Current Gray code */
    uint8_t gray;
    /* Previous Gray code */
    uint8_t gray_old;
    /* Error flag bit */
    uint8_t error_bit;
} ENC_PARAM_T;

/* Encoder communication structure */
typedef struct
{
    /* Command ID */
    uint8_t cmd_id;
    /* Status register */
    uint8_t sf;
    /* Alarm register */
    uint8_t almc;
    /* Encoder bit length */
    uint8_t enid;
    /* Number of received bytes */
    uint8_t receive_num;
    /* EEPROM page address */
    uint8_t eeprom_page;
    /* Communication end flag bit */
    uint8_t end_bit;
    /* Communication status */
    uint8_t sts;

    /* BS CDM data (bit) */
    uint8_t bs_cdm;
    /* BS CDS data (bit) */
    uint8_t bs_cds;
    /* Number of consecutive zeros in BS CDM */
    uint8_t bs_cdm_zero_num;
    /* BS slave ID */
    uint8_t bs_id;
    /* BS register address */
    uint8_t bs_adr;
    /* BS register address CRC4 */
    uint8_t bs_adr_crc;
    /* BS register data */
    uint8_t bs_data;
    /* BS register data CRC4 */
    uint8_t bs_data_crc;
    /* BS register RW flag bit: 0 is read, 1 is write, 2 is read/write error */
    uint8_t bs_rw_bit;
    /* BS temporary counter */
    uint8_t bs_num;
    /* BS reg communication status:
       0 indicates non-register communication,
       1 indicates communication start,
       2 indicates address transmission in progress,
       3 indicates read flag bit,
       4 indicates write flag bit,
       5 indicates data transmission start,
       6 indicates data transmission in progress,
       7 indicates data communication */
    uint8_t bs_reg_sts;
} ENC_COMM_T;

/* Private variables ******************************************************/
/* Encoder communication TX array */
/* Encoder communication send array */
SECTION_DTCM_DATA
uint8_t enc_send_data[20] = {0x0A, 0x01, 0x03, 0x05, 0x07, 0xff, 0x00};

/* Encoder communication receive array */
uint8_t enc_recrive_data[10] = {0};

/* BS register data, one page of data */
uint8_t bs_reg_data[128] = {0};

/* CRC4 of BS register data */
uint8_t bs_reg_crc[128] = {0};

/* Periodic data CRC6, used for BS testing */
uint64_t crc_tempx = 0;

/* Encoder parameter data structure */
volatile ENC_PARAM_T enc_param_data;

/* Encoder communication data structure */
volatile ENC_COMM_T enc_comm_data;

/* Private function prototypes ********************************************/
/* Core configuration functions */
void DDL_SysClkConfig(void);
void Cache_Enable(void);

/* Peripheral initialization functions */
void GPIO_Config(void);
void BiSS_Config(void);

/* Interrupt service routines */
void DMA1_Stream6_Isr(void);
void SPI_Isr(void);

/* Protocol handling functions */
void Param_Init(void);
void ENC_Comm_Bs_Handle(volatile ENC_COMM_T* enc_comm_temp);
uint8_t Calc_CRC4(uint8_t* buffer, uint8_t buf_size);
uint8_t Calc_CRC6(uint64_t buffer, uint8_t bits);

/* Delay function */
void Delay(uint32_t count);

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   Main program
 * @param   None
 * @retval  None
 */
int main(void)
{
    /* USART init structure */
    DDL_USART_InitTypeDef USART_InitStruct = {0U};

    /* Enable I-Cache and D-Cache */
    SCB_InvalidateDCache();
    SCB_InvalidateICache();
    SCB_EnableDCache();
    SCB_EnableICache();
    __DSB();
    __ISB();

    /* Configure system clock */
    DDL_SysClkConfig();

    /* USART configuration */
    USART_InitStruct.BaudRate            = 115200U;
    USART_InitStruct.DataWidth           = DDL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits            = DDL_USART_STOPBITS_1;
    USART_InitStruct.Parity              = DDL_USART_PARITY_NONE;
    USART_InitStruct.TransferDirection   = DDL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = DDL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling        = DDL_USART_OVERSAMPLING_16;
    BOARD_COMInit(COM2, &USART_InitStruct);

    /* Configure interrupt group 4: 4-bit preemptive priority, 0-bit subpriority */
    DDL_NVIC_ConfigPriorityGroup(DDL_NVIC_PRIORITY_GROUP_4);

    /* GPIO configuration */
    GPIO_Config();

    /* SPI configuration */
    BiSS_Config();

    /* Initialize parameters */
    Param_Init();

    /* Simulate single-cycle data: 44-bit user data (26 bits single-turn + 16 bits multi-turn + 2 bits alarm) */
    crc_tempx = ((uint64_t)enc_send_data[6] >> 6) |
                ((uint64_t)enc_send_data[5] << 2) |
                ((uint64_t)enc_send_data[4] << 10) |
                ((uint64_t)enc_send_data[3] << 18) |
                ((uint64_t)enc_send_data[2] << 26) |
                ((uint64_t)enc_send_data[1] << 34) |
                ((((uint64_t)enc_send_data[0] & 0x03) << 42));
    /* Calculate and update CRC6 for the 44-bit data */
    enc_send_data[6] = (enc_send_data[6] & 0xc0) | Calc_CRC6(crc_tempx, 44);

    /* Infinite loop */
    while (1)
    {
        /* Check if the communication end bit is set */
        if (enc_comm_data.end_bit == 1)
        {
            /* Handle BiSS communication */
            ENC_Comm_Bs_Handle(&enc_comm_data);

            /* Clear the end bit after handling */
            enc_comm_data.end_bit = 0;

            /* Simulate single-cycle data */
            enc_send_data[2]++; /* Increment single-turn data */
            crc_tempx = ((uint64_t)enc_send_data[6] >> 6) |
                        ((uint64_t)enc_send_data[5] << 2) |
                        ((uint64_t)enc_send_data[4] << 10) |
                        ((uint64_t)enc_send_data[3] << 18) |
                        ((uint64_t)enc_send_data[2] << 26) |
                        ((uint64_t)enc_send_data[1] << 34) |
                        ((((uint64_t)enc_send_data[0] & 0x03) << 42));
            /* Recalculate and update CRC6 for the updated data */
            enc_send_data[6] = (enc_send_data[6] & 0xc0) | Calc_CRC6(crc_tempx, 44);
        }
    }
}

/**
 * @brief   System clock configuration
 *
 * @param   None
 *
 * @retval  None
 */
void DDL_SysClkConfig(void)
{
    /* Unlock clock control registers */
    /* Wait until the registers are unlocked */
    DDL_RCM_Unlock();
    while ((RCM->KEY & RCM_KEY_KEYST) != RCM_KEY_KEYST) 
    { 
    }

    /* Enable HSE and wait for ready */
    /* Enable HSE input clock */
    DDL_RCM_HSE_Enable();
    /* Wait until HSE is ready */
    while (DDL_RCM_HSE_IsReady() != 1) 
    {
        /* wait for HSERDY */
    }

    /* Configure Flash wait states appropriate for 120 MHz */
    /* Set Flash wait period to accommodate higher frequency */
    DDL_FLASH_SetWaitPeriod(FLASH_DDL_WAIT_PERIOD_3);
    /* Set Flash erase time base to 120 MHz (use 119 to represent 120 MHz) */
    DDL_FLASH_SetEraseTimeBase(119);

    /* Configure PLL */
    /* Ensure PLL is disabled prior to configuration */
    DDL_RCM_PLL_Disable();

    /* Configure PLL settings: multiplier, prescaler, and clock source */
    /* PLL multiplier set to 15 (x15), prescaler no division, clock source from HSE */
    DDL_RCM_PLL_SetMultiplier(15);
    DDL_RCM_PLL_SetPrescaler(DDL_RCM_PLL_DIV1);
    DDL_RCM_PLL_SetClkSource(DDL_RCM_PLL_CLKSOURCE_HSE);

    /* Enable PLL and wait for ready */
    DDL_RCM_PLL_Enable();
    while (DDL_RCM_PLL_IsReady() != 1)
    {
        /* wait for PLL Ready */
    }

    /* Switch system clock to PLL output */
    DDL_RCM_SetSysClkSource(DDL_RCM_SYS_CLKSOURCE_PLL);

    /* Enable clock switch and wait for completion */
    DDL_RCM_EnableSysClkSwitch();
    while (DDL_RCM_IsActiveFlag_SWDONE() != 1)
    {
    }

    /* Set AHB, APB prescalers */
    DDL_RCM_SetAHBPrescaler(DDL_RCM_AHB_DIV_1);
    DDL_RCM_SetAPBPrescaler(DDL_RCM_APB_DIV_1);
    
    /* Disable clock switch controls */
    DDL_RCM_DisableSysClkSwitch();
    
    /* Lock clock control registers */
    DDL_RCM_Lock();

    /* Update SystemCoreClock if used by the project */
    SystemCoreClockUpdate();
}

/**
 * @brief   GPIO Configuration
 * @param   None
 * @retval  None
 */
void GPIO_Config(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0};

    DDL_RCM_Unlock();
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_Lock();

    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_NO;

    /* CLK Configuration */
    GPIO_InitStruct.Pin = SPI_CLK_PIN;
    GPIO_InitStruct.Alternate = SPI_CLK_AF;
    DDL_GPIO_Init(SPI_CLK_PORT, &GPIO_InitStruct);


    /* MISO Configuration */
    GPIO_InitStruct.Pin = SPI_MISO_PIN;
    GPIO_InitStruct.Alternate = SPI_MISO_AF;
    DDL_GPIO_Init(SPI_MISO_PORT, &GPIO_InitStruct);
}

/**
 * @brief   Configure BiSS-C Slave mode
 * @param   None
 * @retval  None
 */
void BiSS_Config(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    DDL_DMA_InitTypeDef DMA_InitStruct = {0};
    DDL_EINT_InitTypeDef EINT_InitStruct = {0};
    DDL_SPI_InitTypeDef SPI_InitStruct = {0};

    /* Initialize structure */
    DDL_GPIO_StructInit(&GPIO_InitStruct);
    DDL_DMA_StructInit(&DMA_InitStruct);
    DDL_EINT_StructInit(&EINT_InitStruct);
    DDL_SPI_StructInit(&SPI_InitStruct);

    DDL_SPI_DisableDMAReq_TX(SPI1);
    DDL_SPI_BISS_DisableBiss(SPI1);
    DDL_SPI_BISS_DisableStop(SPI1);

    DDL_RCM_Unlock();
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_DMA);
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_EINT);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_SPI);
    DDL_RCM_Lock();

    /* Configure DMA */
    DMA_InitStruct.Mode = DDL_DMA_MODE_NORMAL;
    DMA_InitStruct.PeriphOrM2MSrcIncMode = DDL_DMA_PERIPH_NOINCREMENT;
    DMA_InitStruct.MemoryOrM2MDstIncMode = DDL_DMA_MEMORY_INCREMENT;
    DMA_InitStruct.PeriphOrM2MSrcDataSize = DDL_DMA_PDATAALIGN_BYTE;
    DMA_InitStruct.MemoryOrM2MDstDataSize = DDL_DMA_MDATAALIGN_BYTE;
    /* Default to send 7 bytes */
    DMA_InitStruct.NbData = 7;
    DMA_InitStruct.Priority = DDL_DMA_PRIORITY_HIGH;
    DMA_InitStruct.FIFOMode = DDL_DMA_FIFOMODE_DISABLE;
    DMA_InitStruct.FIFOThreshold = DDL_DMA_FIFOTHRESHOLD_1_4;
    DMA_InitStruct.MemBurst = DDL_DMA_MBURST_SINGLE;
    DMA_InitStruct.PeriphBurst = DDL_DMA_PBURST_SINGLE;

    /* Configure SPI MISO DMA */
    /* Select channel 2 */
    DMA_InitStruct.Channel = DDL_DMA_CHANNEL_2;
    DMA_InitStruct.Direction = DDL_DMA_DIRECTION_MEMORY_TO_PERIPH;
    /* Set memory address */
    DMA_InitStruct.MemoryOrM2MDstAddress = (uint32_t)enc_send_data;
    /* Set peripheral address */
    DMA_InitStruct.PeriphOrM2MSrcAddress = (uint32_t)(&(SPI1->DATA));
    /* Configure data stream 6 */
    DDL_DMA_Init(DMA1, DDL_DMA_STREAM_6, &DMA_InitStruct);

    /* Configure PC9 as SPI_CLK/BS_MA */
    GPIO_InitStruct.Pin        = SPI_CLK_PIN;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Alternate  = SPI_CLK_AF;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    DDL_GPIO_Init(SPI_CLK_PORT, &GPIO_InitStruct);

    /* Configure PD2 as SPI_MISO/BS_SLO */
    GPIO_InitStruct.Pin        = SPI_MISO_PIN;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Alternate  = SPI_MISO_AF;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    DDL_GPIO_Init(SPI_MISO_PORT, &GPIO_InitStruct);

    SPI_InitStruct.TransferDirection = DDL_SPI_FULL_DUPLEX;
    SPI_InitStruct.Mode = DDL_SPI_MODE_SLAVE;
    SPI_InitStruct.DataWidth = DDL_SPI_DATAWIDTH_8BIT;
    SPI_InitStruct.ClockPolarity = DDL_SPI_POLARITY_HIGH;
    SPI_InitStruct.ClockPhase = DDL_SPI_PHASE_1EDGE;
    SPI_InitStruct.NSS = DDL_SPI_NSS_SOFT;
    SPI_InitStruct.BaudRate = DDL_SPI_BAUDRATEPRESCALER_DIV4;
    SPI_InitStruct.BitOrder = DDL_SPI_LSB_FIRST;
    SPI_InitStruct.CRCCalculation = DDL_SPI_CRCCALCULATION_DISABLE;
    DDL_SPI_Init(SPI1, &SPI_InitStruct);

    /* Enable SPI_TX DMA */
    DDL_SPI_EnableDMAReq_TX(SPI1);
    /* Enable DMA stream 6 */
    DDL_DMA_EnableStream(DMA1, DDL_DMA_STREAM_6);

    /* Set SPI clock frequency to 120 MHz */
    DDL_SPI_BISS_SetFrequency(SPI1, 120);
    /* Set timeout to 10 us */
    DDL_SPI_BISS_SetTimeout(SPI1, 10);

    /* Register SPI interrupt handler */
    DDL_Interrupt_Register(SPI_IRQn, &SPI_Isr);
    DDL_NVIC_EnableIRQRequest(SPI_IRQn, 2, 0);
    /* Enable CDM interrupt */
    DDL_SPI_EnableIT_CDM(SPI1);

    /* Register DMA stream 6 interrupt handler */
    DDL_Interrupt_Register(DMA1_Stream6_IRQn, &DMA1_Stream6_Isr);

    /* Enable DMA stream 6 interrupt with priority 1 */
    DDL_NVIC_EnableIRQRequest(DMA1_Stream6_IRQn, 1, 0);

    /* Enable DMA transfer complete interrupt */
    DDL_DMA_EnableIT_TC(DMA1, DDL_DMA_STREAM_6);

    /* Enable BiSS mode */
    DDL_SPI_BISS_EnableBiss(SPI1);
}

/**
 * @brief   DMA1 Stream 6 interrupt service routine.
 * @param   None
 * @retval  None
 */
void DMA1_Stream6_Isr(void)
{
    /* Check if the transfer complete interrupt flag is set */
    if (DDL_DMA_IsActiveFlag_TC6(DMA1) != 0)
    {
        /* Enable the STOP signal for SPI communication */
        DDL_SPI_BISS_EnableStop(SPI1);
    }

    /* Clear all DMA interrupt flags */
    DDL_DMA_ClearFlag_HT6(DMA1);

    /* Disable the DMA transfer complete interrupt */
    DDL_DMA_DisableIT_TC(DMA1, DDL_DMA_STREAM_6);
}

/**
 * @brief   SPI interrupt service routine for handling BiSS communication.
 * @param   None
 * @retval  None
 */
void SPI_Isr(void)
{
    /* Check if CDM data is available and TX buffer is empty */
    if ((DDL_SPI_IsActiveFlag_CDM_NE(SPI1)==1) && (DDL_SPI_IsActiveFlag_TXE(SPI1)==1))
    {
        /* Process CDM data */
        if (DDL_SPI_BISS_ReceiveCDMData(SPI1))
        {
            /* Adjust CDM value (master sends inverted CDM) */
            enc_comm_data.bs_cdm = 0;
        }
        else
        {
            /* Adjust CDM value (master sends inverted CDM) */
            enc_comm_data.bs_cdm = 1;
        }
    }
    else
    {
        /* CDM reception failed */
        enc_comm_data.sts = 1;
    }

    /* Clear SPI status register */
    SPI1->STS = 0;

    /* Clear all DMA flags */
    DMA1->HIFCLR = 0xFFFFFFFF;

    /* Mark communication as complete */
    enc_comm_data.end_bit = 1;
}

/**
 * @brief   Calculate 6-bit CRC for a given buffer and bit length.
 * @param   buffer: The input data buffer to calculate the CRC.
 * @param   bits: The number of bits in the input buffer.
 * @retval  The calculated 6-bit CRC value.
 */
uint8_t Calc_CRC6(uint64_t buffer, uint8_t bits)
{
    uint8_t i = 0;
    uint8_t poly = 0x43; /* Polynomial for CRC-6 calculation */
    uint8_t crc_temp = 0;

    /* Extract the initial 6 bits from the buffer */
    crc_temp = (uint8_t)(buffer >> (bits - 6));

    /* Perform the main CRC calculation */
    for (i = 0; i < (bits - 6); i++)
    {
        /* Check the current bit in the buffer */
        if (((buffer >> (bits - 7 - i)) & 0x01) == 1)
        {
            /* If the MSB of crc_temp is set, XOR with the polynomial */
            if ((crc_temp & 0x20) != 0)
                crc_temp = ((crc_temp << 1) | 0x01) ^ poly;
            else
                crc_temp = (crc_temp << 1) | 0x01;
        }
        else
        {
            /* If the MSB of crc_temp is set, XOR with the polynomial */
            if ((crc_temp & 0x20) != 0)
                crc_temp = (crc_temp << 1) ^ poly;
            else
                crc_temp = crc_temp << 1;
        }
    }

    /* Process the remaining 6 bits */
    for (i = 0; i < 6; i++)
    {
        /* If the MSB of crc_temp is set, XOR with the polynomial */
        if ((crc_temp & 0x20) != 0)
            crc_temp = (crc_temp << 1) ^ poly;
        else
            crc_temp = crc_temp << 1;
    }

    /* Invert the result and mask to 6 bits */
    crc_temp = (~crc_temp) & 0x3f;

    return crc_temp;
}

/**
 * @brief   Calculate 4-bit CRC for a given buffer.
 * @param   buffer: Pointer to the input data buffer.
 * @param   buf_size: Size of the input buffer in bytes.
 * @retval  The calculated 4-bit CRC value.
 */
uint8_t Calc_CRC4(uint8_t* buffer, uint8_t buf_size)
{
    /* Define the polynomial for CRC-4 calculation */
    uint8_t poly = 0x13;

    /* Temporary variable to store the CRC value */
    uint8_t crc_temp = 0;

    /* Iterate through each byte in the buffer */
    for (uint8_t i = 0; i < buf_size; i++)
    {
        /* XOR the current byte with the CRC value */
        crc_temp ^= buffer[i];

        /* Process each bit in the current byte */
        for (uint8_t j = 0; j < 8; j++)
        {
            /* Check if the MSB of crc_temp is set */
            if (crc_temp & 0x80)
            {
                /* Shift left and XOR with the polynomial */
                crc_temp = (crc_temp << 1) ^ (poly << 4);
            }
            else
            {
                /* Shift left without XOR */
                crc_temp = (crc_temp << 1);
            }
        }
    }

    /* Invert the result, shift right by 4 bits, and mask to 4 bits */
    return (~(crc_temp >> 4)) & 0x0F;
}

/**
 * @brief   Initialize parameters for BS register data and CRC4.
 * @param   None
 * @retval  None
 */
void Param_Init(void)
{
    uint16_t i = 0;

    /* Initialize BS register data and calculate CRC4 */
    for (i = 0; i < 128; i++)
    {
        /* Set BS register data with sequential values */
        bs_reg_data[i] = i;

        /* Calculate 4-bit CRC for each value */
        bs_reg_crc[i] = Calc_CRC4(&bs_reg_data[i], 1);
    }
}

/**
 * @brief   Handle BiSS communication for register operations.
 * @param   enc_comm_temp: Pointer to the encoder communication data structure.
 * @retval  None
 */
void ENC_Comm_Bs_Handle(volatile ENC_COMM_T* enc_comm_temp)
{
    /* Handle register communication */
    if (enc_comm_temp->bs_reg_sts == 0) /* Register communication not started */
    {
        if (enc_comm_temp->bs_cdm == 0) /* CDM equals 0 */
        {
            /* Increment CDM=0 count */
            enc_comm_temp->bs_cdm_zero_num++;
            /* Set CDS value for the next cycle */
            enc_comm_temp->bs_cds = 0;
        }
        else
        {
            /* Check if CDM=0 count >= 14 indicates Start bit */
            if (enc_comm_temp->bs_cdm_zero_num >= 14)
            {
                /* Start register communication */
                enc_comm_temp->bs_reg_sts = 1;
                /* Reset CDM=0 count */
                enc_comm_temp->bs_cdm_zero_num = 0;
            }
            else
            {
                /* Reset CDM=0 count */
                enc_comm_temp->bs_cdm_zero_num = 0;
            }

            /* Set CDS value for the next cycle: IDL[0] */
            enc_comm_temp->bs_cds = (BS_IDL & 0x01);
        }
    }
    else /* REG communication process: only register read/write mode, no command mode */
    {
        switch (enc_comm_temp->bs_reg_sts)
        {
            case 1: /* Previous bit is the start bit (S), check the current bit (CTS) */
                if (enc_comm_temp->bs_cdm == 1) /* Received CTS=1, indicating register read/write access */
                {
                    /* Enter address transmission process */
                    enc_comm_temp->bs_reg_sts = 2;
                    /* Reset ID */
                    enc_comm_temp->bs_id = 0;
                    /* Reset address */
                    enc_comm_temp->bs_adr = 0;
                    /* Reset address CRC */
                    enc_comm_temp->bs_adr_crc = 0;
                }
                else /* Received CTS=0, indicating command mode */
                {
                    /* Command mode is not supported currently */

                    /* End communication */
                    enc_comm_temp->bs_reg_sts = 0;
                }

                /* Set the CDS value for the next cycle: IDL[1] */
                enc_comm_temp->bs_cds = ((BS_IDL >> 1) & 0x01);
                break;
            case 2: /* Address transmission process: ID[2:0] + ADR[6:0] + CRC[3:0] = 14 bits */
                if (enc_comm_temp->bs_num < 3) /* Receiving ID, sending intermediate 3 bits of IDL */
                {
                    /* Save ID */
                    enc_comm_temp->bs_id |= enc_comm_temp->bs_cdm << (2 - enc_comm_temp->bs_num);
                    /* Set the CDS value for the next cycle: IDL[2:4] */
                    enc_comm_temp->bs_cds = ((BS_IDL >> (enc_comm_temp->bs_num + 2)) & 0x01);
                    /* Increment bit counter */
                    enc_comm_temp->bs_num++;
                }
                else if (enc_comm_temp->bs_num < 6) /* Receiving the first 3 bits of ADR, sending the remaining 3 bits of IDL */
                {
                    /* Save ADR[6:4] */
                    enc_comm_temp->bs_adr |= enc_comm_temp->bs_cdm << (9 - enc_comm_temp->bs_num);
                    /* Set the CDS value for the next cycle: IDL[5:7] */
                    enc_comm_temp->bs_cds = ((BS_IDL >> (enc_comm_temp->bs_num + 2)) & 0x01);
                    /* Increment bit counter */
                    enc_comm_temp->bs_num++;
                }
                else if (enc_comm_temp->bs_num < 10) /* Receiving the last 4 bits of ADR */
                {
                    /* Save ADR[3:0] */
                    enc_comm_temp->bs_adr |= enc_comm_temp->bs_cdm << (9 - enc_comm_temp->bs_num);
                    /* Set the CDS value for the next cycle: 0 */
                    enc_comm_temp->bs_cds = 0;
                    /* Increment bit counter */
                    enc_comm_temp->bs_num++;
                }
                else if (enc_comm_temp->bs_num < 14) /* Receiving CRC4 */
                {
                    /* Save CRC4[3:0] */
                    enc_comm_temp->bs_adr_crc |= enc_comm_temp->bs_cdm << (13 - enc_comm_temp->bs_num);
                    /* Set the CDS value for the next cycle: 0 */
                    enc_comm_temp->bs_cds = 0;
                    /* Increment bit counter */
                    enc_comm_temp->bs_num++;

                    if (enc_comm_temp->bs_num == 14) /* Transmission complete */
                    {
                        /* Reset bit counter */
                        enc_comm_temp->bs_num = 0;
                        /* Enter the process to check the read flag */
                        enc_comm_temp->bs_reg_sts = 3;
                    }
                }
                break;

            case 3: /* Read flag */
                if (enc_comm_temp->bs_cdm == 1) /* Read register */
                {
                    /* Set as read flag */
                    enc_comm_temp->bs_rw_bit = 0;
                }
                else /* Not reading register */
                {
                    /* Set as write flag */
                    enc_comm_temp->bs_rw_bit = 1;
                }

                /* Set the CDS value for the next cycle */
                enc_comm_temp->bs_cds = enc_comm_temp->bs_cdm;
                /* Enter the process to check the write flag */
                enc_comm_temp->bs_reg_sts = 4;
                break;

            case 4: /* Write flag */
                /* Set the CDS value for the next cycle */
                enc_comm_temp->bs_cds = enc_comm_temp->bs_cdm;
                /* Enter the process to check data transmission start */
                enc_comm_temp->bs_reg_sts = 5;

                if (enc_comm_temp->bs_cdm == 1) /* Write register */
                {
                    if (enc_comm_temp->bs_rw_bit == 0) /* RW = 11, error */
                    {
                        /* Set read/write command error */
                        enc_comm_temp->bs_rw_bit = 2;
                        /* End communication */
                        enc_comm_temp->bs_reg_sts = 0;
                    }
                }
                else /* Not writing register */
                {
                    if (enc_comm_temp->bs_rw_bit == 1) /* RW = 00, error */
                    {
                        /* Set read/write command error */
                        enc_comm_temp->bs_rw_bit = 2;
                        /* End communication */
                        enc_comm_temp->bs_reg_sts = 0;
                    }
                }
                break;
            case 5: /* Data transmission start flag */
                if (enc_comm_temp->bs_cdm == 1) /* Data transmission starts */
                {
                    /* Set the CDS value for the next cycle */
                    enc_comm_temp->bs_cds = enc_comm_temp->bs_cdm;

                    /* Enter the data transmission process */
                    enc_comm_temp->bs_reg_sts = 6;

                    if (enc_comm_temp->bs_rw_bit == 0) /* Read process */
                    {
                        /* Load data and CRC for the specified address */
                        enc_comm_temp->bs_data = bs_reg_data[enc_comm_temp->bs_adr];
                        enc_comm_temp->bs_data_crc = bs_reg_crc[enc_comm_temp->bs_adr];
                    }
                    else if (enc_comm_temp->bs_rw_bit == 1) /* Write process, clear data */
                    {
                        /* Clear data and CRC */
                        enc_comm_temp->bs_data = 0;
                        enc_comm_temp->bs_data_crc = 0;
                    }
                }
                else
                {
                    /* Set the CDS value for the next cycle */
                    enc_comm_temp->bs_cds = enc_comm_temp->bs_cdm;

                    /* End communication */
                    enc_comm_temp->bs_reg_sts = 0;
                }
                break;

            case 6: /* Data transmission process: DATA[7:0] + CRC[3:0] */
                /* Read process */
                if (enc_comm_temp->bs_rw_bit == 0)
                {
                    if (enc_comm_temp->bs_num < 8) /* Transmitting DATA[7:0] */
                    {
                        /* Set the CDS value for the next cycle */
                        enc_comm_temp->bs_cds = (enc_comm_temp->bs_data >> (7 - enc_comm_temp->bs_num)) & 0x01;
                        /* Increment bit counter */
                        enc_comm_temp->bs_num++;
                    }
                    else if (enc_comm_temp->bs_num < 12) /* Transmitting CRC[3:0] */
                    {
                        /* Set the CDS value for the next cycle */
                        enc_comm_temp->bs_cds = (enc_comm_temp->bs_data_crc >> (11 - enc_comm_temp->bs_num)) & 0x01;
                        /* Increment bit counter */
                        enc_comm_temp->bs_num++;

                        if (enc_comm_temp->bs_num == 12) /* Transmission complete */
                        {
                            /* Reset bit counter */
                            enc_comm_temp->bs_num = 0;
                            /* Enter the data communication stop flag check process */
                            enc_comm_temp->bs_reg_sts = 7;
                        }
                    }
                }
                /* Write process */
                else
                {
                    if (enc_comm_temp->bs_num < 8) /* Receiving DATA[7:0] */
                    {
                        /* Save DATA */
                        enc_comm_temp->bs_data |= enc_comm_temp->bs_cdm << (7 - enc_comm_temp->bs_num);
                        /* Set the CDS value for the next cycle */
                        enc_comm_temp->bs_cds = enc_comm_temp->bs_cdm;
                        /* Increment bit counter */
                        enc_comm_temp->bs_num++;
                    }
                    else if (enc_comm_temp->bs_num < 12) /* Receiving CRC[3:0] */
                    {
                        /* Save CRC4 */
                        enc_comm_temp->bs_data_crc |= enc_comm_temp->bs_cdm << (11 - enc_comm_temp->bs_num);
                        /* Set the CDS value for the next cycle */
                        enc_comm_temp->bs_cds = enc_comm_temp->bs_cdm;
                        /* Increment bit counter */
                        enc_comm_temp->bs_num++;

                        if (enc_comm_temp->bs_num == 12) /* Transmission complete */
                        {
                            /* Reset bit counter */
                            enc_comm_temp->bs_num = 0;
                            /* Enter the data communication stop flag check process */
                            enc_comm_temp->bs_reg_sts = 7;
                        }
                    }
                }
                break;
            case 7: /* Data transmission stop bit */
                if (enc_comm_temp->bs_cdm == 0) /* Stop bit detected */
                {
                    if (enc_comm_temp->bs_num == 0) /* One stop bit detected, two possibilities: continue or end communication */
                    {
                        /* Increment stop bit counter to determine next state */
                        enc_comm_temp->bs_num++;
                    }
                    else /* Two consecutive stop bits detected, end communication */
                    {
                        /* Reset stop bit counter */
                        enc_comm_temp->bs_num = 0;
                        /* End register communication */
                        enc_comm_temp->bs_reg_sts = 0;
                    }
                }
                else
                {
                    if (enc_comm_temp->bs_num == 1) /* Continuous data transmission */
                    {
                        /* Reset stop bit counter */
                        enc_comm_temp->bs_num = 0;
                        if (enc_comm_temp->bs_adr < 127) /* Move to the next address */
                        {
                            /* Increment address */
                            enc_comm_temp->bs_adr++;
                        }

                        if (enc_comm_temp->bs_rw_bit == 0) /* Read process, update data */
                        {
                            /* Load data for the next address */
                            enc_comm_temp->bs_data = bs_reg_data[enc_comm_temp->bs_adr];
                            /* Load CRC for the next address */
                            enc_comm_temp->bs_data_crc = bs_reg_crc[enc_comm_temp->bs_adr];
                        }

                        /* Enter data transmission process */
                        enc_comm_temp->bs_reg_sts = 6;
                    }
                    else /* Communication error */
                    {
                        /* End communication */
                        enc_comm_temp->bs_reg_sts = 0;
                    }
                }

                /* Set the CDS value for the next cycle */
                enc_comm_temp->bs_cds = enc_comm_temp->bs_cdm;
                break;

            default: /* Default case, no operation */
                break;
        }
    }

    /* Single-cycle data processing: update the send array data (CDS, single-turn, multi-turn, alarm, CRC). */
    /* It is recommended to update at the falling edge interrupt position. */
    /* Here, pre-update the data that can be updated in advance. */

    /* Set CDS */
    if (enc_comm_data.bs_cds == 0)
    {
        /* Clear CDS bit in the send data */
        enc_send_data[0] &= 0xfb;
    }
    else
    {
        /* Set CDS bit in the send data */
        enc_send_data[0] |= 0x04;
    }

    /* Reset BiSS configuration */
    BiSS_Config();

}

/*!
 * @brief       Delay
 *
 * @param       count:  delay count
 *
 * @retval      None
 */
void Delay(uint32_t count)
{
    volatile uint32_t delay = count;
    while (delay--);
}

#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
/*!
* @brief       Redirect C Library function printf to serial port.
*              After Redirection, you can use printf function.
*
* @param       ch:  The characters that need to be send.
*
* @param       *f:  pointer to a FILE that can recording all information
*              needed to control a stream
*
* @retval      The characters that need to be send.
*
* @note
*/
int fputc(int ch, FILE* f)
{
    /* send a byte of data to the serial port */
    DDL_USART_TransmitData8(DEBUG_USART, (uint8_t)ch);

    /* wait for the data to be send */
    while (DDL_USART_IsActiveFlag_TC(DEBUG_USART) == RESET);

    return (ch);
}
#elif defined(__ICCARM__)

/*!
* @brief       Redirect C Library function printf to serial port.
*              After Redirection, you can use printf function.
*
* @param       ch:  The characters that need to be send.
*
* @retval      The characters that need to be send.
*
* @note
*/
int __io_putchar(int ch)
{
    /* send a byte of data to the serial port */
    DDL_USART_TransmitData8(DEBUG_USART, (uint8_t)ch);

    /* wait for the data to be send */
    while (DDL_USART_IsActiveFlag_TC(DEBUG_USART) == RESET);

    return (ch);
}

/*!
* @brief       Redirect C Library function printf to serial port.
*              After Redirection, you can use printf function.
*
* @param       file:  Meaningless in this function.
*
* @param       *ptr:  Buffer pointer for data to be sent.
*
* @param       len:  Length of data to be sent.
*
* @retval      The characters that need to be send.
*
* @note
*/
int __write(int file, char* ptr, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        __io_putchar(*ptr++);
    }

    return len;
}
#elif defined (__clang__) && !defined (__ARMCC_VERSION)

int uart_putc(char ch, FILE* file)
{
    /* send a byte of data to the serial port */
    DDL_USART_TransmitData8(DEBUG_USART, (uint8_t)ch);

    /* wait for the data to be send */
    while (DDL_USART_IsActiveFlag_TC(DEBUG_USART) == RESET);

    return (ch);
}

static FILE __stdio = FDEV_SETUP_STREAM(uart_putc, NULL, NULL, _FDEV_SETUP_WRITE);
FILE* const stdin = &__stdio;

__strong_reference(stdin, stdout);
__strong_reference(stdin, stderr);

#else

#warning Not supported compiler type
#endif
