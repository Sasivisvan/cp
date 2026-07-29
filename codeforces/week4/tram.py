n = int(input(""))

m = 0
c = 0
for i in range(n):
    a,b = tuple(map(int, input().split()))
    c = c -a +b
    m = max(m,c)

print(m)
#116A
