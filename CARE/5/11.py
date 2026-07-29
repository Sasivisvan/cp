#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084


arr = [3, 10, 2, 1, 20]
dp = []

for i in range(len(arr)):
    dp.append(1)
    for j in range(i):
        if arr[j] < arr[i]:
            dp[-1] = max(dp[-1], dp[j]+1)

print(dp)

print(max(dp))
