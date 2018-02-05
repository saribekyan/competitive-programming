#include <stdio.h>
#define Min(a, b) ((a)<(b)?(a):(b))

int m[2510];
int d[2510];
int main()
{
	freopen("river.in", "r", stdin);
	freopen("river.out", "w", stdout);
	int n, i, j;
	scanf("%d%d", &n, m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", m+i);
		m[i] += m[i-1];
	}
	d[0] = m[0];
	for (i = 1; i <= n; i++)
	{
		d[i] = m[i];
		for (j = 1; j < i; j++)
			d[i] = Min(d[i], d[j]+m[0]+d[i-j]);
	}
	printf("%d\n", d[n]);
	return 0;
}
