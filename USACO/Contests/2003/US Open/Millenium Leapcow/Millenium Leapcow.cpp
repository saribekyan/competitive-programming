/*
PROG: leap2
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int w[400][400];
int x[160000], y[160000];
int d[160000], p[160000];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int main()
{
	freopen("leap2.in", "r", stdin);
	freopen("leap2.out", "w", stdout);
	int n, k, l, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			scanf("%d", w[i]+j);
			x[w[i][j]] = i;
			y[w[i][j]] = j;
		}
	for (i = 1; i <= n*n; i++)
	{
		d[i] = 1;
		p[i] = -1;
	}
	for (i = n*n-1; i > 0; i--)
		for (j = 0; j < 8; j++)
		{
			k = x[i]+dx[j];
			l = y[i]+dy[j];
			if (k >= 0 && k < n && l >= 0 && l < n && w[k][l] > i)
				if (d[w[k][l]]+1 > d[i] || d[w[k][l]]+1 == d[i] && p[i] > w[k][l])
				{
					d[i] = d[w[k][l]]+1;
					p[i] = w[k][l];
				}
		}
	k = 1;
	for (i = 2; i <= n*n; i++)
		if (d[k] < d[i])
			k = i;
	printf("%d\n", d[k]);
	while (k != -1)
	{
		printf("%d\n", k);
		k = p[k];
	}
	return 0;
}
