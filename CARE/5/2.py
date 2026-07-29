#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084


coins = [ 2,3,5,7]

m = 14

dp = [float('inf')] * (m+1)

dp[0] = 0

for i in range(1,m+1):
    for j in coins:

        if i-j >=0 :
            dp[i] = min(dp[i-j]+1, dp[i])

print(dp)

print(dp[-1])
