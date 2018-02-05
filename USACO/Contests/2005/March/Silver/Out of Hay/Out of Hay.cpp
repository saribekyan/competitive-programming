#include <cstdio>
#include <algorithm>
using namespace std;

int n;
struct edge
{
	int p, q, w;
} e[10010];
bool operator < (edge a, edge b)
{
	return a.w < b.w;
}
bool t[2010];
bool g[2010][2010];
void dfs(int p)
{
	int i;
	for (i = 0; i < n; i++)
		if (!t[i] && g[p][i])
		{
			t[i] = 1;
			dfs(i);
		}
}
bool can(int k)
{
	int i;
	memset(t, 0, sizeof(t));
	memset(g, 0, sizeof(g));
	for (i = 0; i <= k; i++)
		g[e[i].p][e[i].q] = g[e[i].q][e[i].p] = 1;
	t[0] = 1;
	dfs(0);
	for (i = 0; i < n && t[i]; i++);
	return (i == n);
}
int main()
{
	freopen("outofhay.in", "r", stdin);
	freopen("outofhay.out", "w", stdout);
	int m, p, q, k, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &e[i].p, &e[i].q, &e[i].w);
		e[i].p--;
		e[i].q--;
	}
	sort(e, e+m);
	p = 0;
	q = m-1;
	while (q-p > 1)
	{
		k = ((p+q)>>1);
		if (can(k))
			q = k;
		else
			p = k;
	}
	if (can(p))
		printf("%d\n", e[p].w);
	else
		printf("%d\n", e[q].w);
	return 0;
}
