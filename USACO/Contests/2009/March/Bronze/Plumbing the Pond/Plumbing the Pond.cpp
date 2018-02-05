/*
PROG: plumb
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int d[55][55];
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main()
{
	freopen("plumb.in", "r", stdin);
	freopen("plumb.out", "w", stdout);
	int n, m, c, p, q, i, j, k;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", d[i]+j);
	c = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (d[i][j] > c)
				for (k = 0; k < 8; k++)
				{
					p = i+di[k];
					q = j+dj[k];
					if (d[p][q] == d[i][j])
						c = d[i][j];
				}
	printf("%d\n", c);
	return 0;
}
