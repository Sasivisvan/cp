#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

arr = [10,5,6,3,2,20,100,80]

arr = sorted(arr)

for i in range(0, len(arr)-1, 2):
    arr[i], arr[i+1] = arr[i+1], arr[i]

print(arr)
