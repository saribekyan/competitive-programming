#include <stdio.h>

long long c[10010], y[10010];
int main()
{
	freopen("yogfac.in", "r", stdin);
	freopen("yogfac.out", "w", stdout);
	int n, s, i, j;
	long long ans, p, q;
	scanf("%d%d", &n, &s);
	ans = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%lld%lld", c+i, y+i);
		p = c[i]*y[i];
		for (j = 0; j < i; j++)
		{
			q = y[i]*(c[j]+(i-j)*s);
			if (p > q)
				p = q;
		}
		ans += p;
	}
	printf("%lld\n", ans);
	return 0;
}
