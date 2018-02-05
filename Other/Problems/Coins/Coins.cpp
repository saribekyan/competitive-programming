#include <stdio.h>
#define Min(a, b) ((a)<(b)?(a):(b))

int three(int n)
{
	int p=1, i;
	for (i = 0; p < n; i++)
		p *= 3;
	return i;
}
int d[2][5000010];
int main()
{
	int n, k, sw, m, i, j;
	scanf("%d%d", &n, &k);
	if (k >= three(n))
	{
		printf("%d\n", three(n));
		return 0;
	}
	sw = 0;
	d[sw][0] = 1;
	for (i = 1; d[sw][i-1] <= n; i++)
		d[sw][i] = (i<<1)|1;
	m = n>>1;
	for (i = 2; i <= k; i++)
	{
		d[sw^1][0] = 1;
		for (j = 1; d[sw^1][j-1] <= n; j++)
			d[sw^1][j] = d[sw^1][j-1]+(d[sw][j-1]<<1);
		sw ^= 1;
		for (j = 0; d[sw][j+1]; j++)
			if (d[sw][j] < n && n <= d[sw][j+1])
				m = Min(m, j+1);
	}
	printf("%d\n", m);
	return 0;
}
