/*
PROG: tcave
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int d[5010];
int pr[5010];
queue<int> Q;
vector<int> g[5010];
void bfs(int t)
{
	int p, i;
	memset(d, -1, sizeof(d));
	d[0] = 0;
	Q.push(0);
	while (!Q.empty())
	{
		p = Q.front(); Q.pop();
		if (p == t)
			return;
		i = g[p].size();
		for (i--; i >= 0; i--)
			if (d[g[p][i]] == -1)
			{
				d[g[p][i]] = d[p]+1;
				pr[g[p][i]] = p;
				Q.push(g[p][i]);
			}
	}
}
void print(int p)
{
	if (p)
		print(pr[p]);
	printf("%d\n", p+1);
}
int main()
{
	freopen("tcave.in", "r", stdin);
	freopen("tcave.out", "w", stdout);
	int n, m, t, p, q, w, i;
	scanf("%d%d%d", &n, &m, &t);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &p, &q, &w);
		g[p-1].push_back(q-1);
		g[p-1].push_back(w-1);
		g[q-1].push_back(p-1);
		g[q-1].push_back(w-1);
		g[w-1].push_back(p-1);
		g[w-1].push_back(q-1);
	}
	bfs(t-1);
	printf("%d\n", d[t-1]+1);
	print(t-1);
	return 0;
}
