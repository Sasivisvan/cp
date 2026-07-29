#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

arr = [12, 1, 2, 3, 0, 11, 4]

countSmaller = []

for i in range(len(arr)):
    count = 0
    for j in range(i+1, len(arr)):
        if arr[j] < arr[i]:
            count += 1
    countSmaller.append(count)

print(countSmaller)
