#include <cstdio>
#include <vector>
using namespace std;

int s;
bool t[1010];
bool g[1010][1010];
vector<int> e[1010];
void dfs(int p)
{
	int i;
	for (i = e[p].size()-1; i >= 0; i--)
		if (!t[e[p][i]])
		{
			t[e[p][i]] = 1;
			g[s][e[p][i]] = 1;
			dfs(e[p][i]);
		}
}
int main()
{
	freopen("ranking.in", "r", stdin);
	freopen("ranking.out", "w", stdout);
	int n, m, p, q, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &p, &q);
		g[p-1][q-1] = 1;
		e[p-1].push_back(q-1);
	}
	for (s = 0; s < n; s++)
	{
		for (i = 0; i < n; i++)
			t[i] = 0;
		t[s] = 1;
		dfs(s);
	}
	m = 0;
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
			m += !g[i][j] && !g[j][i];
	printf("%d\n", m);
	return 0;
}
