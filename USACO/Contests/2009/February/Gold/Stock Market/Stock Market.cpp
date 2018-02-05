/*
PROG: stock
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#define Max(a, b) ((a)>(b)?(a):(b))

int p[20][60];
int d[500010];
int main()
{
	freopen("stock.in", "r", stdin);
	freopen("stock.out", "w", stdout);
	int n, m, c, l, i, j, k;
	scanf("%d%d%d", &m, &n, &c);
	for (j = 0; j < m; j++)
		for (i = 0; i < n; i++)
			scanf("%d", p[i]+j);
	for (i = 0; i+1 < n; i++)
	{
		for (j = 0; j <= c; j++)
			d[j] = j;
		for (j = 0; j < m; j++)
			if (p[i][j] < p[i+1][j])
				for (k = p[i][j]; k <= c; k++)
					d[k] = Max(d[k], d[k-p[i][j]]+p[i+1][j]);
		for (j = 0; j <= c; j++)
			c = Max(c, d[j]);
	}
	printf("%d\n", c);
	return 0;
}
