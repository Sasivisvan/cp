t = int(input(""))
for _ in range(t):
    # n,s,x = tuple(map(int,input().split(" ")))
    n = int(input())
    arr = list(tuple(map(int,input().split(" "))))
    
    i=0
    while(i<n and i+arr[i]==n):
        i+=1
    first = arr[:i]
    arr = arr[i:] 
    # print("arr:",arr)
    n = n - i
    val =i
    # print("i:",i)
    if arr:
        i = arr.index(max(arr))+1
    else:
        i = n
    
    
    sec1 = arr[:i]
    ans =  first + sec1[::-1] + arr[i:]
    # print("i: ", i)
    # print("Ans: ",ans)
    
    for i in ans:
        print(i, end=" ")
    print()