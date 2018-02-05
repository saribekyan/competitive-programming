#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int t[255][255];
queue<int> a1, a2;
int g[255][255], deg[255];
int main()
{
	freopen("age.in", "r", stdin);
	freopen("age.out", "w", stdout);
	int n, m, p, q, i, j;
	scanf("%d%d%d%d", &n, &m, &p, &q);
	memset(t, -1, sizeof(t));
	t[p-1][q-1] = 0;
	a1.push(p-1);
	a2.push(q-1);
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &p, &q);
		g[p-1][deg[p-1]++] = q-1;
	}
	while (!a1.empty())
	{
		p = a1.front();
		q = a2.front();
		if (p == q)
		{
			printf("%d\n", t[p][q]);
			return 0;
		}
		a1.pop();
		a2.pop();
		for (i = 0; i < deg[p]; i++)
			for (j = 0; j < deg[q]; j++)
				if (t[g[p][i]][g[q][j]] == -1)
				{
					a1.push(g[p][i]);
					a2.push(g[q][j]);
					t[g[p][i]][g[q][j]] = t[p][q]+1;
				}
	}
	printf("NIE\n");
	return 0;
}
