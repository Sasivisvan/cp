#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

arr = [0,3,4,7,10,9]
c = 4

arr = sorted(arr)

lo = 0
hi = arr[-1] - arr[0]
ans = 0

while lo <= hi:
    mid = (lo + hi) // 2
    count = 1
    last = arr[0]
    for i in range(1, len(arr)):
        if arr[i] - last >= mid:
            count += 1
            last = arr[i]
    if count >= c:
        ans = mid
        lo = mid + 1
    else:
        hi = mid - 1

print(ans)
