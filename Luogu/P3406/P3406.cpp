#include <iostream>
#include <cstdio>
#define MAXN 100050
using namespace std;
int n, m;
int p[MAXN * 10];
int a[MAXN], b[MAXN], c[MAXN];
int d[MAXN] = {0};
int main()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf ("%d", &p[i]);
    for (int i = 2; i <= m; i++)
    {
        d[max (p[i], p[i - 1])]--;
        d[min (p[i], p[i - 1])]++; 
    }
    long long cnt = 0, sum = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        scanf ("%d%d%d", &a[i], &b[i], &c[i]);
        cnt += d[i];
        if (cnt == 0)
            continue;
        long long ticket = (long long)cnt * a[i];
        long long IC = c[i] + (long long)cnt * b[i];
        sum += min (ticket, IC);
    }
    printf ("%lld", sum);
    return 0;
}