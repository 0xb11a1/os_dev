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

call read_from_disk



call switch_to_pm

jmp $ ; endless loop 

; inlude functions 
%include "includes/myfunction.asm"
%include "includes/gdt.asm"
%include "includes/switch_to_pm.asm"

[bits 32]
BEGIN_PM:
; NOTE: this works 
mov edx, 0xb8000
mov [edx], byte 'A'

jmp kernal_start

jmp $
; Data
[bits 16]
; padding --> for booting only 
times 510-($-$$) db 0
dw 0xaa55

kernal_start:
[bits 32]
; NOTE: this works 
mov edx, 0xb8002
mov [edx], byte 'A'
; NOTE : this does not works - and it stops the above code from working ! 
msg_test:
db 'HELLO',0


mov esi, msg_test
; call print_new
call print_string_pm


jmp $



call_string_pm:
    mov ebx, 0xb8000  
    _call_string_pm_loop:
        mov eax, byte  [esi]
        mov [ebx], byte eax 

        add esi, 1
        add ebx, 2 
        cmp eax, 0x00
        jne _call_string_pm_loop
    ret 


; VID equ 0xb8000
; WB equ 0x0f 

; print_string_pm:
;     pusha 
;     mov edx, VID

; print_string_pm_loop:
;     mov al, [esi]
;     mov ah, WB
    
;     cmp al,0
;     je print_string_pm_done

;     mov [edx], ax 

;     add esi, 1 
;     add edx, 2 

;     jmp print_string_pm_loop

; print_string_pm_done:
;     popa 
;     ret 



; jmp $

; print_new:
;     pusha
;     xor eax, eax 
;     ; mov ebx, eax 
;     mov edx, 0xb8000
;     ; si -- > pointer to the string
;     _loop_print_new:
;         mov al, [esi]
;         mov ah, 0x0f
;         ; mov 
;         mov [edx], ax 

        
;         add edx, 0x2
;         add esi, 0x1 

;         cmp al, 0x0
;         jne _loop_print_new

;     ; ret
;     popa 



jmp $
[bits 16]
times (512*2)-($-$$) db 0 

