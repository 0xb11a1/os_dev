[org 0x7c00]

mov bp, 0x8000
mov sp, bp 

xor ax, ax
mov ds, ax
mov es, ax 

; boot_name:
; db 'A'
msg:
db "hiiiiii",0
mov si, msg 
call PRINT_STRING


mov bx, 0x9000
mov dh, 5 

; call read_from_disk



call switch_to_pm

jmp $ ; endless loop 

; inlude functions 
%include "includes/myfunction.asm"
%include "includes/gdt.asm"
%include "includes/switch_to_pm.asm"

[bits 32]
BEGIN_PM:
; NOTE: this works 
; mov eax, 0x00
mov edx, 0xb8001
mov [edx], byte 0x60



; jmp kernal_start

jmp $
; Data
[bits 16]
; padding --> for booting only 
times 510-($-$$) db 0
dw 0xaa55

kernal_start:
[bits 32]
