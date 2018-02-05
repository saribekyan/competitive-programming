#include <stdio.h>
#define inf 123456789
#define Min(a, b) ((a)<(b)?(a):(b))

int e[10010][2];
int *g[10010], deg[10010];
bool t[10010];
int dfs(int p, int par)
{
	if (deg[p] == 1 && g[p][0] == par)
		if (!t[par])
		{
			t[p] = t[par] = 1;
			return 1;
		}
	int ret=0, i;
	for (i = 0; i < deg[p]; i++)
		if (g[p][i] != par)
			ret += dfs(g[p][i], p);
	for (i = 0; i < deg[p] && !t[g[p][i]]; i++);
	if (i == deg[p])
	{
		t[p] = 1;
		ret++;
		for (i = 0; i < deg[p]; i++)
			t[g[p][i]] = 1;
	}
	return ret;
}
int main()
{
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	int n, a, b, i;
	scanf("%d", &n);
	for (i = 0; i < n-1; i++)
	{
		scanf("%d%d", e[i], e[i]+1);
		deg[--e[i][0]]++;
		deg[--e[i][1]]++;
	}
	for (i = 0; i < n; i++)
	{
		g[i] = new int[deg[i]+1];
		deg[i] = 0;
	}
	for (i = 0; i < n-1; i++)
	{
		g[e[i][0]][deg[e[i][0]]++] = e[i][1];
		g[e[i][1]][deg[e[i][1]]++] = e[i][0];
	}
	printf("%d\n", dfs(0, -1));
	return 0;
}
