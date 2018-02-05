/*
PROG: baying
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

long long d[4000010];
int main()
{
	freopen("baying.in", "r", stdin);
	freopen("baying.out", "w", stdout);
	int n, c, p1, p2, i;
	long long a1, b1, d1, a2, b2, d2, x, y;
	scanf("%d%d", &c, &n);
	scanf("%lld%lld%lld", &a1, &b1, &d1);
	scanf("%lld%lld%lld", &a2, &b2, &d2);
	d[0] = c;
	p1 = p2 = 0;
	for (i = 1; i < n; i++)
	{
		x = b1+a1*d[p1]/d1;
		y = b2+a2*d[p2]/d2;
		if (x < y)
		{
			d[i] = x;
			p1++;
		}
		else
		{
			d[i] = y;
			p2++;
		}
		if (x == y)
			p1++;
	}
	printf("%lld\n", d[n-1]);
	return 0;
}
