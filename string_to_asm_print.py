# add space at the start - for the loop below to start from one - because if zero it start drawing before the memory location for video

msg=""" _________
< Cool_OS >
 ---------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\ 
                ||----w |
                ||     ||

"""

# mov1="mov edx, "
# mov2="mov [edx], byte ''"

# charater screen size :
# width = 80
# hight = 25 
# 
j=0
base_addr = 0xb8000

for line  in msg.splitlines():
    for i in range(len(line)):
        final_addr = base_addr + i*2  
        print("mov edx, "+str(hex(final_addr)))
        print("mov [edx], byte '{}'".format(line[i]))
    base_addr += 160

# for i in range(1,len(msg)):
#     if (msg[i] == '\n'):
#         j+=1 
#         base_addr += 160
#         # print()
#         continue
#     # re-think this function 
#     final_addr = base_addr + ()
    
#     # x = i % 80 
#     # final_adrr = 0xb8000 + (x*2) + (j*132) -2
#     print("mov edx, "+str(hex(final_adrr)))
#     print("mov [edx], byte '{}'".format(msg[i]))
#     # print(msg[i], end="")
#     # print(hex(final_adrr), end= " ")

