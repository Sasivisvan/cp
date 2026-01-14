t = int(input(""))
for _ in range(t):
    s,k,m = tuple(map(int,input().split(" ")))
    
    odd_even = m//k%2
    over = m%k
    # print("over: ",over)
    # print("odd_even: ",odd_even)
    if(odd_even==1):
        if(s-k)>=0:
            left = s - (s-k)
        else:
            left = min(s,k)
        # print("Left1: ",left)
        print(max(0,left-over))
    else:
        # print("Left2: ",left)
        print(max(0, s-over))
    
    