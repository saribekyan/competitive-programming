/*
PROG: path
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))

int d[2][5010];
int e[15010][3];
int *g[5010], *w[5010], deg[5010];
int main()
{
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	int n, m, sw, k, l, i, j;
	scanf("%d%d%d", &n, &m, &k);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", e[i], e[i]+1, e[i]+2);
		deg[--e[i][0]]++;
		deg[--e[i][1]]++;
	}
	for (i = 0; i < n; i++)
	{
		g[i] = new int[deg[i]+1];
		w[i] = new int[deg[i]+1];
		deg[i] = 0;
	}
	for (i = 0; i < m; i++)
	{
		g[e[i][0]][deg[e[i][0]]] = e[i][1];
		g[e[i][1]][deg[e[i][1]]] = e[i][0];
		w[e[i][0]][deg[e[i][0]]++] = w[e[i][1]][deg[e[i][1]]++] = e[i][2];
	}
	sw = 0;
	memset(d, -1, sizeof(d));
	d[0][0] = 0;
	for (i = 1; i <= k; i++)
	{
		for (j = 0; j < n; j++)
		{
			d[sw^1][j] = 1000000000;
			for (l = 0; l < deg[j]; l++)
				if (d[sw][g[j][l]] != -1)
					d[sw^1][j] = Min(d[sw^1][j], d[sw][g[j][l]]+w[j][l]);
		}
		sw ^= 1;
	}
	printf("%d\n", d[sw][n-1]);
	return 0;
}
