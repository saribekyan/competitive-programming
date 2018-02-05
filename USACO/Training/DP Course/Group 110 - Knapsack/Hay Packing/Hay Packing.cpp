/*
PROG: packhay
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

bool d[5010];
int main()
{
	freopen("packhay.in", "r", stdin);
	freopen("packhay.out", "w", stdout);
	int n, m, v, i, j;
	scanf("%d%d", &m, &n);
	d[0] = 1;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &v);
		for (j = m-v; j >= 0; j--)
			d[j+v] = d[j+v] || d[j];
	}
	for (i = m; i >= 0 && !d[i]; i--);
	printf("%d\n", i);
	return 0;
}
