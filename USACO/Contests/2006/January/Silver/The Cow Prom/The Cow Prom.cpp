#include <stdio.h>
#include <string.h>
#define inf 1000000000

int e[50010][2];
int *g[10010], deg[10010];

int c;
int low[10010], ind[10010];
void dfs(int p)
{
	int i;
	ind[p] = c++;
	low[p] = inf;
	for (i = deg[p]-1; i >= 0; i--)
	{
		if (ind[g[p][i]] == -1)
			dfs(g[p][i]);
		if (low[p] > low[g[p][i]])
			low[p] = low[g[p][i]];
		if (low[p] > ind[g[p][i]])
			low[p] = ind[g[p][i]];
	}
}
int main()
{
	freopen("prom.in", "r", stdin);
	freopen("prom.out", "w", stdout);
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", e[i], e[i]+1);
		deg[--e[i][0]]++;
	}
	for (i = 0; i < n; i++)
		g[i] = new int[deg[i]+1];
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < m; i++)
		g[e[i][0]][deg[e[i][0]]++] = e[i][1]-1;
	memset(low, -1, sizeof(low));
	memset(ind, -1, sizeof(ind));
	for (m = i = 0; i < n; i++)
		if (ind[i] == -1)
		{
			c = 0;
			dfs(i);
			m += ind[i] == low[i];
		}
	printf("%d\n", m);
	return 0;
}
