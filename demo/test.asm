mov ah, 0x0e ; setting the value to select the "teletype output" function 

mov al, 'h' ;  puting the char
int 0x10 ;  calling the interupt after setting the value - it is like a switch stament and 0x0e is a code for "teletype output"; BIOS scrolling teletype function 

mov al, 'e'
int 0x10
mov al, 'l'
int 0x10
mov al, 'l'
int 0x10
mov al, 'o'
int 0x10

jmp $ ; endless jump - jump to the current offcet (which is the same jmp instruction) - to stop the CPU zooming of executing arbitrary bytes in memory as code. 
; pad out the bootsector to 512 bytes with last 2 bytes as magic 'bootable' number.
times 510-($-$$) db 0 

dw 0xaa55
