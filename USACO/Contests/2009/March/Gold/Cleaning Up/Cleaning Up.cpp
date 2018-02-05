/*
PROG: cleanup
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int ind[210];
int a[40010];
int d[40010];
int last[40010];
int main()
{
	freopen("cleanup.in", "r", stdin);
	freopen("cleanup.out", "w", stdout);
	int n, p, m, i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", a+i);
	for (p = 1; p*p < n; p++);
	d[1] = 1;
	last[a[1]] = 1;
	for (i = 0; i <= p; i++)
		ind[i] = 1;
	for (i = 2; i <= n; i++)
	{
		d[i] = i;
		ind[0] = i;
		for (j = p; j > 0; j--)
			if (last[a[i]] < ind[j])
				ind[j] = ind[j-1];
		last[a[i]] = i;
		for (j = 1; j <= p; j++)
			if (d[i] > d[ind[j]-1]+j*j)
				d[i] = d[ind[j]-1]+j*j;
	}
	printf("%d\n", d[n]);
	return 0;
}
