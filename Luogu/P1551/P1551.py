MAXN = 5050
fa = list (range(MAXN))
def find (x):
    if fa[x] != x:
        fa[x] = find (fa[x])
    return fa[x]

n, m, p = map (int, input().split())
for i in range (1, n + 1):
    fa[i] = i
for i in range (1, m + 1):
    a, b = map (int, input().split())
    fa[find(a)] = find(b)
while p:
    x, y = map (int, input().split())
    if find(x) == find(y):
        print ("Yes")
    else:
        print ("No")
    p -= 1