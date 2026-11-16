t = int(input(""))
inf = 10000000000000

while(t>0):
    
    n = int(input())
    arr = list(map(int,input().split(" ")))
    
    
    dp = [inf for i in range(n+1)]
    # core algo
    for i in arr :
        dp[i]=1
    
    s = set(arr)
    
    for i in range(n+1):
        if dp[i]==inf:
            continue
        
        j = 2
        while(i*j <= n):
            if j in s:
                dp[i*j] = min(dp[i*j], dp[i]+1)
            j+=1
    #core algo ends
    for i in range(n):
        if dp[i+1]!=inf:
            print(dp[i+1],end=" ")
        else:
            print(-1, end = " ")
    t-=1
