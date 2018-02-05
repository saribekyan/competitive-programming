#include <stdio.h>
#define inf 1000000000.0

int n;
int f[1010];
int e[20010][2];
double w[20010];
int g[1010][1010];

double d[2010];
bool check(double k)
{
	int m=0, i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (g[i][j])
			{
				e[m][0] = (i<<1)|1;
				e[m][1] = j<<1;
				w[m++] = g[i][j];
			}
	for (i = 0; i < n; i++)
	{
		e[m][0] = i<<1;
		e[m][1] = e[m][0]|1;
		w[m++] = -f[i]/k;
	}
	for (i = 0; i < n; i++)
		d[i] = inf;
	for (i = 0; i+1 < n; i++)
		for (j = 0; j < m; j++)
			if (d[e[j][1]] > d[e[j][0]]+w[j])
				d[e[j][1]] = d[e[j][0]]+w[j];
	for (i = 0; i < m; i++)
		if (d[e[i][1]] > d[e[i][0]]+w[i])
			return 1;
	return 0;
}
int main()
{
	freopen("sightsee.in", "r", stdin);
	freopen("sightsee.out", "w", stdout);
	double l, r, k;
	int m, p, q, t, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", f+i);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &p, &q, &t);
		if (g[p-1][q-1] == 0 || g[p-1][q-1] > t)
			g[p-1][q-1] = t;
	}
	l = 0.0;
	r = 1000.0;
	for (i = 0; i < 30; i++)
	{
		k = (l+r)/2.0;
		if (check(k))
			l = k;
		else
			r = k;
	}
	printf("%.2lf\n", k);
	return 0;
}
