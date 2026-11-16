n= int(input())
mat = []
for i in range(n):
    mat.append(list(map(int, input().split())))
found = False
for i in range(n):
    s = 0
    if sum(mat[i]) == 1 :

        for j in range(n):
            s+=mat[j][i]

        if s == n :
            print(True)
            found = True
            break

        else:
            found = False

if not found:
    print(False)
