#include <stdio.h>
#define MOD (1000000007LL)

long long d[200010];
int main()
{
	long long n, m=0, a, i;
	scanf("%lld", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &a);
		if (d[a] == 0)
			m++;
		d[a]++;
	}
	a = 1;
	for (i = 1; i <= n-m; i++)
		a = (a*i)%MOD;
	for (i = 1; i <= n; i++)
		if (d[i])
			a = (a*d[i])%MOD;
	printf("%lld\n", a);
	return 0;
}
