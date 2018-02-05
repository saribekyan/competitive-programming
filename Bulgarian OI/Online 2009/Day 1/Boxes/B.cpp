/*
TASK:boxes
LANG:C++
*/
#include <cstdio>
#include <vector>
using namespace std;

bool t[100010];
int st[100010];
vector<int> g[100010];
void dfs(int p)
{
	int l = 0, q, i;
	t[p] = 1;
	st[l++] = p;
	while (l)
	{
		p = st[--l];
		q = g[p].size();
		for (i = q-1; i >= 0; i--)
		{
			q = g[p][i];
			if (!t[q])
			{
				t[q] = 1;
				st[l++] = q;
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int l, n, p, i;
	for (l = 0; l < 2; l++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			g[i].clear();
			t[i] = 0;
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d", &p);
			g[p-1].push_back(i);
			g[i].push_back(p-1);
		}
		p = 0;
		for (i = 0; i < n; i++)
			if (!t[i])
			{
				dfs(i);
				p++;
			}
		if (l == 0)
			printf("%d ", p);
		else
			printf("%d\n", p);
	}
	return 0;
}
