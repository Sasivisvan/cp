#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

arr = [5, 3, 4, 11, 2]


dp = [0] * (len(arr)+1)


for i in range(1, len(arr)+1):

    dp[i] = max(dp[i-2]+arr[i-1], dp[i-1])

print(dp)

print(dp[-1])
