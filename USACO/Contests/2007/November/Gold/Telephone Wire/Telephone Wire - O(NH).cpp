/*
PROG: telewire
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <math.h>
#define MAXH 100
#define MAXN 100000
#define inf 1000000000

int c;
int h[MAXN+10];
int d[2][MAXH+10], lo[MAXH+10], hi[MAXH+10];
void set_lh(int sw)
{
	int i;
	lo[MAXH] = d[sw][MAXH]+c*MAXH;
	for (i = MAXH-1; i >= 0; i--)
		if (lo[i+1] < d[sw][i]+c*i)
			lo[i] = lo[i+1];
		else
			lo[i] = d[sw][i]+c*i;
	hi[0] = d[sw][0];
	for (i = 1; i <= MAXH; i++)
		if (hi[i-1] < d[sw][i]-c*i)
			hi[i] = hi[i-1];
		else
			hi[i] = d[sw][i]-c*i;
}
int main()
{
	freopen("telewire.in", "r", stdin);
	freopen("telewire.out", "w", stdout);
	int n, sw, p, i, j;
	scanf("%d%d", &n, &c);
	for (i = 0; i < n; i++)
		scanf("%d", h+i);
	sw = 0;
	for (i = 0; i <= MAXH; i++)
		if (i < h[0])
			d[sw][i] = inf;
		else
			d[sw][i] = (i-h[0])*(i-h[0]);
	for (i = 1; i < n; i++, sw^=1)
	{
		set_lh(sw);
		for (j = 0; j < h[i]; j++)
			d[sw^1][j] = inf;
		for (j = h[i]; j <= MAXH; j++)
			if (-c*j+lo[j] < c*j+hi[j-1])
				d[sw^1][j] = (j-h[i])*(j-h[i])-c*j+lo[j];
			else
				d[sw^1][j] = (j-h[i])*(j-h[i])+c*j+hi[j-1];
	}
	p = inf;
	for (i = h[n-1]; i <= MAXH; i++)
		if (p > d[sw][i])
			p = d[sw][i];
	printf("%d\n", p);
	return 0;
}
