n = int (input())
sum_solution = 0
ans = [0] * 15
check1 = [False] * 28
check2 = [False] * 28
check3 = [False] * 28
def dfs (line):
    global sum_solution
    if line > n:
        sum_solution += 1
        if sum_solution <= 3:
            for i in range (1, n + 1):
                print (ans[i], end = ' ')
            print()
        return
    for i in range (1, n + 1):
        if not check1[i] and not check2[line + i] and not check3[n + line - i]:
            ans[line] = i
            check1[i] = True
            check2[line + i] = True
            check3[n - i + line] = True
            dfs (line + 1)
            check1[i] = False
            check2[line + i] = False
            check3[n - i + line] = False
dfs (1)
print (sum_solution)