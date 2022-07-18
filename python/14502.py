import copy
from collections import deque

def bfs() : 
    q = deque()
    graph = copy.deepcopy(arr)
    for i in range(N) : 
        for j in range(M) :
            if graph[i][j] == 2 :
                q.append((i, j))
    
    while q :
        x, y = q.popleft()
        for i in range(4) :
            nextX = x + dx[i]
            nextY = y + dy[i]
            if nextX > -1 and nextX < N and nextY > -1 and nextY < M and graph[nextX][nextY] == 0 :
                graph[nextX][nextY] = 2
                q.append((nextX, nextY))
    
    global ans
    cnt = 0
    for i in range(N) : 
        cnt += graph[i].count(0)
    ans = max(ans, cnt)

def dfs(wall) :
    if wall == 3 :
        bfs()
        return
    for i in range(N) : 
        for j in range(M) :
            if arr[i][j] == 0 :
                arr[i][j] = 1
                dfs(wall + 1)
                arr[i][j] = 0

N, M = map(int, input().split())
dx = (1, -1, 0, 0)
dy = (0, 0, -1, 1)
ans = 0

arr = [list(map(int, input().split())) for _ in range(N)]

dfs(0)
print(ans)
