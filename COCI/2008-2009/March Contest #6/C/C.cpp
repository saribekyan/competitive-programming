#include <stdio.h>

int d[110][110];
int main()
{
	int n, m, p, q, s, i, j, k, l;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &p, &q);
		d[p][q] = 1;
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			d[i][j] += d[i][j-1]+d[i-1][j]-d[i-1][j-1];
	p = m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			for (s = 1; i+s-1 <= n; s++)
				if (m%s == 0)
				{
					k = i+s-1;
					l = j+m/s-1;
					if (l > n)
						continue;
					if (p > m-(d[k][l]-d[i-1][l]-d[k][j-1]+d[i-1][j-1]))
						p = m-(d[k][l]-d[i-1][l]-d[k][j-1]+d[i-1][j-1]);
				}
	printf("%d\n", p);
	return 0;
}
