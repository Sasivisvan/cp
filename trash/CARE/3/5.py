#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

n = 2
k = 0

mod = 1000000007
v = 5
c = 21

dp = [[0]*(k+2) for _ in range(n+1)]

for j in range(k+1):
    dp[1][j] = v
dp[1][0] = c

for i in range(2, n+1):
    dp[i][0] = dp[i-1][0] * c % mod
    for j in range(1, k+1):
        dp[i][j] = dp[i-1][j-1] * v % mod

ans = 0
for j in range(k+1):
    ans = (ans + dp[n][j]) % mod

print(ans)
