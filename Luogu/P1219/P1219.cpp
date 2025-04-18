#include <cstdio>
using namespace std;
int n, sum = 0;
int ans[14];
bool check1[28], check2[28], check3[28];
void dfs (int line)
{
	if (line > n)
	{
		sum++;
		if (sum > 3)
			return;
		else
		{
			for (int i = 1; i <= n; i++)
				printf ("%d ", ans[i]);
			printf ("\n");
			return;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if ((!check1[i]) && (!check2[line + i]) && (!check3[line - i + n]))
        {
            ans[line] = i;
            check1[i] = true; check2[line + i] = true; check3[line - i + n] = true;
            dfs (line + 1);
            check1[i] = false; check2[line + i] = false; check3[line - i + n] = false;
        }
	}
}
int main()
{
	scanf ("%d", &n);
	dfs (1);
	printf ("%d", sum);
	return 0;
}