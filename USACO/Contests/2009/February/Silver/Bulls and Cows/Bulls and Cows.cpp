/*
PROG: bullcow
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#define MOD 5000011

int d[100010];
int main()
{
	freopen("bullcow.in", "r", stdin);
	freopen("bullcow.out", "w", stdout);
	int n, k, i;
	scanf("%d%d", &n, &k);
	for (i = 0; i <= n; i++)
		if (i <= k)
			d[i] = i+1;
		else
			d[i] = (d[i-1]+d[i-k-1])%MOD;
	printf("%d\n", d[n]);
	return 0;
}
