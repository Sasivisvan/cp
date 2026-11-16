a = list(map(int, input().split()))
b = list(map(int, input().split()))
done  = False
for i in range(len(b)):
    if a[i]!=b[i]:
        print(i)
        done=True
        break

if not done:
    print(len(a)-1)


