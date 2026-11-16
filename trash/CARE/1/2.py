#Roll No: CH.SC.U4AIE24084
mat = [[1, 1, 0],
 [0, 1, 0],
 [0, 1, 1]]

found = False
index = 0
for i in range(len(mat)):
    if sum(mat[i]) == 1:
        isCeleb = True
        for j in range(len(mat)):
            if mat[j][i] == 0:
                isCeleb = False
                break
        if isCeleb and not found:
            found = True
            print("Found Celebrity:", i)

if not found:
    print(-1)