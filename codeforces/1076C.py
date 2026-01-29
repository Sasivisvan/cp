t = int(input(""))

for _ in range(t):
    n,q = tuple(map(int,input().split(" ")))
    a = list(tuple(map(int,input().split(" "))))
    b = list(tuple(map(int,input().split(" "))))
    queries = []
    for i in range(q):
        t1,t2 = tuple(map(int,input().split(" ")))
        queries.append([t1,t2])
    
    ans = [max(a[-1],b[-1])]
    for i in range(n-1, -1, -1):
        ans.append(max(a[i],b[i],ans[n - i- 1]))
    ans = ans[::-1]
    
    sumarr = [ans[0]]
    for i in ans[0:]:
        sumarr.append(sumarr[-1]+i)
    # print(sumarr)
    
    for i,j in queries:
        print(sumarr[j]- sumarr[i-1],end = " ")
    print()
    
    
    
    