n = int(input())
    
for i in range(n+1):
    s=0
    for j in range(n+1):
        if (i == 0 or i==n) and (j==0 or j==n):
            s+= n*n -1 - 4
        elif (i == 1 or i==n-1) and (j==1 or j==n-1):
            s+= n*n -1 -6
        else:
            s+= n*n -1 -8
print(s)
    