/*
PROG: buyhay
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#define inf 1000000000
#define Min(a, b) ((a)<(b)?(a):(b))

int d[60010];
int main()
{
	freopen("buyhay.in", "r", stdin);
	freopen("buyhay.out", "w", stdout);
	int n, m, p, c, i;
	scanf("%d%d", &n, &m);
	d[0] = 0;
	for (i = 1; i <= m+5010; i++)
		d[i] = inf;
	while (n--)
	{
		scanf("%d%d", &p, &c);
		for (i = 0; i <= m; i++)
			d[i+p] = Min(d[i+p], d[i]+c);
	}
	p = inf;
	for (i = m; i <= m+5010; i++)
		p = Min(p, d[i]);
	printf("%d\n", p);
	return 0;
}
