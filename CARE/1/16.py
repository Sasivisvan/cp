#Roll No: CH.SC.U4AIE24084

coins =  [1, 2, 3]

s = 4

s+=1
ans = [0 for i in range(s)]
ans[0] = 1

c = 0
while(c<len(coins)):
    i = coins[c]
    while(i<len(ans)):
        ans[i]+=ans[i-coins[c]]
        i+=1
    c+=1

print(ans[-1])
