#include <stdio.h>
#define inf 123456789
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

int d[310][310];
int main()
{
	freopen("hurdles.in", "r", stdin);
	freopen("hurdles.out", "w", stdout);
	int n, m, t, p, q, h, i, j, k;
	scanf("%d%d%d", &n, &m, &t);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			d[i][j] = 123456789;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &p, &q, &h);
		d[p-1][q-1] = Min(d[p-1][q-1], h);
	}
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				d[i][j] = Min(d[i][j], Max(d[i][k], d[k][j]));
	for (i = 0; i < t; i++)
	{
		scanf("%d%d", &p, &q);
		if (d[p-1][q-1] == inf)
			printf("-1\n");
		else
			printf("%d\n", d[p-1][q-1]);
	}
	return 0;
}
