#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

r, c = 4, 4
mat = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
    [13, 14, 15, 16]
]

ans = []
top, bottom, left, right = 0, r - 1, 0, c - 1
layer = 0

while top <= bottom and left <= right:
    if layer % 2 == 0:
        for i in range(left, right + 1):
            ans.append(mat[top][i])
        top += 1
        for i in range(top, bottom + 1):
            ans.append(mat[i][right])
        right -= 1
        if top <= bottom:
            for i in range(right, left - 1, -1):
                ans.append(mat[bottom][i])
            bottom -= 1
        if left <= right:
            for i in range(bottom, top - 1, -1):
                ans.append(mat[i][left])
            left += 1
    else:
        for i in range(left, right + 1):
            ans.append(mat[top][i])
        top += 1
        for i in range(top, bottom + 1):
            ans.append(mat[i][right])
        right -= 1
        if top <= bottom:
            for i in range(right, left - 1, -1):
                ans.append(mat[bottom][i])
            bottom -= 1
        if left <= right:
            for i in range(bottom, top - 1, -1):
                ans.append(mat[i][left])
            left += 1
    layer += 1

print(" ".join(map(str, ans)))
