/*
PROG: ppairing
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int d[100010];
int main()
{
	freopen("ppairing.in", "r", stdin);
	freopen("ppairing.out", "w", stdout);
	int n, c, p, i, j;
	scanf("%d%d", &n, &c);
	for (n = i = 0; i < c; i++)
	{
		scanf("%d", &p);
		for (j = 0; j < p; j++)
			d[n++] = i+1;
	}
	for (i = 0; 2*i < n; i++)
		printf("%d %d\n", d[i], d[i+n/2]);
	return 0;
}
