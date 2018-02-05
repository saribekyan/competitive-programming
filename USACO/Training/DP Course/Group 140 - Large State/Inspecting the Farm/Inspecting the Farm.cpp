/*
PROG: inspect
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

long long d[2][2510];
vector<int> g[2510];
int main()
{
	freopen("inspect.in", "r", stdin);
	freopen("inspect.out", "w", stdout);
	long long ans;
	int n, k, m, sw, p, q, i;
	scanf("%d%d%d", &n, &k, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &p, &q);
		g[p-1].push_back(q-1);
	}
	sw = 0;
	ans = 0;
	memset(d[sw], 0, sizeof(d[sw]));
	d[sw][0] = 1;
	for (i = 1; i <= n; i++)
	{
		memset(d[sw^1], 0, sizeof(d[sw^1]));
		for (p = 0; p < n; p++)
			for (q = g[p].size()-1; q >= 0; q--)
				d[sw^1][g[p][q]] += d[sw][p];
		sw ^= 1;
		if (i >= k)
			ans += d[sw][n-1];
	}
	printf("%lld\n", ans);
	return 0;
}
