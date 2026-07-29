#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084


arr = [1, 5, 11, 5]

s = sum(arr)

if s % 2 != 0:
    print(False)
else:
    t = s // 2
    dp = [False] * (t+1)
    dp[0] = True

    for x in arr:
        for j in range(t, x-1, -1):
            if dp[j-x]:
                dp[j] = True

    print(dp)

    print(dp[-1])
