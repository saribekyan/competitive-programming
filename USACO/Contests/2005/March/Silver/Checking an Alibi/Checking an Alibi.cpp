#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))

int d[510];
bool t[510];
int ans[510];
int g[510][510];
int main()
{
	freopen("alibi.in", "r", stdin);
	freopen("alibi.out", "w", stdout);
	int n, m, p, q, u, v, w, i, j;
	scanf("%d%d%d%d", &n, &m, &p, &q);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			g[i][j] = 1000000000;
		g[i][i] = 0;
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		g[u-1][v-1] = g[v-1][u-1] = Min(g[u-1][v-1], w);
	}
	d[0] = 0;
	memset(t, 0, sizeof(t));
	for (i = 1; i < n; i++)
		d[i] = 1000000000;
	while (1)
	{
		u = -1;
		for (i = 0; i < n; i++)
			if (!t[i] && (u == -1 || d[u] > d[i]))
				u = i;
		if (u == -1)
			break;
		t[u] = 1;
		for (i = 0; i < n; i++)
			d[i] = Min(d[i], d[u]+g[u][i]);
	}
	n = 0;
	for (i = 0; i < p; i++)
	{
		scanf("%d", &u);
		if (d[u-1] <= q)
			ans[n++] = i+1;
	}
	printf("%d\n", n);
	for (i = 0; i < n; i++)
		printf("%d\n", ans[i]);
	return 0;
}
