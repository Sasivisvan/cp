# i = int(input())
i=20

n = int(i**(1/2))

for j in range(2, n+1):
    
    if(i%j==0):
        print(j)
        print(int(i/j))
    