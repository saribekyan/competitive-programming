#include <stdio.h>
#include <string.h>
#define inf 1000000000

int numv[1010];
int g[110][110];
int d[21][110][110];

int dp[2][110];

int main()
{
	freopen("relays.in", "r", stdin);
	freopen("relays.out", "w", stdout);
	int len, n, m, s, e, p, q, l, i, j, k;
	scanf("%d%d%d%d", &len, &m, &s, &e);
	memset(numv, -1, sizeof(numv));
	n = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &l, &p, &q);
		if (numv[p] != -1)
			p = numv[p];
		else
			p = numv[p] = n++;
		if (numv[q] != -1)
			q = numv[q];
		else
			q = numv[q] = n++;
		if (g[p][q] == 0 || g[p][q] > l)
			g[p][q] = g[q][p] = l;
	}
	s = numv[s];
	e = numv[e];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (g[i][j] == 0)
				g[i][j] = inf;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			d[0][i][j] = g[i][j];
	for (l = 1; (1<<l) <= len; l++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				d[l][i][j] = inf;
	for (l = 1; (1<<l) <= len; l++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				for (k = 0; k < n; k++)
					if (d[l][i][j] > d[l-1][i][k]+d[l-1][k][j])
						d[l][i][j] = d[l-1][i][k]+d[l-1][k][j];
	k = 0;
	for (i = 0; i < n; i++)
		if (i == s)
			dp[k][i] = 0;
		else
			dp[k][i] = inf;
	for (l = 0; (1<<l) <= len; l++)
		if ((len>>l)&1)
		{
			for (i = 0; i < n; i++)
				dp[k^1][i] = inf;
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if (dp[k^1][j] > dp[k][i]+d[l][i][j])
						dp[k^1][j] = dp[k][i]+d[l][i][j];
			k ^= 1;
		}
	printf("%d\n", dp[k][e]);
	return 0;
}
