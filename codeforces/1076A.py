t = int(input(""))
for _ in range(t):
    n,s,x = tuple(map(int,input().split(" ")))
    arr = list(map(int,input().split(" ")))
    su=sum(arr)
    if(su>s):
        print("NO")
    else:
        if((s-su)%x==0):
            print("YES")
        else:
            print("NO")