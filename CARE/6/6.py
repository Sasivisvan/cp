#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

r, c = 4, 4
mat = [
    [28, 11, 18, 17],
    [14, 20, 29, 26],
    [25, 15, 22, 13],
    [27, 19, 23, 30]
]

for i in range(r):
    mn = min(mat[i])
    mat[i].remove(mn)

c -= 1
cols = []
for j in range(c):
    col = [mat[i][j] for i in range(r)]
    mn = min(col)
    col.remove(mn)
    cols.append(col)

for i in range(r - 1):
    row = [cols[j][i] for j in range(c)]
    print(" ".join(map(str, row)))
