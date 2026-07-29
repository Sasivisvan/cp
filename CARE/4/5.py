#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

arr = [-1, 2, 2, 4]
t = 4
diff = 100000
ans = 0

for i in range(len(arr)):
    for j in range(i+1, len(arr)):
        for k in range(j+1, len(arr)):
            if abs(abs(arr[i] + arr[j] + arr[k]) - t) <= diff  and (arr[i] + arr[j] + arr[k])>ans:
                diff = abs((arr[i] + arr[j] + arr[k]) - t)
                ans = (arr[i] + arr[j] + arr[k])
print(ans)

