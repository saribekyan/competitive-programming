/*
PROG: lookup
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int h[100010], d[100010];
int main()
{
	freopen("lookup.in", "r", stdin);
	freopen("lookup.out", "w", stdout);
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", h+i);
	d[n-1] = 0;
	for (i = n-2; i >= 0; i--)
	{
		for (j = i+1; j && h[i] >= h[j]; j = d[j]);
		d[i] = j;
	}
	for (i = 0; i < n; i++)
		if (d[i])
			printf("%d\n", d[i]+1);
		else
			printf("0\n");
	return 0;
}
