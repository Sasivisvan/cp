#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

arr = [1, 1, 2, 3, 3, 4, 4]

lo = 0
hi = len(arr) - 1

while lo < hi:
    mid = (lo + hi) // 2
    if mid % 2 == 1:
        mid -= 1
    if arr[mid] == arr[mid+1]:
        lo = mid + 2
    else:
        hi = mid

print(arr[lo])
