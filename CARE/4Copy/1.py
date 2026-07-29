#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

# a = 10
# arr = [3,54,-76,45,98,99,-9,6,3,-1,3,2,5,7,5,776,5,65,23]

arr = [-2, 0, 5, -1, 2]
a = 4
arr = sorted(arr)

i=0

while(a>0):
    if arr[i]<0:
        arr[i] = -arr[i]
        i+=1
    elif arr[i]>=0:
        break
    a -= 1

if a%2==1:
    arr[arr.index(min(arr))] = -arr[arr.index(min(arr))]

print(sum(arr))



