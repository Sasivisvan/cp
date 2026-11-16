t = int(input(""))

for _ in range(t):
    n = int(input())
    a = list(tuple(map(int,input().split(" "))))
    b = list(tuple(map(int,input().split(" "))))
    
    a = sorted(a)
    
    # print(a)
    
    ans = 0
    t=0
    lvl=1
    for i in b:
        t+=i
        if(n-t >=0 and n-t < n):
            if(a[n-t]*lvl > ans):
                ans = a[n-t]*lvl
        lvl+=1
    
    print(ans)
        