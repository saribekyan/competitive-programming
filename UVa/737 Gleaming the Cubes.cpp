#include <cstdio>
#include <algorithm>
using namespace std;

struct P{int a; bool c;}x[2000], y[2000], z[2000];
bool operator <(P a, P b){return a.a < b.a;}

int main()
{
	int n, i, j;
	while (scanf("%d", &n) && n)
	{
		for (i = 0; i < 2*n; i+=2)
		{
			scanf("%d%d%d%d", &x[i].a, &y[i].a, &z[i].a, &j);
			x[i+1].a = x[i].a+j;
			y[i+1].a = y[i].a+j;
			z[i+1].a = z[i].a+j;
			x[i].c = y[i].c = z[i].c = 1;
			x[i+1].c = y[i+1].c = z[i+1].c = 0;
		}
		sort(x, x+2*n);
		sort(y, y+2*n);
		sort(z, z+2*n);
		for (i = 0; i < n; i++)
			if (!x[i].c || !y[i].c || !z[i].c)
				break;
		if (i == n)
			printf("%d\n", (x[n].a-x[n-1].a)*(y[n].a-y[n-1].a)*(z[n].a-z[n-1].a));
		else
			printf("0\n");
	}
	return 0;
}