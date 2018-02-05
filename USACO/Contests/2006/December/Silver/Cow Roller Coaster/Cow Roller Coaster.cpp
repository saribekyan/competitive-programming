#include <stdio.h>
#include <string.h>
#define Max(a, b) ((a)>(b)?(a):(b))

int in[10010][4];
int d[1010][1010];
int *w[1010], *f[1010], *c[1010], deg[1010];
int main()
{
	freopen("coaster.in", "r", stdin);
	freopen("coaster.out", "w", stdout);
	int l, n, b, i, j, k;
	scanf("%d%d%d", &l, &n, &b);
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", in[i], in[i]+1, in[i]+2, in[i]+3);
		deg[in[i][0]]++;
	}
	for (i = 0; i <= l+1; i++)
	{
		w[i] = new int[deg[i]+1];
		f[i] = new int[deg[i]+1];
		c[i] = new int[deg[i]+1];
	}
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < n; i++)
	{
		w[in[i][0]][deg[in[i][0]]] = in[i][1];
		f[in[i][0]][deg[in[i][0]]] = in[i][2];
		c[in[i][0]][deg[in[i][0]]] = in[i][3];
		deg[in[i][0]]++;
	}
	memset(d, -1, sizeof(d));
	d[0][0] = 0;
	for (i = 0; i <= b; i++)
		for (j = 0; j <= l; j++)
			if (d[i][j] != -1)
				for (k = 0; k < deg[j]; k++)
					if (i+c[j][k] <= b)
						d[i+c[j][k]][j+w[j][k]] = Max(d[i+c[j][k]][j+w[j][k]], d[i][j]+f[j][k]);
	k = -1;
	for (i = 0; i <= b; i++)
		k = Max(k, d[i][l]);
	printf("%d\n", k);
	return 0;
}
