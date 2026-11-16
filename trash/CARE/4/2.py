#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

arr = [12, 10, 15, 22, 21, 20, 1, 8, 9]

arr = sorted(arr)
# print(arr)

total = 0


for i in range(len(arr)):

    if i == 0 :
        total += abs(arr[i] - arr[i+1])
    elif i== len(arr)-1:
        total += abs(arr[i] - arr[i-1])
    else:
        total += min(abs(arr[i] - arr[i+1]), abs(arr[i] - arr[i-1]))


print(total)



"""
def bs(arr, val, i, j):

    global num

    mid = (i+j) //2

    if i>j:
        num = min(num, abs(val - arr[i]), abs(val - arr[j]), abs(val - arr[mid]))
        return mid

    if arr[mid] == val :
        num = min(num, 0)

        return mid

    if arr[mid] > val:
        return bs(arr, val, i, mid-1)

    if arr[mid] <val :
        return bs(arr, val, mid+1, j)

"""
