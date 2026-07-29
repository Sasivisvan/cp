#Roll No: CH.SC.U4AIE24084

arr = [0, 2, 2, 2, 0, 6, 6, 0, 0, 8] 

i=0
while(i<len(arr)-1):
    if arr[i] == arr[i+1] and arr[i]!=0:
        arr[i] = arr[i]*2
        arr[i+1] = 0
    i+=1

i=0
j = 0

while(i<len(arr) and j<len(arr)):
    if arr[j]!= 0:
        arr[i] = arr[j]
        # arr[j] = 0
        i+=1
    j+=1

while(i<len(arr)):
    arr[i]=0
    i+=1

print(arr)