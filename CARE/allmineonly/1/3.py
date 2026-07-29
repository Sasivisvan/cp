
n = int(input())

arr = list(map(int, input().split()))

i = n-2
highest = arr[-1]
ans = -1

larr = []
rarr = []
while(i>=0):
    if arr[i] > highest:
        highest = arr[i]
        ans = i

    i-=1

print(ans)

