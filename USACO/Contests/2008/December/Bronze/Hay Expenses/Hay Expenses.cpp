/*
PROG: hayexp
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int a[510];
int main()
{
	freopen("hayexp.in", "r", stdin);
	freopen("hayexp.out", "w", stdout);
	int n, m, s, p, q, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", a+i);
	for (i = 0; i < m; i++)
	{
		s = 0;
		scanf("%d%d", &p, &q);
		for (j = p-1; j < q; j++)
			s += a[j];
		printf("%d\n", s);
	}
	return 0;
}
