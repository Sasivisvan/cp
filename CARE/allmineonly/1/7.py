arr = list(map(int, input().split()))

found = set()

ans = []

for i in arr:
    if i not in found:
        ans.append(i)
        found.add(i)
print(ans)
