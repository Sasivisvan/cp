#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084


arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]

dp = [float('inf')] * len(arr)
dp[0] = 0

for i in range(1, len(arr)):
    for j in range(i):
        if j + arr[j] >= i and dp[j] != float('inf'):
            dp[i] = min(dp[i], dp[j] + 1)

print(dp)

if dp[-1] == float('inf'):
    print(-1)
else:
    print(dp[-1])
