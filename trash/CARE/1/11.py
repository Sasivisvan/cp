#Roll No: CH.SC.U4AIE24084
arr =  [0, 1, 2, 3, 4, 5, 6, 7]

arreven = []
arrodd = []

for i in range(0,len(arr),2):
    arreven.append(arr[i])

for i in range(1, len(arr),2):
    arrodd.append(arr[i])

print(sorted(arreven) + sorted(arrodd)[::-1])