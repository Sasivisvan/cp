length = int(input())
arr = list(map(int, input().split()))

if length <= 1:
    print(0)
else:
    prefix = [0] * (length + 1)
    for i in range(length):
        prefix[i+1] = prefix[i] + arr[i]
        
    dp = [[0] * length for _ in range(length)]
    
    for l in range(2, length + 1):
        for i in range(length - l + 1):
            j = i + l - 1
            dp[i][j] = float('inf')
            for k in range(i, j):
                cost = dp[i][k] + dp[k+1][j] + prefix[j+1] - prefix[i]
                if cost < dp[i][j]:
                    dp[i][j] = cost
                    
    print(dp[0][length-1])