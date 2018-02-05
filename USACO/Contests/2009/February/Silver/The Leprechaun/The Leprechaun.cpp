/*
PROG: lepr
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#define inf 1000000

int n;
int a[210];
int d[210][210];
int di[4] = {1, 0, 1, -1};
int dj[4] = {0, 1, 1, 1};
int solve()
{
	int s, p, i, j;
	p = 0;
	s = -inf;
	for (i = 0; i < n; i++)
	{
		p += a[i];
		if (s < p)
			s = p;
		if (p < 0)
			p = 0;
	}
	p = a[0];
	for (i = 0, j = n; i+1 != j;)
	{
		if (p+a[i+1] <= 0 && p+a[j-1] <= 0)
			break;
		if (p+a[i+1] > 0)
			p += a[++i];
		else
			p += a[--j];
		if (s < p)
			s = p;
	}
	return s;
}
int main()
{
	freopen("lepr.in", "r", stdin);
	freopen("lepr.out", "w", stdout);
	int s, m, i, j, k, l;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", d[i]+j);
	m = -inf;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < 4; k++)
			{
				for (l = 0; l < n; l++)
					a[l] = d[(i+l*di[k]+n)%n][(j+l*dj[k]+n)%n];
				s = solve();
				if (s > m)
					m = s;
			}
	printf("%d\n", m);
	return 0;
}
