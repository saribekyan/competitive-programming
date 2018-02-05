#include <stdio.h>
#define inf 1000000000

int a[20][20], d[20][20], w[20][20];
int main()
{
	int ans, n, m, p, q, s, l, k, i, j;
	scanf("%d%d%d%d", &n, &m, &p, &q);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			scanf("%d", a[i]+j);
			a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	ans = inf;
	for (s = 0; s < (1<<(n-1)); s++)
	{
		for (k = i = 0; i+1 < n; i++)
			k += (s>>i)&1;
		if (k == p)
		{
			for (i = 0; i <= m; i++)
				for (j = 0; j <= q; j++)
					d[i][j] = inf;
			for (i = 1; i <= m; i++)
				for (j = i; j <= m; j++)
				{
					l = 1;
					w[i][j] = 0;
					for (k = 0; k < n; k++)
						if ((s>>k)&1)
						{
							if (w[i][j] < a[k+1][j]-a[k+1][i-1]-a[l-1][j]+a[l-1][i-1])
								w[i][j] = a[k+1][j]-a[k+1][i-1]-a[l-1][j]+a[l-1][i-1];
							l = k+2;
						}
					if (w[i][j] < a[n][j]-a[n][i-1]-a[l-1][j]+a[l-1][i-1])
						w[i][j] = a[n][j]-a[n][i-1]-a[l-1][j]+a[l-1][i-1];
				}
			for (i = 1; i <= m; i++)
				d[i][0] = w[1][i];
			for (i = 1; i <= q; i++)
				for (j = i+1; j <= m; j++)
					for (k = i; k < j; k++)
					{
						if (d[k][i-1] > w[k+1][j] && d[j][i] > d[k][i-1])
							d[j][i] = d[k][i-1];
						if (d[k][i-1] <= w[k+1][j] && d[j][i] > w[k+1][j])
							d[j][i] = w[k+1][j];
					}
			if (ans > d[m][q])
				ans = d[m][q];
		}
	}
	printf("%d\n", ans);
	return 0;
}
