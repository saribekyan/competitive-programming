#include <cstdio>
#include <algorithm>
using namespace std;

int e[10010][2];
bool *t[1510], v[1510];
int *g[1510], deg[1500];

void go(int p)
{
	int i;
	for (i = 0; i < deg[p]; i++)
		if (t[p][i] && !v[g[p][i]])
		{
			v[g[p][i]] = 1;
			go(g[p][i]);
		}
}
int main()
{
	freopen("order.in", "r", stdin);
	freopen("order.out", "w", stdout);
	int n, m, p, i, j;
	scanf("%d%d", &n, &m);
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", e[i], e[i]+1);
		deg[--e[i][0]]++;
		e[i][1]--;
	}
	for (i = 0; i <= n; i++)
	{
		g[i] = new int[deg[i]+1];
		t[i] = new bool[deg[i]+1];
		for (j = 0; j <= deg[i]; j++)
			t[i][j] = 1;
		deg[i] = 0;
	}
	for (i = 0; i < m; i++)
		g[e[i][0]][deg[e[i][0]]++] = e[i][1];
	for (i = 0; i < n; i++)
		sort(g[i], g[i]+deg[i]);
	p = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < deg[i]; j++)
		{
			t[i][j] = 0;
			memset(v, 0, sizeof(v));
			v[i] = 1;
			go(i);
			t[i][j] = !v[g[i][j]];
			p += t[i][j];
		}
	}
	printf("%d\n", p);
	for (i = 0; i < n; i++)
		for (j = 0; j < deg[i]; j++)
			if (t[i][j])
				printf("%d %d\n", i+1, g[i][j]+1);
	return 0;
}
