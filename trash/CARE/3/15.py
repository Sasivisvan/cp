#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C
s = "123"

n = len(s)
dp = [0] * (n + 1)
dp[0] = 1
dp[1] = 1 if s[0] != '0' else 0

for i in range(2, n + 1):
    one = int(s[i-1])
    two = int(s[i-2:i])

    if one >= 1:
        dp[i] += dp[i-1]
    if two >= 10 and two <= 26:
        dp[i] += dp[i-2]

print(dp[n])
