#include <stdio.h>
#include <string.h>

int n, m;
int b[2010][210], s[2010][210];
int d[2010][2010][2][2], it[2][2];
void solve()
{
	int l, t, w, p, q, i, j;
	for (i = 1; i <= n; i++)
		d[i][i][0][1] = s[i][m];
	for (i = 2; i <= n; i++)
		if (d[i][i][0][1] > d[i-1][i-1][0][1]+b[i][1]+b[i][m])
			d[i][i][0][1] = d[i-1][i-1][0][1]+b[i][1]+b[i][m];
	for (i = n-1; i > 0; i--)
		if (d[i][i][0][1] > d[i+1][i+1][0][1]+b[i][1]+b[i][m])
			d[i][i][0][1] = d[i+1][i+1][0][1]+b[i][1]+b[i][m];
	for (i = 1; i <= n; i++)
	{
		d[i][i][1][0] = d[i][i][0][1];
		d[i][i][0][0] = b[i][1];
		d[i][i][1][1] = b[i][m];
	}

	for (l = 1; l <= n; l++)
		for (i = 1; i+l <= n; i++)
		{
			p = 1;
			q = m;
			j = i+l;
			for (t = 0; t < 2; t++)
			{
				if (l == 1)
				{
					it[t][t] = b[i][p]+b[j][p];
					it[t][t^1] = d[i][i][t][t^1]+b[j][q];
					w = d[j][j][t][t^1]+b[i][p];
					if (it[t][t^1] > w)
						it[t][t^1] = w;
				}
				else
				{
					it[t][t] = d[i+1][j][t][t]+b[i][p];
					w = d[i][j-1][t][t]+b[j][p];
					if (it[t][t] > w)
						it[t][t] = w;
					w = d[i][j-1][t][t^1]+d[j][j][t^1][t];
					if (it[t][t] > w)
						it[t][t] = w;

					it[t][t^1] = d[i+1][j][t][t^1]+b[i][p];
					w = d[i][j-1][t][t^1]+b[j][q];
					if (it[t][t^1] > w)
						it[t][t^1] = w;
					w = d[i][i][t][t^1]+d[i+1][j][t^1][t^1];
					if (it[t][t^1] > w)
						it[t][t^1] = w;
				}
				d[j][i][t][t] = it[t][t];
				d[j][i][t^1][t] = it[t][t^1];
				p = m;
				q = 1;
			}
			memcpy(d[i][j], it, sizeof(it));
		}
}
int main()
{
	long long ans = 0;
	int w, t, p, q, u, v, i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			scanf("%d", b[i]+j);
			s[i][j] = s[i][j-1]+b[i][j];
		}
	solve();
	p = q = 1;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%d", &u, &v);
		if (n)
			ans -= b[u][v];
		if (p == u)
		{
			if (q > v)
			{
				i = v;
				j = q;
			}
			else
			{
				i = q;
				j = v;
			}
			w = s[p][j]-s[p][i-1];
			t = d[p][p][0][1]+s[p][i]-s[p][1]+s[p][m-1]-s[p][j-1];
			if (w > t)
				w = t;
		}
		else
		{
			w = s[p][q]-s[p][1]+d[p][u][0][0]+s[u][v]-s[u][1];
			t = s[p][q]-s[p][1]+d[p][u][0][1]+s[u][m-1]-s[u][v-1];
			if (w > t)
				w = t;
			t = s[p][m-1]-s[p][q-1]+d[p][u][1][0]+s[u][v]-s[u][1];
			if (w > t)
				w = t;
			t = s[p][m-1]-s[p][q-1]+d[p][u][1][1]+s[u][m-1]-s[u][v-1];
			if (w > t)
				w = t;
		}
		ans += w;
		p = u;
		q = v;
	}
	printf("%lld\n", ans);
	return 0;
}
