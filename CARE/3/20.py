#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C
s1 = "AAB"
s2 = "AAC"
s3 = "AAAABC"

a = len(s1)
b = len(s2)

if a + b != len(s3):
    print(False)
else:
    dp = [[False]*(b+1) for _ in range(a+1)]
    dp[0][0] = True

    for i in range(1, a+1):
        dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1]

    for j in range(1, b+1):
        dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1]

    for i in range(1, a+1):
        for j in range(1, b+1):
            top = dp[i-1][j] and s1[i-1] == s3[i+j-1]
            left = dp[i][j-1] and s2[j-1] == s3[i+j-1]
            dp[i][j] = top or left

    print(dp[a][b])

