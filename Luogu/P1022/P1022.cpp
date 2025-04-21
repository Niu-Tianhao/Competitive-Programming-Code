#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int flag_equal;
int int_count_number = 0, int_count_x = 0;
bool book1 = false, book2 = false;
char x;
int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '=')
        {
            flag_equal = i;
            book1 = true;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            x = str[i];
            book2 = true;
        }
        if (book1 && book2)
            break;
    }
        
    int point = 0;
    while (point < flag_equal)
    {
        if (point == 0)
        {
            if (str[point] == '-')
            {
                point++;
                if (str[point] == x)
                {
                    int_count_x--;
                    point++;
                }
                if ('0' <= str[point] && str[point] <= '9')
                {
                    int num = str[point] - '0';
                    while ('0' <= str[point] && str[point] <= '9')
                    {
                        point++;
                        if ('0' <= str[point] && str[point] <= '9')
                            num = num * 10 + (str[point] - '0');
                        else if (str[point] == x)
                        {
                            int_count_x -= num;
                            num = 0;
                            point++;
                            break;
                        }
                        else if (str[point] != x)
                        {
                            int_count_number -= num;
                            num = 0;
                            break;
                        }
                    }
                }

            }
            else if (str[point] == x)
            {
                int_count_x++;
                point++;
            }
            else if ('0' <= str[point] && str[point] <= '9')
            {
                int num = str[point] - '0';
                while ('0' <= str[point] && str[point] <= '9')
                {
                    point++;
                    if ('0' <= str[point] && str[point] <= '9')
                        num = num * 10 + (str[point] - '0');
                    else if (str[point] == x)
                    {
                        int_count_x += num;
                        num = 0;
                        point++;
                        break;
                    }
                    else if (str[point] != x)
                    {
                        int_count_number += num;
                        num = 0;
                        break;
                    }
                }
            }
        }
        else
        {
            if (str[point] == '+')
            {
                point++;
                if (str[point] == x)
                    int_count_x++;
                else
                {
                    int num = str[point] - '0';
                    while ('0' <= str[point] && str[point] <= '9')
                    {
                        point++;
                        if ('0' <= str[point] && str[point] <= '9')
                            num = num * 10 + (str[point] - '0');
                        else if (str[point] == x)
                        {
                            int_count_x += num;
                            num = 0;
                            point++;
                            break;
                        }
                        else if (str[point] != x)
                        {
                            int_count_number += num;
                            num = 0;
                            break;
                        }
                    }
                }
            }
            if (str[point] == '-')
            {
                point++;
                if (str[point] == 'x')
                    int_count_x--;
                else
                {
                    if (str[point] == x)
                    {
                        int_count_x--;
                        point++;
                    }
                    if ('0' <= str[point] && str[point] <= '9')
                    {
                        int num = str[point] - '0';
                        while ('0' <= str[point] && str[point] <= '9')
                        {
                            point++;
                            if ('0' <= str[point] && str[point] <= '9')
                                num = num * 10 + (str[point] - '0');
                            else if (str[point] == x)
                            {
                                int_count_x -= num;
                                num = 0;
                                point++;
                                break;
                            }
                            else if (str[point] != x)
                            {
                                int_count_number -= num;
                                num = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    point = flag_equal + 1;
    while (point < str.length())
    {
        if (point == flag_equal + 1)
        {
            if (str[point] == '-')
            {
                point++;
                if (str[point] == x)
                {
                    int_count_x++;
                    point++;
                }
                if ('0' <= str[point] && str[point] <= '9')
                {
                    int num = str[point] - '0';
                    while ('0' <= str[point] && str[point] <= '9')
                    {
                        point++;
                        if ('0' <= str[point] && str[point] <= '9')
                            num = num * 10 + (str[point] - '0');
                        else if (str[point] == x)
                        {
                            int_count_x += num;
                            num = 0;
                            point++;
                            break;
                        }
                        else if (str[point] != x)
                        {
                            int_count_number += num;
                            num = 0;
                            break;
                        }
                    }
                }
            }
            else if (str[point] == x)
            {
                int_count_x--;
                point++;
            }
            else if ('0' <= str[point] && str[point] <= '9')
            {
                int num = str[point] - '0';
                while ('0' <= str[point] && str[point] <= '9')
                {
                    point++;
                    if ('0' <= str[point] && str[point] <= '9')
                        num = num * 10 + (str[point] - '0');
                    else if (str[point] == x)
                    {
                        int_count_x -= num;
                        num = 0;
                        point++;
                        break;
                    }
                    else if (str[point] != x)
                    {
                        int_count_number -= num;
                        num = 0;
                        break;
                    }
                }
            }
        }
        else
        {
            if (str[point] == '+')
            {
                point++;
                if (str[point] == x)
                    int_count_x--;
                else
                {
                    int num = str[point] - '0';
                    while ('0' <= str[point] && str[point] <= '9')
                    {
                        point++;
                        if ('0' <= str[point] && str[point] <= '9')
                            num = num * 10 + (str[point] - '0');
                        else if (str[point] == x)
                        {
                            int_count_x -= num;
                            num = 0;
                            point++;
                            break;
                        }
                        else if (str[point] != x)
                        {
                            int_count_number -= num;
                            num = 0;
                            break;
                        }
                    }
                }
            }
            if (str[point] == '-')
            {
                point++;
                if (str[point] == 'x')
                    int_count_x++;
                else
                {
                    if (str[point] == x)
                    {
                        int_count_x++;
                        point++;
                    }
                    if ('0' <= str[point] && str[point] <= '9')
                    {
                        int num = str[point] - '0';
                        while ('0' <= str[point] && str[point] <= '9')
                        {
                            point++;
                            if ('0' <= str[point] && str[point] <= '9')
                                num = num * 10 + (str[point] - '0');
                            else if (str[point] == x)
                            {
                                int_count_x += num;
                                num = 0;
                                point++;
                                break;
                            }
                            else if (str[point] != x)
                            {
                                int_count_number += num;
                                num = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }       
    }
    double double_count_number = (double)(int_count_number);
    double double_count_x = (double)(int_count_x);
    double result = - double_count_number / double_count_x;
    printf ("%c=%.3lf\n", x, result);
    return 0;
}