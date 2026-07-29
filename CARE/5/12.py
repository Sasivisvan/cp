#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084


a = [3, 4, 9, 1]
b = [5, 3, 8, 9, 10, 2, 1]

dp = [0] * len(b)

for i in range(len(a)):
    cur = 0
    for j in range(len(b)):
        if a[i] == b[j]:
            dp[j] = max(dp[j], cur + 1)
        if b[j] < a[i]:
            cur = max(cur, dp[j])

print(dp)

print(max(dp))
