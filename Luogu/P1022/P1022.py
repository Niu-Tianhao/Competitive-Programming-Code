s = input()

flag_equal = -1
book1 = False
book2 = False
x = ''
int_count_number = 0
int_count_x = 0

# 找到 'x' 和 '=' 的位置
for i in range(len(s)):
    if s[i] == '=':
        flag_equal = i
        book1 = True
    elif 'a' <= s[i] <= 'z':
        x = s[i]
        book2 = True
    if book1 and book2:
        break

point = 0

# 处理等号左边的表达式
while point < flag_equal:
    if point == 0:
        if s[point] == '-':
            point += 1
            if point < len(s) and s[point] == x:
                int_count_x -= 1
                point += 1
            if point < len(s) and '0' <= s[point] <= '9':
                num = int(s[point])
                while point < len(s) and '0' <= s[point] <= '9':
                    point += 1
                    if point < len(s) and '0' <= s[point] <= '9':
                        num = num * 10 + int(s[point])
                    elif point < len(s) and s[point] == x:
                        int_count_x -= num
                        num = 0
                        point += 1
                        break
                    else:
                        int_count_number -= num
                        num = 0
                        break
        elif s[point] == x:
            int_count_x += 1
            point += 1
        elif '0' <= s[point] <= '9':
            num = int(s[point])
            while point < len(s) and '0' <= s[point] <= '9':
                point += 1
                if point < len(s) and '0' <= s[point] <= '9':
                    num = num * 10 + int(s[point])
                elif point < len(s) and s[point] == x:
                    int_count_x += num
                    num = 0
                    point += 1
                    break
                else:
                    int_count_number += num
                    num = 0
                    break
    else:
        if s[point] == '+':
            point += 1
            if point < len(s) and s[point] == x:
                int_count_x += 1
            else:
                num = int(s[point])
                while point < len(s) and '0' <= s[point] <= '9':
                    point += 1
                    if point < len(s) and '0' <= s[point] <= '9':
                        num = num * 10 + int(s[point])
                    elif point < len(s) and s[point] == x:
                        int_count_x += num
                        num = 0
                        point += 1
                        break
                    else:
                        int_count_number += num
                        num = 0
                        break
        elif s[point] == '-':
            point += 1
            if point < len(s) and s[point] == x:
                int_count_x -= 1
            else:
                num = int(s[point])
                while point < len(s) and '0' <= s[point] <= '9':
                    point += 1
                    if point < len(s) and '0' <= s[point] <= '9':
                        num = num * 10 + int(s[point])
                    elif point < len(s) and s[point] == x:
                        int_count_x -= num
                        num = 0
                        point += 1
                        break
                    else:
                        int_count_number -= num
                        num = 0
                        break

# 处理等号右边的表达式
point = flag_equal + 1
while point < len(s):
    if point == flag_equal + 1:
        if s[point] == '-':
            point += 1
            if point < len(s) and s[point] == x:
                int_count_x += 1
                point += 1
            if point < len(s) and '0' <= s[point] <= '9':
                num = int(s[point])
                while point < len(s) and '0' <= s[point] <= '9':
                    point += 1
                    if point < len(s) and '0' <= s[point] <= '9':
                        num = num * 10 + int(s[point])
                    elif point < len(s) and s[point] == x:
                        int_count_x += num
                        num = 0
                        point += 1
                        break
                    else:
                        int_count_number += num
                        num = 0
                        break
        elif s[point] == x:
            int_count_x -= 1
            point += 1
        elif '0' <= s[point] <= '9':
            num = int(s[point])
            while point < len(s) and '0' <= s[point] <= '9':
                point += 1
                if point < len(s) and '0' <= s[point] <= '9':
                    num = num * 10 + int(s[point])
                elif point < len(s) and s[point] == x:
                    int_count_x -= num
                    num = 0
                    point += 1
                    break
                else:
                    int_count_number -= num
                    num = 0
                    break
    else:
        if s[point] == '+':
            point += 1
            if point < len(s) and s[point] == x:
                int_count_x -= 1
            else:
                num = int(s[point])
                while point < len(s) and '0' <= s[point] <= '9':
                    point += 1
                    if point < len(s) and '0' <= s[point] <= '9':
                        num = num * 10 + int(s[point])
                    elif point < len(s) and s[point] == x:
                        int_count_x -= num
                        num = 0
                        point += 1
                        break
                    else:
                        int_count_number -= num
                        num = 0
                        break
        elif s[point] == '-':
            point += 1
            if point < len(s) and s[point] == x:
                int_count_x += 1
            else:
                num = int(s[point])
                while point < len(s) and '0' <= s[point] <= '9':
                    point += 1
                    if point < len(s) and '0' <= s[point] <= '9':
                        num = num * 10 + int(s[point])
                    elif point < len(s) and s[point] == x:
                        int_count_x += num
                        num = 0
                        point += 1
                        break
                    else:
                        int_count_number += num
                        num = 0
                        break

# 计算结果
result = -int_count_number / int_count_x
print(f"{x}={result:.3f}")