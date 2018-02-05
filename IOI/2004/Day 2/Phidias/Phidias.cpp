#include <stdio.h>

int d[610][610];
int main()
{
	int n, m, k, i, j;
	scanf("%d%d%d", &n, &m, &k);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			d[i][j] = i*j;
	while (k--)
	{
		scanf("%d%d", &i, &j);
		d[i][j] = 0;
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			for (k = 1; (k<<1) <= i; k++)
				if (d[i][j] > d[k][j]+d[i-k][j])
					d[i][j] = d[k][j]+d[i-k][j];
			for (k = 1; (k<<1) <= j; k++)
				if (d[i][j] > d[i][k]+d[i][j-k])
					d[i][j] = d[i][k]+d[i][j-k];
		}
	printf("%d\n", d[n][m]);
	return 0;
}
