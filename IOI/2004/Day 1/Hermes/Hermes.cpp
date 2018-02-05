#include <stdio.h>
#include <math.h>
#define Min(a, b) ((a)<(b)?(a):(b))

int x[20010], y[20010];
int a[2][20010], b[2][20010];
int main()
{
	int m, n, p, q, sw, i, j;
	scanf("%d", &n);
	x[0] = y[0] = 0;
	for (i = 1; i <= n; i++)
		scanf("%d%d", x+i, y+i);
	for (i = 0; i <= n; i++)
	{
		a[0][i] = abs(y[i]);
		b[0][i] = abs(x[i]);
	}
	for (sw = i = 0; i < n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			a[1-sw][j] = Min(a[sw][j]+abs(x[i]-x[i+1]), b[sw][i+1]+abs(y[i]-y[j]));
			b[1-sw][j] = Min(b[sw][j]+abs(y[i]-y[i+1]), a[sw][i+1]+abs(x[i]-x[j]));
		}
		sw = 1-sw;
	}
	m = 1000000000;
	for (i = 0; i <= n; i++)
		m = Min(m, Min(a[sw][i], b[sw][i]));
	printf("%d\n", m);
	return 0;
}
