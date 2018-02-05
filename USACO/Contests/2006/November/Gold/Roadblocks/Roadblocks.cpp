#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))

int n;
bool t[5010];
int d[2][5010];
int e[100010][3];
int *g[5010], *w[5010], deg[5010];
void dijkstra(int s, int l)
{
	int p, i;
	for (i = 0; i < n; i++)
		d[l][i] = 1000000000;
	d[l][s] = 0;
	memset(t, 0, sizeof(t));
	while (1)
	{
		p = -1;
		for (i = 0; i < n; i++)
			if (!t[i] && (p == -1 || p != -1 && d[l][p] > d[l][i]))
				p = i;
		if (p == -1)
			return;
		t[p] = 1;
		for (i = 0; i < deg[p]; i++)
			d[l][g[p][i]] = Min(d[l][g[p][i]], d[l][p]+w[p][i]);
	}
}
int main()
{
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
	int m, l, p, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", e[i], e[i]+1, e[i]+2);
		e[i][0]--;
		e[i][1]--;
		deg[e[i][0]]++;
		deg[e[i][1]]++;
	}
	for (i = 0; i < n; i++)
	{
		g[i] = new int[deg[i]+1];
		w[i] = new int[deg[i]+1];
	}
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < m; i++)
	{
		g[e[i][0]][deg[e[i][0]]] = e[i][1];
		g[e[i][1]][deg[e[i][1]]] = e[i][0];
		w[e[i][0]][deg[e[i][0]]] = w[e[i][1]][deg[e[i][1]]] = e[i][2];
		deg[e[i][0]]++;
		deg[e[i][1]]++;
	}
	p = 1000000000;
	dijkstra(0, 0);
	dijkstra(n-1, 1);
	for (i = 0; i < m; i++)
	{
		l = d[0][e[i][0]]+e[i][2]+d[1][e[i][1]];
		if (l < p && l > d[0][n-1])
			p = l;
		l = d[0][e[i][1]]+e[i][2]+d[1][e[i][0]];
		if (l < p && l > d[0][n-1])
			p = l;
	}
	printf("%d\n", p);
	return 0;
}
