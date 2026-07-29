#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

a = "telescope"
b = "let"

banned = set(b)

ans = []
for i in a:
    if i not in banned:
        ans.append(i)

print("".join(ans))
