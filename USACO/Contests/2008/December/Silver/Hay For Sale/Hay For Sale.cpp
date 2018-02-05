/*
PROG: hay4sale
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

bool d[50010];
int main()
{
	freopen("hay4sale.in", "r", stdin);
	freopen("hay4sale.out", "w", stdout);
	int n, m, v, i, j;
	scanf("%d%d", &m, &n);
	d[0] = 1;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &v);
		for (j = m-v; j >= 0; j--)
			d[j+v] |= d[j];
	}
	for (i = m; i >= 0; i--)
		if (d[i])
			break;
	printf("%d\n", i);
	return 0;
}
