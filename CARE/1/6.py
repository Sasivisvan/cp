#Roll No: CH.SC.U4AIE24084

a = [1, 2, 3, 4, 5, 10]
b = [2, 3, 1, 0, 5]

b = set(b)
ans = []
for i in a:
    if i not in b:
        ans.append(i)
print(ans)