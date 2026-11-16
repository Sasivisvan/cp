#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084


nums = [10,9,2,5,3,7,101,18]
dp = []

for i in range(len(nums)):
    dp.append(1)
    for j in range (i):
        if nums[j] < nums[i]:
            dp[-1] = max(dp[-1], dp[j]+1,1)

print(dp)

print(max(dp))

