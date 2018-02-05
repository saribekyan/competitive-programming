#include <stdio.h>

typedef long long LL;
LL x[5010], y[5010], p[5010], q[5010];
int main()
{
	LL n, m, r, d, i, j;
	scanf("%lld%lld%lld", &m, &n, &r);
	for (i = 0; i < m; i++)
		scanf("%lld%lld", p+i, q+i);
	for (i = 0; i < n; i++)
		scanf("%lld%lld", x+i, y+i);
	for (i = 0; i < m; i++)
	{
		d = 0;
		for (j = 0; j < n; j++)
			d += ((x[j]-p[i])*(x[j]-p[i])+(y[j]-q[i])*(y[j]-q[i]) <= r*r);
		printf("%lld\n", d);
	}
	return 0;
}
