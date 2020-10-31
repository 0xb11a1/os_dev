[org 0x7c00]

mov bp, 0x8000
mov sp, bp 

xor ax, ax
mov ds, ax
mov es, ax 

mov cx, dx
call PRINT_HEX

call read_from_disk

mov si,test_load_text
call PRINT_STRING


jmp $ ; endless loop 

; inlude functions 
%include "myfunction.asm"

; Data
test_data:
db 'hello There',0


read_from_disk:
  mov ah, 0x02
  mov al, 1
  mov ch, 0 
  mov cl, 2
  mov dh, 0
  mov dl,0x80  
  mov bx, 0
  mov es, bx 
  mov bx, 0x7c00 + 512 


  int 0x13

  jc error_disk


  ret

error_disk:
  mov si, msg_error_loading_drive
  call PRINT_STRING
  jmp $
  ;ret

msg_error_loading_drive:
  db 'Error loading the drive',0

; padding --> for booting only 
times 510-($-$$) db 0

dw 0xaa55

test_load_text:
  db "i was loaded ",0

times (512*2)-($-$$) db 0








