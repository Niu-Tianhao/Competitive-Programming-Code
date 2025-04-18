#include <cstdio>
#include <cmath>
using namespace std;
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    if(x==y)
    {
        printf("1");
        return 0;
    }
    int cnt=0;
    for (int i=x; i<=sqrt(x*y); i+=x)
    {
        for (int j=i; j<=y; j++)
        {
            if(gcd(i,j)==x && j*i/gcd(i,j)==y)
                cnt+=2;
        }
    }
    printf("%d",cnt);
    return 0;
}
