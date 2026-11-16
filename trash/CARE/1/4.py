#Roll No: CH.SC.U4AIE24084

arr = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110]

i,j = 0,0


#have a nlog(n) sorting algo not an n^2
while(i<len(arr)):
    j=i+1
    while(j<len(arr)):

        if arr[i]<arr[j]:
            arr[i],arr[j] = arr[j],arr[i]
        
        j+=1
    i+=1

i=1
j = len(arr)-1

while(i<len(arr)):

    # arr[i],arr[j] = arr[j],arr[i]
    temp = arr[j]
    del arr[j]
    arr.insert(i, temp)
    i+=2
print(arr)
