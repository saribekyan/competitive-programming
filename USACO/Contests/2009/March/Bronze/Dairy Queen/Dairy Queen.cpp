/*
PROG: dq
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int d[310];
int main()
{
	freopen("dq.in", "r", stdin);
	freopen("dq.out", "w", stdout);
	int n, m, c, i, j;
	scanf("%d%d", &n, &m);
	d[0] = 1;
	for (i = 0; i < m; i++)
	{
		scanf("%d", &c);
		for (j = 0; j+c <= n; j++)
			d[j+c] += d[j];
	}
	printf("%d\n", d[n]);
	return 0;
}
