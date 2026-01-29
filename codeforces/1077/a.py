t = int(input(""))
for _ in range(t):
    n = int(input())
    ans = []
    mid = n//2
    
    m=mid
    a = [x+1 for x in range(n)]
    # print(a)
    for i in range(1,n//2+1):
        
        print(a[mid],end=" ")
        print(a[m-i],end=" ")
        
            
        mid+=1
    if n%2==1:
        print(n,end=" ")
    print()
        
         