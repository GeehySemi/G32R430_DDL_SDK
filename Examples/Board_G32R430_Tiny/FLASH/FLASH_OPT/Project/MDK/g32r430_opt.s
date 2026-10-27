// 
// G32R430 Option Bytes Configuration
// 
// Address range: 0x1FFF0000 ~ 0x1FFF000B
// Each field is 1 byte (8 bits).
// 
// Below example sets:
//   - RDP to Level0: 0xAA (nRDP: 0x55)
//   - USER to 0x03 => SW IWDG = 1, SW WWDG = 1, WLOCK enable = 0
//        (nUSER = 0xFC)
//   - WLOCK = 0xFF => disable all write protections
//        (nWLOCK = 0x00)
//   - BOOTADDR = 0x4000 (boot from 0x08000000, for demonstration)
//        (nBOOTADDR = 0xBFFF)
//   - You can adjust these settings based on your application needs.
// 

    .section .ARM.__at_0x1FFF0000
    /* 0x0000: RDP, nRDP */
    .byte 0xAA          /* RDP: 0xAA => Level0 (no protection) */
    .byte 0x55          /* nRDP: 0x55 => complement of RDP */

    /* 0x0002: USER, nUSER */
    .byte 0x03          /* USER: [2]=0 => WLOCK Disable,
                                 [1]=1 => SW WWDG ,
                                 [0]=1 => SW IWDG */
    .byte 0xFC          /* nUSER: complement of 0x07 */

    /* 0x0004: WLOCK, nWLOCK */
    .byte 0xFF          /* WLOCK: 0xFF => all sectors unprotected (bit=1 => write protection OFF) */
    .byte 0x00          /* nWLOCK: complement of 0xFF */

    /* 0x0006: Reserved */
    .byte 0x00
    .byte 0xFF

    /* 0x0008: BOOTADDR[7:0], nBOOTADDR[7:0] */
    .byte 0x80          /* BOOTADDR[7:0] */
    .byte 0x7F          /* nBOOTADDR[7:0] */

    /* 0x000A: BOOTADDR[15:8], nBOOTADDR[15:8] */
    .byte 0x00          /* BOOTADDR[15:8] */
    .byte 0xFF          /* nBOOTADDR[15:8] */

/* End of file */