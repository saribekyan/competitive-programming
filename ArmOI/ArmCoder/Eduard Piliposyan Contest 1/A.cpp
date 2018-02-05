#include <stdio.h>

int main()
{
	long long n, mod, d[2], b[2], x, y, i;
	scanf("%lld%lld", &n, &mod);
	d[0] = 0;
	b[0] = 2%mod;
	d[1] = 1;
	b[1] = 2%mod;
	for (i = 2; i < n; i++)
	{
		x = (d[1]*b[0]+d[0])%mod;
		y = (b[0]*b[1])%mod;
		d[0] = d[1];
		d[1] = x;
		b[0] = b[1];
		b[1] = y;
	}
	printf("%lld\n", d[1]);
	return 0;
}
