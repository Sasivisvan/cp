mat=[]
r,c = tuple(map(int, input().split(" ")))
for i in range(r):
    mat.append(list(map(int, input().split(" "))))

for i in mat:
    i[i.index(min(i))] = -1

for i in range(len(mat[0])):
    col_min = mat[0][i]
    col_min_index = 0
    for j in range(len(mat)):
        if mat[j][i]<col_min and mat[j][i]!=-1:
            col_min = mat[j][i]
            col_min_index = j
    
    mat[col_min_index][i] = -1

for row in mat:
    print()
    for n in row:
        if n!=-1:
            print(n,end=" ")
    
