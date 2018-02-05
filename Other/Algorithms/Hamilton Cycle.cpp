#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct edge
{
	int p, q, w;
} e[10000];
bool operator < (edge a, edge b)
{
	return a.w < b.w;
}
int u[100];
bool t[100];
int x[100], y[100];
int g[100][100], deg[100];
void dfs(int p)
{
	int i;
	for (i = 0; i < deg[p]; i++)
		if (!t[g[p][i]])
		{
			t[g[p][i]] = 1;
			printf("%d\n", g[p][i]+1);
			dfs(g[p][i]);
		}
}
int main()
{
	int n, m, c, c1, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", x+i, y+i);
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
		{
			e[i*n+j].p = i;
			e[i*n+j].q = j;
			e[i*n+j].w = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		}
	m = n*(n-1)/2;
	sort(e, e+m);
	for (i = 0; i < n; i++)
		u[i] = i;
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < m; i++)
		if (u[e[i].p] != u[e[i].q])
		{
			if (u[e[i].p] < u[e[i].q])
			{
				c = u[e[i].p];
				c1 = u[e[i].q];
				g[e[i].p][deg[e[i].p]++] = e[i].q;
			}
			else
			{
				c = u[e[i].q];
				c1 = u[e[i].p];
				g[e[i].q][deg[e[i].q]++] = e[i].p;
			}
			for (j = 0; j < n; j++)
				if (u[j] == c1)
					u[j] = c;
		}
	printf("1\n");
	memset(t, 0, sizeof(t));
	t[0] = 1;
	dfs(0);
	printf("1\n");
	return 0;
}
