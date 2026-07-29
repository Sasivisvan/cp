from collections import deque
def get_neis(x,y):
    neis = []
    dirs = [(1,0), (-1,0), (0,1), (0,-1)]

    for p in dirs:
        if x+p[0] < len(mat) and y+p[1] < len(mat[0]) and x+p[0]>=0 and y+p[1]>=0:
            neis.append((x+p[0], y+p[1]))
    return neis

def BFS(x,y):

    count = 0
    q = deque()
    q.append((x,y))
    mat[x][y] = 0
    while len(q)>0:
        curr = q.popleft()
        count+=1
        
        neis = get_neis(curr[0],curr[1])
        for i in neis:
            if mat[i[0]][i[1]] == 1:
                mat[i[0]][i[1]] = 0
                q.append(i)
    return count


def solve():
    all_counts = []

    for i in range(len(mat)):
        for j in range(len(mat[0])):
            if mat[i][j] == 1:
                all_counts.append(BFS(i,j))

    all_counts = sorted(all_counts)[::-1]
    total_sum=0
    for i in range(len(all_counts)):
        if i%2 == 1:
            total_sum+=all_counts[i]

    print(total_sum)

mat = [
    [1, 0, 1, 1, 0],
    [1, 0, 0, 1, 0],
    [0, 1, 0, 0, 1],
    [1, 1, 1, 0, 1],
    [0, 0, 0, 0, 1]
]

solve()