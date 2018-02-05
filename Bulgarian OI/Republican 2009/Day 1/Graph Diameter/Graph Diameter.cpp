#include <cstdio>
#include <vector>
using namespace std;

int d[1010];
int par[1010];
vector<int> g[1010], w[1010];
int solve(int p)
{
	if (d[p] != -1)
		return d[p];
	int i;
	d[p] = 0;
	for (i = g[p].size()-1; i >= 0; i--)
		if (g[p][i] != par[p])
		{
			par[g[p][i]] = p;
			if (d[p] < solve(g[p][i])+w[p][i])
				d[p] = d[g[p][i]]+w[p][i];
		}
	return d[p];
}
int main()
{
	int n, m, p, q, u, i;
	scanf("%d", &n);
	for (i = 0; i < n-1; i++)
	{
		scanf("%d%d%d", &p, &q, &u);
		g[--p].push_back(--q);
		w[p].push_back(u);
		g[q].push_back(p);
		w[q].push_back(u);
	}
	m = 0;
	memset(d, -1, sizeof(d));
	memset(par, -1, sizeof(par));
	for (p = 0; p < n; p++)
	{
		if (m < solve(p))
			m = d[p];
		u = q = -1;
		for (i = g[p].size()-1; i >= 0; i--)
			if (g[p][i] != par[p] && (u == -1 || solve(g[p][i])+w[p][i] > d[g[p][u]]+w[p][u]))
				u = i;
		for (i = g[p].size()-1; i >= 0; i--)
			if (g[p][i] != par[p] && i != u && (q == -1 || solve(g[p][i])+w[p][i] > d[g[p][q]]+w[p][q]))
				q = i;
		if (u != -1 && q != -1 && m < d[g[p][u]]+w[p][u]+d[g[p][q]]+w[p][q])
			m = d[g[p][u]]+w[p][u]+d[g[p][q]]+w[p][q];
	}
	printf("%d\n", m);
	return 0;
}
