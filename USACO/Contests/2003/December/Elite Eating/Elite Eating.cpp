/*
PROG: elite
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>

int d[2][26][10010];
int main()
{
	freopen("elite.in", "r", stdin);
	freopen("elite.out", "w", stdout);
	int n, m, s, sw, i, j, k;
	scanf("%d%d", &n, &s);
	sw = 0;
	d[sw][0][0] = 1;
	for (i = 1; i <= 100; i++)
	{
		memset(d[sw^1], 0, sizeof(d[sw^1]));
		for (j = 0; j <= n; j++)
			for (k = 0; k <= s; k++)
			{
				d[sw^1][j][k] += d[sw][j][k];
				if (j < n && k+i*i <= s)
					d[sw^1][j+1][k+i*i] += d[sw][j][k];
			}
		sw ^= 1;
	}
	m = 0;
	for (i = 0; i < s; i++)
		m += d[sw][n][i];
	printf("%d\n", m);
	return 0;
}
