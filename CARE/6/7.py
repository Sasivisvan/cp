#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

r, c = 5, 6
mat = [
    [47, 48, 63, 37, 29, 72],
    [78, 60, 67, 13, 46, 30],
    [65, 72, 95, 55, 52, 76],
    [86, 62, 88, 48, 80, 91],
    [31, 49, 81, 76, 27, 95]
]
x = 55

found = False
fi, fj = -1, -1
for i in range(r):
    for j in range(c):
        if i == 0 or i == r - 1 or j == 0 or j == c - 1:
            continue
        if mat[i][j] == x:
            fi, fj = i, j
            found = True
            break
    if found:
        break

if not found:
    print(-1)
else:
    dirs = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
    ans = []
    for di, dj in dirs:
        ni, nj = fi + di, fj + dj
        while 0 <= ni < r and 0 <= nj < c:
            li, lj = ni, nj
            ni += di
            nj += dj
        ans.append(mat[li][lj])
    print(" ".join(map(str, ans)))
