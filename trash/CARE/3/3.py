#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

from math import factorial

n = 4
r = 1
g = 1
b = 1

def perm(n, a, b, c):
    return factorial(n) // (factorial(a) * factorial(b) * factorial(c))

ans = 0

for i in range(r, n+1):
    for j in range(g, n+1):
        for k in range(b, n+1):
            if i + j + k == n:
                ans += perm(n, i, j, k)

print(ans)
