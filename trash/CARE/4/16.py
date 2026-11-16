#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

arr = [4, 5, 6, 7, 0, 1, 2]
target = 4

lo = 0
hi = len(arr) - 1
ans = -1

while lo <= hi:
    mid = (lo + hi) // 2
    if arr[mid] == target:
        ans = mid
        break
    if arr[lo] <= arr[mid]:
        if arr[lo] <= target < arr[mid]:
            hi = mid - 1
        else:
            lo = mid + 1
    else:
        if arr[mid] < target <= arr[hi]:
            lo = mid + 1
        else:
            hi = mid - 1

print(ans)
