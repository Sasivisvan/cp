#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

n = int(input())

nums= list(map(int, input().split()))

count = int(input())

ans = []

for i in nums : 
    if i>0 and i%2==0:
        ans.append(i)
    
    if len(ans) == count:
        break

print(ans)
