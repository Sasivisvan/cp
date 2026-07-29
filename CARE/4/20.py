#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

arr = [1, 2, 3, 3, 4, 4, 8, 10]
key = 4

ans = key
for i in range(len(arr)):
    if arr[i] > key:
        ans = arr[i]
        break

print(ans)
