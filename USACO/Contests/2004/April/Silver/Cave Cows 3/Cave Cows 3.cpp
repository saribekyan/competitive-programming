#include <stdio.h>
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

int main()
{
	freopen("cavecow3.in", "r", stdin);
	freopen("cavecow3.out", "w", stdout);
	int n, x, y, p, q, u, v;
	scanf("%d", &n);
	p = u = -1000000000;
	q = v = -p;
	while (n--)
	{
		scanf("%d%d", &x, &y);
		p = Max(p, x+y);
		q = Min(q, x+y);
		u = Max(u, x-y);
		v = Min(v, x-y);
	}
	printf("%d\n", Max(p-q, u-v));
	return 0;
}
