#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084


price = [0, 3, 5, 8, 9, 10, 17, 17, 20]

dp = [0] * (len(price))

for i in range(len(price)):

    for j in range(1, i+1):

        dp[i] = max(dp[i], dp[i-j] + price[j])

print(dp)

print(dp[-1])
