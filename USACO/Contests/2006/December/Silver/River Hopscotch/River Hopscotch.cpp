#include <cstdio>
#include <algorithm>
using namespace std;

int n, l;
int c[50010];
int d[50010];
int can(int k)
{
	if (l < k)
		return 1000000010;
	int i;
	int *I;
	d[0] = 0;
	for (i = 1; i <= n; i++)
	{
		I = upper_bound(c, c+n+1, c[i]-k);
		if (c[i]-c[i-1] >= k)
			d[i] = d[i-1];
		else
			d[i] = d[i-1]+1;
		if (I != c)
			d[i] = min(d[i], d[I-c-1]+i-(I-c));
	}
	I = upper_bound(c, c+n+1, l-k);
	if (I == c)
		return 1000000010;
	return d[I-c-1]+n+1-(I-c);
}
int main()
{
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	int m, p, q, k, i;
	scanf("%d%d%d", &l, &n, &m);
	c[0] = 0;
	for (i = 1; i <= n; i++)
		scanf("%d", c+i);
	sort(c+1, c+n+1);
	p = 1;
	q = 1000000000;
	while (q-p > 1)
	{
		k = ((q+p)>>1);
		if (can(k) > m)
			q = k;
		else
			p = k;
	}
	if (can(q) <= m)
		printf("%d\n", q);
	else
		printf("%d\n", p);
	return 0;
}
