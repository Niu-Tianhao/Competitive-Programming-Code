#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Node 
{
    int x, y, step;
};

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}; 
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1}; 
int ans[405][405];
int n, m, sx, sy;

void bfs() 
{
    queue<Node> q;
    q.push({sx, sy, 0});
    ans[sx][sy] = 0;

    while (!q.empty()) 
    {
        Node cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) 
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny] == -1) 
            {
                ans[nx][ny] = cur.step + 1;
                q.push({nx, ny, cur.step + 1});
            }
        }
    }
}

int main() 
{
    memset(ans, -1, sizeof(ans)); 
    cin >> n >> m >> sx >> sy;
    sx--; sy--; 
    bfs(); 
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            printf("%-5d", ans[i][j]); 
        }
        printf("\n");
    }
    return 0;
}