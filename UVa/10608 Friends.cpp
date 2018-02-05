#include <stdio.h>
#define Max(a, b) ((a)>(b)?(a):(b))

int num[30010];
int r[30010], p[30010];
int find(int u)
{
	if (u != p[u])
		p[u] = find(p[u]);
	return p[u];
}
void merge(int u, int v)
{
	int pu=find(u);
	int pv=find(v);
	if (r[pu] < r[pv])
		p[pu] = pv;
	else
		p[pv] = pu;
	if (r[pu] == r[pv])
		r[pv]++;
}
int main()
{
	int t, n, m, u, v, i;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
		{
			r[i] = 0;
			p[i] = i;
			num[i] = 0;
		}
		for (i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);
			merge(u-1, v-1);
		}
		for (i = 0; i < n; i++)
			find(i);
		for (i = 0; i < n; i++)
			num[p[i]]++;
		m = 0;
		for (i = 0; i < n; i++)
			m = Max(m, num[i]);
		printf("%d\n", m);
	}
	return 0;
}
