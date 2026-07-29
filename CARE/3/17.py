#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C
txt = "GeeksForGeeks"
pat = "For"

n = len(txt)
m = len(pat)
ans = -1

for i in range(n - m + 1):
    j = 0
    while j < m:
        if txt[i + j] != pat[j]:
            break
        j += 1
    if j == m:
        ans = i
        break

print(ans)
