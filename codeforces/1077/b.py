t = int(input(""))
for _ in range(t):
    n = int(input())
    arr = list(map(int,list(input())))

    #pre process
    if n<=2:
        print(1)
    else:
        for i in range(n-1):
            if(arr[i+1]==0 and arr[i]==1):
                arr[i+1] = -1
                
        print(arr)
        for i in range(n):
            if(i-1 >=0 and i+1<=n ):
                print(i)
                if (arr[i]==0 and arr[i-1]==0 and arr[i+1]==0):
                    arr[i]=1
                else :
                    if (arr[i]==0 and arr[i+1]==0 and arr[i-1]!=1):
                        arr[i] = 
        print(arr)
        print(arr.count(1))
    