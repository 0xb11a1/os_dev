msg="""  __   __  ___ 
|  | |  ||   |
|  |_|  ||   |
|       ||   |
|       ||   |
|   _   ||   |
|__| |__||___|
"""

mov1="mov edx, "
mov2="mov [edx], byte ''"

# charater screen size :
# width = 80
# hight = 25 
# 
j=0
for i in range(1,len(msg)):
    if (msg[i] == '\n'):
        j+=1 
        # print()
        continue
    x = i % 80 
    final_adrr = 0xb8000 + (x*2) + (j*130) -2
    print("mov edx, "+str(hex(final_adrr)))
    print("mov [edx], byte '{}'".format(msg[i]))
    # print(msg[i], end="")
    # print(hex(final_adrr), end= " ")

