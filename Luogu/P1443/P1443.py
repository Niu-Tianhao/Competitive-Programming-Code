from collections import deque
import numpy as npy

class Node:
    def __init__(self, x, y, step):
        self.x = x
        self.y = y
        self.step = step

dx = [2, 1, -1, -2, -2, -1, 1, 2]
dy = [1, 2, 2, 1, -1, -2, -2, -1]

n, m, sx, sy = map (int, input().split())
sx -= 1
sy -= 1
ans = npy.full ((405, 405), -1)

def bfs ():
    q = deque()
    q.append (Node (sx, sy, 0))
    ans[sx, sy] = 0
    while q:
        cur = q.popleft()

        for i in range (8):
            nx = cur.x + dx[i]
            ny = cur.y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and ans[nx, ny] == -1:
                ans [nx, ny] = cur.step + 1
                q.append(Node (nx, ny, cur.step + 1))
bfs ()

for i in range(n):
    for j in range(m):
        print(f"{ans[i, j]:-5d}", end = "")
    print()