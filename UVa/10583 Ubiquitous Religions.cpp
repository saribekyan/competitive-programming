#include <stdio.h>

int r[50010], p[50010];
int find(int u)
{
	if (u != p[u])
		p[u] = find(p[u]);
	return p[u];
}
void merge(int u, int v)
{
	int a=find(u);
	int b=find(v);
	if (a == b)
		return;
	if (r[a] < r[b])
		p[a] = b;
	else
		p[b] = a;
	if (r[a] == r[b])
		r[b]++;
}
bool t[50010];
int main()
{
	long long m, i;
	int l=1, n, u, v;
	while (scanf("%d%lld", &n, &m) && (n || m))
	{
		for (i = 0; i < n; i++)
		{
			r[i] = 0;
			p[i] = i;
			t[i] = 0;
		}
		for (i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);
			merge(u-1, v-1);
		}
		for (i = 0; i < n; i++)
			t[find(i)] = 1;
		u = 0;
		for (i = 0; i < n; i++)
			u += t[i];
		printf("Case %d: %d\n", l++, u);
	}
	return 0;
}
