#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084


m = 3
n = 3

dp = [[0] * n for _ in range(m)]

for i in range(m):
    dp[i][0] = 1
for j in range(n):
    dp[0][j] = 1

for i in range(1, m):
    for j in range(1, n):
        dp[i][j] = dp[i-1][j] + dp[i][j-1]

print(dp)

print(dp[-1][-1])
