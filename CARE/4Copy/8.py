#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C


arr = [1, 10, 3, 11, 6, 15]

arr = sorted(arr)
ans = 1

for i in range(len(arr)):
    if arr[i]<=ans:
        ans+=arr[i]
    else:
        break

print(ans)
