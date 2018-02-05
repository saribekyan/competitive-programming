#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))

long long n, m;
long long p[510], d[510], s[510], a[510];
void mul()
{
	long long j, k;
	memset(s, 0, sizeof(s));
	for (j = 0; j < n; j++)
		for (k = 0; k < n; k++)
			s[j] = (s[j]+d[k]*p[(j-k+n)%n])%m;
	memcpy(d, s, sizeof(s));
}
void pow(long long k)
{
	long long i;
	for (i = 30; i >= 0 && !(k&(1<<i)); i--);
	memcpy(d, a, sizeof(a));
	for (i--; i >= 0; i--)
	{
		memcpy(p, d, sizeof(d));
		mul();
		if (k&(1<<i))
		{
			memcpy(p, a, sizeof(a));
			mul();
		}
	}
}
int main()
{
	long long ds, k, i;
	while (scanf("%lld%lld%lld%lld", &n, &m, &ds, &k) == 4)
	{
		memset(a, 0, sizeof(a));
		for (i = 0; i < n; i++)
			if (Min(i, n-i) <= ds)
				a[i] = 1;
		pow(k);
		for (i = 0; i < n; i++)
			scanf("%d", p+i);
		memset(a, 0, sizeof(a));
		for (i = 0; i < n; i++)
			for (k = 0; k < n; k++)
				a[i] = (a[i]+d[(k-i+n)%n]*p[k])%m;
		for (i = 0; i < n-1; i++)
			printf("%lld ", a[i]);
		printf("%lld\n", a[i]);
	}
	return 0;
}
