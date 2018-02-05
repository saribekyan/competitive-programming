#include <stdio.h>
#define MOD (98765431LL)

typedef long long LL;
LL a[50010];
LL degree(LL a, LL n)
{
	if (n == 1)
		return a;
	LL x=degree(a,n/2);
	x = (x*x)%MOD;
	if (n%2)
		return (x*a)%MOD;
	return x;
}
void ext_euc(LL a, LL b, LL &x, LL &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	LL x1, y1;
	ext_euc(b, a%b, x1, y1);
	x = y1;
	y = (x1-(a/b)*y1+MOD*MOD)%MOD;
}
int main()
{
	LL n, t, s=0, m, k, b1, i;
	scanf("%lld%lld", &n, &t);
	for (i = 0; i < n; i++)
	{
		scanf("%lld", a+i);
		s = (s+a[i])%MOD;
	}
	ext_euc(MOD, n, k, b1);
	if (t%2)
		m = (((degree(n-1, t)+1)%MOD)*b1+MOD*MOD)%MOD;
	else
		m = (((degree(n-1, t)-1+MOD)%MOD)*b1+MOD*MOD)%MOD;
	for (i = 0; i < n; i++)
		if (t%2)
			printf("%lld\n", (s*m-a[i]+MOD)%MOD);
		else
			printf("%lld\n", (s*m+a[i])%MOD);
	return 0;
}
