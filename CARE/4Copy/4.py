#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

citations = [6, 0, 3, 5, 3]

citations = sorted(citations)[::-1]

ans = 0

for i in range(len(citations)):
    if i+1<=citations[i]:
        ans = i+1

print(ans)

