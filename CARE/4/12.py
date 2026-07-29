#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

arr = [1,2,3,4,5,6,7,8,9]
x = 5

arr = sorted(arr)

diffs = []
for i in range(len(arr)):
    diffs.append((abs(arr[i] - x), arr[i]))

diffs = sorted(diffs)

ans = sorted([diffs[0][1], diffs[1][1], diffs[2][1]])
print(ans)
