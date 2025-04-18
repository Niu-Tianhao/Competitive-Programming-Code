#include <iostream>
#define maxn 12
using namespace std;

char pos[maxn][maxn];

void trans (int &dx, int &dy)
{
	if (dx == 0 && dy == 1)
	{
		dx = -1;
		dy = 0;
		return;
	}
	if (dx == -1 && dy == 0)
	{
		dx = 0;
		dy = -1;
		return;
	}
	if (dx == 0 && dy == -1)
	{
		dx =1;
		dy = 0;
		return;
	}
	if (dx == 1 && dy == 0)
	{
		dx = 0;
		dy = 1;
		return;
	}
}

int main()
{
	int x1, y1, x2, y2; 
	int dx1 = 0, dx2 = 0, dy1 = -1, dy2 = -1;
    for (int i = 0; i < 12; i++)
    	for (int j = 0; j < 12; j++)
    		pos[i][j] = '*';
    for (int j = 1; j <= 10; j++)
    {
        for (int i = 1; i <= 10; i++)
        {
            cin >> pos[j][i];
            if (pos[j][i] == 'C')
            {
            	x1 = i;
            	y1 = j;
			}
			if (pos[j][i]=='F')
			{
				x2 = i;
				y2 = j;
			} 
        }
    }
    int time = 0;
    while ((x1 != x2 || y1 != y2) && time <= 160000)
    {
    	if (pos[y1 + dy1][x1 + dx1] == '*')
    		trans(dx1, dy1);
    	else
    	{
    		x1 += dx1;
    		y1 += dy1;
		}
		if (pos[y2 + dy2][x2 + dx2]=='*')
			trans (dx2, dy2);
		else
		{
			x2 += dx2;
			y2 += dy2;
		}
		 time++;
		 if (x1 == x2 && y1 == y2)
		 	break;
	}
	if (time >= 160000)
	{
		cout << 0;
		return 0;
	}
	cout << time;
	return 0;
}
