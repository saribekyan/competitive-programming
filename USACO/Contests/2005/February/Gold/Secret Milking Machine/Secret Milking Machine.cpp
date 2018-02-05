#include <cstdio>
#include <algorithm>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))

int n, l;
int g[210][210];
struct edge
{
	int p, q, w;
} e[40010];
bool operator <(edge a, edge b)
{
	return a.w < b.w;
}
bool t[210];
int way[210];
void dfs(int p)
{
	if (p == n-1)
		return;
	int i;
	for (i = 0; i < n; i++)
		if (!t[i] && g[p][i])
		{
			t[i] = 1;
			way[l++] = i;
			dfs(i);
			if (way[l-1] == n-1)
				return;
			l--;
		}
}
int nways(int k)
{
	int f=0, m, i;
	memset(g, 0, sizeof(g));
	for (i = 0; i <= k; i++)
	{
		g[e[i].p][e[i].q]++;
		g[e[i].q][e[i].p]++;
	}
	way[0] = 0;
	while (1)
	{
		l = 1;
		memset(t, 0, sizeof(t));
		t[0] = 1;
		dfs(0);
		if (way[l-1] != n-1)
			return f;
		m = 1000000000;
		for (i = 0; i < l-1; i++)
			m = Min(m, g[way[i]][way[i+1]]);
		for (i = 0; i < l-1; i++)
		{
			g[way[i]][way[i+1]] -= m;
			g[way[i+1]][way[i]] += m;
		}
		f += m;
	}
	return 0;
}
int main()
{
	freopen("secret.in", "r", stdin);
	freopen("secret.out", "w", stdout);
	int m, t, p, q, k, i;
	scanf("%d%d%d", &n, &m, &t);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &e[i].p, &e[i].q, &e[i].w);
		e[i].p--;
		e[i].q--;
	}
	p = 0;
	q = m-1;
	sort(e, e+m);
	while (q-p > 1)
	{
		k = ((p+q)>>1);
		if (nways(k) < t)
			p = k;
		else
			q = k;
	}
	if (nways(p) >= t)
		printf("%d\n", e[p].w);
	else
		printf("%d\n", e[q].w);
	return 0;
}
