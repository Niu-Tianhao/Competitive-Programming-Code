n, m = map (int, input().split())
p = list (map (int, input().split()))

MAXN = 100050
d = [0] * MAXN

for i in range(1, m):
    d[max (p[i], p[i - 1])] -= 1
    d[min (p[i], p[i - 1])] += 1

a = [0] * MAXN
b = [0] * MAXN
c = [0] * MAXN

for i in range (1, n):
    a[i], b[i], c[i] = map (int, input().split())
cnt = 0
total = 0

for i in range (1, n):
    cnt += d[i]
    if cnt == 0:
        continue
    ticket = cnt * a[i]
    IC = c[i] + cnt * b[i]
    total += min (ticket, IC)
print (total)