#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))

short n, m, l;
bool found;
bool t[1050];
short way[1050];
short g[1050][1050];
short d[1010][21], s[21];
short g1[1050][1001], deg[1050];
void dfs(short p)
{
	if (p == n+m+1)
	{
		found = 1;
		return;
	}
	short i;
	for (i = 0; i < deg[p]; i++)
		if (!t[g1[p][i]] && g[p][g1[p][i]])
		{
			t[g1[p][i]] = 1;
			way[l++] = g1[p][i];
			dfs(g1[p][i]);
			if (found)
				return;
			l--;
		}
}
short flow()
{
	short ret=0, p, i;
	way[0] = 0;
	while (1)
	{
		l = 1;
		found = 0;
		memset(t, 0, sizeof(t));
		t[0] = 1;
		dfs(0);
		if (!found)
			return ret;
		p = 30000;
		for (i = 0; i < l-1; i++)
			p = Min(p, g[way[i]][way[i+1]]);
		for (i = 0; i < l-1; i++)
		{
			g[way[i]][way[i+1]] -= p;
			g[way[i+1]][way[i]] += p;
		}
		ret += p;
	}
	return -1;
}
int main()
{
	freopen("stead.in", "r", stdin);
	freopen("stead.out", "w", stdout);
	short p, i, j, k, r;
	scanf("%hd%hd", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%hd", d[i]+j);
	for (i = 0; i < m; i++)
		scanf("%hd", s+i);
	p = m;
	for (j = 1; j <= n; j++)
	{
		g1[0][deg[0]++] = j;
		g1[j][deg[j]++] = 0;
	}
	for (j = n+1; j <= n+m; j++)
	{
		g1[j][deg[j]++] = n+m+1;
		g1[n+m+1][deg[n+m+1]++] = j;
	}
	for (i = 0; i < m; i++)
	{
		deg[0] = n;
		for (j = 1; j <= n+m; j++)
			deg[j] = 1;
		deg[n+m+1] = m;
		for (j = i; j < m; j++)
			if (j+1 < p+i)
			{
				for (k = 1; k <= n; k++)
					g[0][k] = 1;
				for (k = n+1; k <= n+m; k++)
					g[k][n+m+1] = s[k-n-1];
				for (k = 0; k < n; k++)
				{
					for (r = i; r <= j; r++)
						g[k+1][n+d[k][r]] = 1;
					g1[k+1][deg[k+1]++] = n+d[k][j];
					g1[n+d[k][j]][deg[n+d[k][j]]++] = k+1;
				}
				if (flow() >= n)
					p = Min(p, j-i+1);
			}
	}
	printf("%hd\n", p);
	return 0;
}
