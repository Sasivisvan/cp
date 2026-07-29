#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

r, c = 4, 5
mat = [
    [1, 0, 1, 1, 1],
    [1, 1, 1, 1, 1],
    [0, 1, 1, 1, 0],
    [1, 1, 1, 1, 0]
]

h = [0] * c
ans = 0

for i in range(r):
    for j in range(c):
        if mat[i][j] == 1:
            h[j] += 1
        else:
            h[j] = 0

    stk = []
    left = [0] * c
    right = [0] * c

    for j in range(c):
        while stk and h[stk[-1]] >= h[j]:
            stk.pop()
        left[j] = stk[-1] + 1 if stk else 0
        stk.append(j)

    stk = []
    for j in range(c - 1, -1, -1):
        while stk and h[stk[-1]] >= h[j]:
            stk.pop()
        right[j] = stk[-1] - 1 if stk else c - 1
        stk.append(j)

    for j in range(c):
        area = h[j] * (right[j] - left[j] + 1)
        ans = max(ans, area)

print(ans)
