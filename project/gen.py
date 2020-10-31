str="mov edx, 0xb8"  
str2="mov [edx], byte '?'"

for i in range(0,20,2):
    curr = str+hex(i)[2:].zfill(3)
    print(curr)
    print(str2)

