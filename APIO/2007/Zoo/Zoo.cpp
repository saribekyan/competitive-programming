/*
PROG: zoo
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>

int n;
int d[2][32];
int e[50010], f[50010][6], l[50010][6];
bool happy(int c, int s)
{
	int i;
	for (i = 0; f[c][i] != -1; i++)
		if ((s&(1<<(4-f[c][i]+e[c]))) == 0)
			return 1;
	for (i = 0; l[c][i] != -1; i++)
		if (s&(1<<(4-l[c][i]+e[c])))
			return 1;
	return 0;
}
bool check(int p, int t, int s)
{
	if (p > 4 && p+4 <= n)
		return 1;
	if (p <= 4)
	{
		if (p == 0)
			return (t&15) == s;
		return (s&((1<<(5-p))-1)) == (t>>p);
	}
	return (t&((1<<(4-n+p))-1)) == (s>>(n-p));
}
int main()
{
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	int ans, m, s, sw, p, q, t, u, x, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", e+i, &p, &q);
		for (j = 0; j < p; j++)
		{
			scanf("%d", f[i]+j);
			if (f[i][j] < e[i])
				f[i][j] += n;
		}
		f[i][j] = -1;
		for (j = 0; j < q; j++)
		{
			scanf("%d", l[i]+j);
			if (l[i][j] < e[i])
				l[i][j] += n;
		}
		l[i][j] = -1;
	}
	ans = 0;
	for (s = 0; s < 16; s++)
	{
		p = 0;
		sw = 0;
		memset(d[sw], 0, sizeof(d[sw]));
		for (i = 0; i < n; i++)
		{
			q = p;
			memset(d[sw^1], 0, sizeof(d[sw^1]));
			for (t = 0; t < 32; t++)
				if (check(i, t, s))
				{
					u = (t&(15))<<1;
					if (check(i+1, u, s))
					{
						x = d[sw][t];
						for (q = p; q < m && e[q] == i+1; q++)
							x += happy(q, u);
						if (d[sw^1][u] < x)
							d[sw^1][u] = x;
					}
					u |= 1;
					if (check(i+1, u, s))
					{
						x = d[sw][t];
						for (q = p; q < m && e[q] == i+1; q++)
							x += happy(q, u);
						if (d[sw^1][u] < x)
							d[sw^1][u] = x;
					}
				}
			p = q;
			sw ^= 1;
		}
		for (t = 0; t < 32; t++)
			if (ans < d[sw][t])
				ans = d[sw][t];
	}
	printf("%d\n", ans);
	return 0;
}
