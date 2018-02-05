/*
PROG: damage2
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define inf 100000
#define S(p) (p<<1)-1
#define E(p) (p<<1)

bool t[6010];
bool undamaged[3010];
int w[100010], inv[100010];
vector<int> g[6010], e[6010];

bool dfs(int p)
{
	if (undamaged[(p+1)>>1])
		return 1;
	int q, i;
	for (i = g[p].size()-1; i >= 0; i--)
	{
		q = g[p][i];
		if (!t[q] && w[e[p][i]])
		{
			t[q] = 1;
			if (dfs(q))
			{
				w[e[p][i]]--;
				w[inv[e[p][i]]]++;
				return 1;
			}
		}
	}
	return 0;
}
int flow()
{
	int ret = 0, m;
	while (1)
	{
		memset(t, 0, sizeof(t));
		t[0] = 1;
		if (!dfs(0))
			return ret;
		ret++;
	}
	return -1;
}
int main()
{
	freopen("damage2.in", "r", stdin);
	freopen("damage2.out", "w", stdout);
	int n, m, p, q, k, l, i;
	scanf("%d%d%d", &n, &m, &k);
	l = 0;
	for (i = 1; i < n; i++)
	{
		p = S(i);
		q = E(i);
		g[p].push_back(q);
		e[p].push_back(l);
		w[l] = 1;
		inv[l++] = l+1;
		g[q].push_back(p);
		e[q].push_back(l);
		w[l] = 0;
		inv[l++] = l-1;
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &p, &q);
		if (p == q)
			continue;
		p--;
		q--;
		if (q)
		{
			g[E(p)].push_back(S(q));
			e[E(p)].push_back(l);
			w[l] = inf;
			inv[l++] = l+1;
			g[S(q)].push_back(E(p));
			e[S(q)].push_back(l);
			w[l] = 0;
			inv[l++] = l-1;
		}
		if (p)
		{
			g[E(q)].push_back(S(p));
			e[E(q)].push_back(l);
			w[l] = inf;
			inv[l++] = l+1;
			g[S(p)].push_back(E(q));
			e[S(p)].push_back(l);
			w[l] = 0;
			inv[l++] = l-1;
		}
	}
	while (k--)
	{
		scanf("%d", &p);
		undamaged[p-1] = 1;
	}
	printf("%d\n", flow());
	return 0;
}
