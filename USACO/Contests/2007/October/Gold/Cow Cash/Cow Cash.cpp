/*
PROG: money2
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

long long d[10010];
int main()
{
	freopen("money2.in", "r", stdin);
	freopen("money2.out", "w", stdout);
	long long n, m, p, i;
	scanf("%lld%lld", &m, &n);
	d[0] = 1;
	while (m--)
	{
		scanf("%lld", &p);
		for (i = 0; i+p <= n; i++)
			d[i+p] += d[i];
	}
	printf("%lld\n", d[n]);
	return 0;
}
