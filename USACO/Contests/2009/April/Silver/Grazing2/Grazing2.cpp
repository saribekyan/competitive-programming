/*
PROG: graze2
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define inf 1000000000

int sw;
int p[2010];
int d[2][2010];
int main()
{
	freopen("graze2.in", "r", stdin);
	freopen("graze2.out", "w", stdout);
	int n, s, l, i, j;
	scanf("%d%d", &n, &s);
	for (i = 0; i < n; i++)
		scanf("%d", p+i);
	sort(p, p+n);
	l = (s-1)/(n-1);
	for (i = 0; i <= n; i++)
		d[sw][i] = inf;
	d[sw][1] = p[0]-1;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j <= n; j++)
			d[sw^1][j] = inf;
		for (j = 1; j <= i+1; j++)
		{
			if (d[sw^1][j] > d[sw][j]+abs(i*l+j-p[i]))
				d[sw^1][j] = d[sw][j]+abs(i*l+j-p[i]);
			if (j > 1 && d[sw^1][j] > d[sw][j-1]+abs(i*l+j-p[i]))
				d[sw^1][j] = d[sw][j-1]+abs(i*l+j-p[i]);
		}
		sw ^= 1;
	}
	printf("%d\n", d[sw][s-(n-1)*l]);
	return 0;
}
