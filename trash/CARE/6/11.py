#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

r, c = 10, 9
mat = [
    [5,7,5,3,2,9,5,1,6],
    [3,7,6,2,5,9,6,9,2],
    [3,7,8,9,7,3,9,6,6],
    [6,2,3,9,1,4,5,2,9],
    [9,4,3,7,8,5,2,2,5],
    [9,1,8,9,6,3,2,9,2],
    [8,2,3,8,9,7,3,9,1],
    [1,8,6,9,4,6,5,3,1],
    [3,7,8,9,7,9,2,6,9],
    [8,9,2,5,9,5,3,1,8]
]
x, y = 4, 4

ans = []
for i in range(0, r - x + 1, x):
    for j in range(0, c - y + 1, y):
        s = 0
        for di in range(x):
            for dj in range(y):
                s += mat[i + di][j + dj]
        ans.append(s)

print(" ".join(map(str, ans)))
