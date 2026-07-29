#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

s = input()
hash = 0
star = 0
for i in s:
    if i=='#':
        hash+=1
    if i=='*':
        star+=1


print(star-hash)
