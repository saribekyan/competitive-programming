#include <stdio.h>
#include <string.h>
#define MOD (1000000000LL)

long long d[1000010];
int main()
{
	freopen("sumset.in", "r", stdin);
	freopen("sumset.out", "w", stdout);
	int n, i, j;
	scanf("%d", &n);
	memset(d, 0, sizeof(d));
	d[0] = 1;
	for (i = 0; i < 20; i++)
		for (j = 0; j <= n; j++)
			if (j+(1<<i) <= n)
				d[j+(1<<i)] = (d[j+(1<<i)]+d[j])%MOD;
	printf("%lld\n", d[n]);
	return 0;
}
