#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

r, c = 3, 4
mat = [
    [10, 20, 30, 40],
    [50, 51, 52, 53],
    [60, 70, 80, 90]
]

for d in range(r + c - 1):
    vals = []
    if d < r:
        i = r - 1 - d
        j = 0
    else:
        i = 0
        j = d - r + 1
    while i < r and j < c:
        vals.append(mat[i][j])
        i += 1
        j += 1
    print(" ".join(map(str, vals)))
