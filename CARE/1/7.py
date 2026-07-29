#Roll No: CH.SC.U4AIE24084

arr = [2, 2, 3, 3, 7, 5] 

taken = set()
ans = []
for i in arr:
    if i not in taken:
        ans.append(i)
        taken.add(i)

print(ans)