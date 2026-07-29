arr = list(map(int, input().split()))


n = len(arr)
ans = []
i=0
while(i<n-1):
    if arr[i]!=arr[i+1] :
        ans.append(arr[i])
    i+=1

ans.append(arr[-1])

print(ans)
