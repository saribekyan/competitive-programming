/*
PROG: mnoteb
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int b[110];
int main()
{
	freopen("mnoteb.in", "r", stdin);
	freopen("mnoteb.out", "w", stdout);
	int n, m, p, t, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", b+i);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &t);
		for (j = p = 0; j < n && p <= t; j++)
			p += b[j];
		printf("%d\n", j);
	}
	return 0;
}
