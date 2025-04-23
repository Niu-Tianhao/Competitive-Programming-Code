#include <iostream>
#include <cstdio>
#define MAXN 5050
using namespace std;
int n, m, p;
int fa[MAXN];

int find (int num)
{
    if (fa[num] != num)
        fa[num] = find (fa[num]);
    return fa[num];
}

int main()
{
    scanf ("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        scanf ("%d%d", &a, &b);
        fa[find(a)] = find(b);
    }
    int x, y;
    while (p--)
    {
        scanf ("%d%d", &x, &y);
        if (find(x) == find(y))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}