#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

n = 5
trees = [10, 7, 5, 8, 6]
x, t = 3, 4

pos = 0
for day in range(t):
    cut = []
    cnt = 0
    p = pos
    while cnt < x:
        if trees[p % n] > 1:
            cut.append(p % n)
            cnt += 1
        p += 1
    for i in range(n):
        if i not in cut:
            trees[i] += 1
        else:
            trees[i] -= 1
    pos = (cut[-1] + 1) % n

print(" ".join(map(str, trees)))
