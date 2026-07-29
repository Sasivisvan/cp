#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

arr = [1, 2, 3, 4, 5]
key = 3

lo = 0
hi = len(arr) - 1
ans = len(arr)

while lo <= hi:
    mid = (lo + hi) // 2
    if arr[mid] >= key:
        ans = mid
        hi = mid - 1
    else:
        lo = mid + 1

print(ans)
