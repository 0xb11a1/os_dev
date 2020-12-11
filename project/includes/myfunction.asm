read_from_disk:
push ax 
push cx 
push dx 
push bx 
push es 

; setting the variables 
  mov ah, 0x02 ; read sector from drive 
  mov al, 9 ; nums of sector to read 
  mov ch, 0 ; select first cylinder/tracks 
  mov cl, 2 ; select the 2nd sector 
  mov dh, 0 ; select first read/write header 
  ; mov dl,0x80 ; drive name/code 
  mov bx, 0 
  mov es, bx ; no need for higher value rightnow  
  mov bx, 0x7c00 + 512 ; pointer to the first byte to load


  int 0x13
	; int 0x13 set sum regesters after finishing 
	; the carry flag set when there is an error 
  ; jc error_disk
  jc print_error_disk
  _cont:
  pop es 
  pop bx
  pop dx 
  pop cx 
  pop ax 
  ret

  
  msg_disk_error:
    db "error loading drive...",0
  print_error_disk:
    mov si, msg_disk_error

    call PRINT_STRING
    jmp _cont




print:
  push ax
  mov al,'X'
  mov ah,0x0e
  int 0x10
  pop ax
  ret


PRINT_STRING:
  ; print the value of `si`
  pusha
  push ax
  push si
  _loop:
    mov al, [si]
    ;lodsb
    cmp al, 0
    je _end
    mov ah, 0x0e
    int 0x10
    add si, 1
    ;inc si
    jmp _loop

  _end
  pop si
  pop ax 
  popa
  ret


PRINT_HEX:
  ; this for saving the original value from distruction
  ; it is nesseray when using with other functions 
  ; calling convention 
  push si
  push bx
  ; print the value of `cx` as a hex output 
  ; put the value in the si of the templet hex
	mov si, HEX_TEMPLET
	; modifing the 
  ; using cx as the passed parameter
  ; comment based in the value 0x1234
  ; moving each digit at a time 
  mov bx, cx ; 0x1234
  shr bx, 12 ; 0x0001 -> 12 becuse each digit is 4 bit wide 
  ; only bx regester can be used as and index inside a [] so i had to use it here
	mov bx, [HEXPATT+bx]
  mov [HEX_TEMPLET+2], byte bl 
  
  mov bx, cx ; 0x1234
  shr bx, 8 ; 0x0012
  and bx, 0x000f ; 0x0002
  mov bx, [HEXPATT+bx]
  mov [HEX_TEMPLET+3], byte bl 
   
  mov bx, cx ; 0x1234
  shr bx, 4 ; 0x0123
  and bx, 0x000f ; 0x0003
  mov bx, [HEXPATT+bx]
  mov [HEX_TEMPLET+4], byte bl 
  
  mov bx, cx ; 0x1234
  and bx, 0x000f ; 0x0004
  mov bx, [HEXPATT+bx]
  mov [HEX_TEMPLET+5], byte bl 

  call PRINT_STRING 
  pop bx 
  pop si 
  ret 

; data 
HEX_TEMPLET:
; templet for to modify it
db '0x????  ',0

HEXPATT:
db '0123456789ABCDEF'
