from collections import deque

def get_neis(x, y, n, m):
    neis = []
    d = [(1,0), (-1,0), (0,1), (0,-1)]

    for dx, dy in d:
        nx = x + dx
        ny = y + dy

        if nx >= 0 and ny >= 0 and nx < n and ny < m:
            neis.append((nx, ny))

    return neis


def bfs(x, y, n, m, mat, vis):
    q = deque()
    q.append((x, y))
    vis[x][y] = True
    closed = True

    while q:
        i, j = q.popleft()

        if i == 0 or j == 0 or i == n-1 or j == m-1:
            closed = False

        neis = get_neis(i, j, n, m)

        for ni, nj in neis:
            if mat[ni][nj] == 1 and not vis[ni][nj]:
                vis[ni][nj] = True
                q.append((ni, nj))

    return closed


def closed_islands(n, m, mat):
    vis = [[False] * m for _ in range(n)]
    ans = 0

    for i in range(n):
        for j in range(m):
            if mat[i][j] == 1 and not vis[i][j]:
                if bfs(i, j, n, m, mat, vis):
                    ans += 1

    return ans


n = 5
m = 8

mat = [
    [0,0,0,0,0,0,0,1],
    [0,1,1,1,1,0,0,1],
    [0,1,0,1,0,0,0,1],
    [0,1,1,1,1,0,1,0],
    [1,0,0,0,0,1,0,1]
]

print(closed_islands(n, m, mat))