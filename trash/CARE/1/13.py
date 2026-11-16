#Roll No: CH.SC.U4AIE24084

arr =  [2, 3, 2, 3, 5]
# arr =   [3, 3, 3, 3]

ans = [0 for i in range(len(arr))]

for i in arr:

    ans[i-1]+=1

print(ans)