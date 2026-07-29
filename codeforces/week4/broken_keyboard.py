n, k = tuple(map(int, input().split()))

arr = input()

ans = 0

keys = set(input())
c=0
for i in arr :
    # print(i,c)
    if i in keys:
        c+=1
    else :
        ans += (c*(c+1))/2
        c=0
ans += (c*(c+1))/2
print(int(ans))
#1272C
