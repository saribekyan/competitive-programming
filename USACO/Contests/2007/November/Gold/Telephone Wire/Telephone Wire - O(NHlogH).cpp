#include <stdio.h>
#include <math.h>
#define MAXH 100
#define MAXN 100000
#define inf 1000000000

int h[MAXN+10];
int d[MAXN+10][MAXH+10];
int main()
{
	freopen("telewire.in", "r", stdin);
	freopen("telewire.out", "w", stdout);
	int n, c, p, q, k, l, r, i, j;
	scanf("%d%d", &n, &c);
	for (i = 0; i < n; i++)
		scanf("%d", h+i);
	for (i = 0; i <= MAXH; i++)
		if (i < h[0])
			d[0][i] = inf;
		else
			d[0][i] = (i-h[0])*(i-h[0]);
	for (i = 1; i < n; i++)
		for (j = h[i]; j <= MAXH; j++)
		{
			p = h[i-1];
			q = MAXH;
			while (q-p > 2)
			{
				k = (q-p+1)/3;
				l = p+k;
				r = q-k;
				if (d[i-1][l]+c*abs(l-j) < d[i-1][r]+c*abs(r-j))
					q = r;
				else
					p = l;
			}
			for (l = p+1; l <= q; l++)
				if (d[i-1][p]+c*abs(p-j) > d[i-1][l]+c*abs(l-j))
					p = l;
			d[i][j] = d[i-1][p]+c*abs(p-j)+(j-h[i])*(j-h[i]);
		}
	p = inf;
	for (i = h[n-1]; i <= MAXH; i++)
		if (p > d[n-1][i])
			p = d[n-1][i];
	printf("%d\n", p);
	return 0;
}
