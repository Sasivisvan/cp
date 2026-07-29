#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

n, m= tuple(map(int, input().split()))
nums= list(map(int, input().split()))
k,t= tuple(map(int, input().split()))

ans = []
for i in nums:
    if i+t > m :
        t1 =  t - (m-i)
        ans.append(m-k + (t1%k))
    else:
        ans.append(i+t)

print(ans)  