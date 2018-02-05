/*
PROG: bestspot
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#define inf 1000000000
#define Min(a, b) ((a)<(b)?(a):(b))

int f[510];
int d[510][510];
int main()
{
	freopen("bestspot.in", "r", stdin);
	freopen("bestspot.out", "w", stdout);
	int n, m, p, w, i, j, k;
	scanf("%d%d%d", &n, &p, &m);
	for (i = 0; i < p; i++)
	{
		scanf("%d", f+i);
		f[i]--;
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i != j)
				d[i][j] = inf;
	for (k = 0; k < m; k++)
	{
		scanf("%d%d%d", &i, &j, &w);
		d[i-1][j-1] = d[j-1][i-1] = w;
	}
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				d[i][j] = Min(d[i][j], d[i][k]+d[k][j]);
	k = -1;
	m = inf;
	for (i = 0; i < n; i++)
	{
		w = 0;
		for (j = 0; j < p; j++)
			w += d[i][f[j]];
		if (m > w)
		{
			m = w;
			k = i;
		}
	}
	printf("%d\n", k+1);
	return 0;
}
