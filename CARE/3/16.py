#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C
s = "abcdecba"
n = 8
k = 1

r = s[::-1]

dp = [[0]*(n+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        if s[i-1] == r[j-1]:
            dp[i][j] = 1 + dp[i-1][j-1]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

lcs = dp[n][n]
removed = n - lcs

print(1 if removed <= k else 0)
