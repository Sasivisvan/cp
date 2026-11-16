def knapsack_01(w, v, W):
    n = len(w)
    dp = [[0]*(W+1) for _ in range(n+1)]

    for i in range(1, n+1):
        for j in range(W+1):
            if w[i-1] <= j:
                dp[i][j] = max(dp[i-1][j],
                               v[i-1] + dp[i-1][j - w[i-1]])
            else:
                dp[i][j] = dp[i-1][j]

    return dp[n][W]


w = [2, 4, 5, 9]
v = [3, 6, 8, 13]
W = 10

print(knapsack_01(w, v, W))
