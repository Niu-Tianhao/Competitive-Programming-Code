#include <iostream>
#include <algorithm>
#define MAXN 25
using namespace std;
int n;
string str[MAXN];

bool cmp (string s1, string s2)
{
    return s1 + s2 > s2 + s1;
}

int main()
{
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    sort (str, str + n, cmp);
    for (int i = 0; i < n; i++)
        cout << str[i];
    cout << "\n";
    return 0;
}