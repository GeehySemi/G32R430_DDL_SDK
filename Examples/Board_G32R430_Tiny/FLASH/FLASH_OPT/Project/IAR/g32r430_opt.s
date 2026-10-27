;----------------------------------------------------------------------------
; G32R430 Option Bytes Configuration (converted style)
;----------------------------------------------------------------------------
; In little-endian, the first byte (lowest address) is the LSB of the 32-bit word.
; Here, for bytes [AA, 55, 03, FC], in memory the order is:
; address +0 => 0xAA
; address +1 => 0x55
; address +2 => 0x03
; address +3 => 0xFC
; Thus the 32-bit representation is 0xFC0355AA.
;----------------------------------------------------------------------------

    SECTION .rodata:CONST:ROOT,0x1FFF0000
    
; 0x1FFF0000 ~ 0x1FFF0003
; [RDP (0xAA), nRDP (0x55), USER (0x03), nUSER (0xFC)]
    DCD 0xFC0355AA  ; Byte0=0xAA, Byte1=0x55, Byte2=0x03, Byte3=0xFC

; 0x1FFF0004 ~ 0x1FFF0007
; [WLOCK (0xFF), nWLOCK (0x00), Reserved(0x00), Reserved(0xFF)]
    DCD 0xFF0000FF  ; Byte0=0xFF, Byte1=0x00, Byte2=0x00, Byte3=0xFF

; 0x1FFF0008 ~ 0x1FFF000B
; [BOOTADDR_L (0x80), nBOOTADDR_L (0x7F), BOOTADDR_H (0x00), nBOOTADDR_H (0xFF)]
    DCD 0xFF007F80  ; Byte0=0x80, Byte1=0x7F, Byte2=0x00, Byte3=0xFF

    END
