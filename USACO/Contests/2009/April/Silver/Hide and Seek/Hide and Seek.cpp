/*
PROG: hideseek
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int d[20010];
queue<int> Q;
vector<int> g[20010];
int main()
{
	freopen("hideseek.in", "r", stdin);
	freopen("hideseek.out", "w", stdout);
	int n, m, p, q, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &p, &q);
		g[p-1].push_back(q-1);
		g[q-1].push_back(p-1);
	}
	memset(d, -1, sizeof(d));
	d[0] = 0;
	Q.push(0);
	while (!Q.empty())
	{
		p = Q.front(); Q.pop();
		i = g[p].size();
		for (i--; i >= 0; i--)
			if (d[g[p][i]] == -1)
			{
				d[g[p][i]] = d[p]+1;
				Q.push(g[p][i]);
			}
	}
	p = m = 0;
	for (i = 0; i < n; i++)
	{
		if (d[i] > d[p])
		{
			p = i;
			m = 0;
		}
		m += (d[i] == d[p]);
	}
	printf("%d %d %d\n", p+1, d[p], m);
	return 0;
}
