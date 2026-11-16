#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084
from pprint import pprint

arr = [3, 34, 4, 12, 5, 2]
s = 9

dp = [[False] * (s+1) for _ in range(len(arr)+1)]

dp[0][0] = True

for i in range(1,len(arr)+1):
    dp[i][0] = True
    for j in range(1, s+1):
        dp[i][j] = dp[i-1][j]
        if  j - arr[i-1] >=0 :
            if dp[i-1][j - arr[i-1]]:
                dp[i][j] = True

pprint(dp)
print(dp[-1][-1])
