/*
PROG: psolve
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#define inf 1000000000

int m;
int d[310][310];
int a[310], b[310];
int solve(int p, int q)
{
	int &it = d[p][q];
	if (it != -1)
		return it;
	if (p == 1 && a[q] <= m && b[q] <= m)
		return it = 3;
	if (a[q]-a[p-1] > m || b[q]-b[p-1] > m)
		return it = inf;
	int i;
	it = inf;
	for (i = p-1; i >= 1; i--)
		if (it > solve(i, p-1)+2)
			it = d[i][p-1]+2;
	for (i = p-1; i >= 1 && a[q]-a[p-1]+b[p-1]-b[i-1] <= m; i--)
		if (it > solve(i, p-1)+1)
			it = d[i][p-1]+1;
	return it;
}
int main()
{
	freopen("psolve.in", "r", stdin);
	freopen("psolve.out", "w", stdout);
	int n, p, q, i;
	scanf("%d%d", &m, &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &p, &q);
		a[i] = a[i-1]+p;
		b[i] = b[i-1]+q;
	}
	p = inf;
	memset(d, -1, sizeof(d));
	for (i = 1; i <= n; i++)
		if (p > solve(i, n))
			p = d[i][n];
	printf("%d\n", p);
	return 0;
}
