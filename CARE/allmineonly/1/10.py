
arr = list(map(int, input().split()))
target = int(input())


found = set()
done = False
for i in arr:
    if target-i in found:
        print(True)
        done = True
        break

    found.add(i)

if not done:
    print(False)

