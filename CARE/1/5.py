#Roll No: CH.SC.U4AIE24084

arr  = [1, 2,2,2, 4,4, 5]
out = []

included = set()

i=0
while(i<len(arr)):
    if arr[i] not in included:
        out.append(arr[i])
        included.add(arr[i])
    i+=1

print(out)