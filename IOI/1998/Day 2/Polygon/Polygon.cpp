#include <stdio.h>
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

int d[110];
char s[110];
int dp[2][110][110];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, m, i, j, k, l;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%c%c %d", s+i, s+i, d+i);
		s[i+n] = s[i];
		d[i+n] = d[i];
	}
	for (i = 0; i < 2*n; i++)
		for (j = 0; j < 2*n; j++)
		{
			dp[0][i][j] = -1000000000;
			dp[1][i][j] = -dp[0][i][j];
		}
	for (i = 0; i < 2*n; i++)
		dp[0][i][i] = dp[1][i][i] = d[i];
	for (l = 1; l < n; l++)
		for (i = 0; i < 2*n-l; i++)
		{
			j = i+l;
			for(k = i+1; k <= j; k++)
				if (s[k] == 't')
				{
					dp[0][i][j] = Max(dp[0][i][j], dp[0][i][k-1]+dp[0][k][j]);
					dp[1][i][j] = Min(dp[1][i][j], dp[1][i][k-1]+dp[1][k][j]);
				}
				else
				{
					dp[0][i][j] = Max(dp[0][i][j], Max(dp[0][i][k-1]*dp[0][k][j], dp[1][i][k-1]*dp[1][k][j]));
					dp[1][i][j] = Min(dp[1][i][j], Min(dp[1][i][k-1]*dp[1][k][j], dp[0][i][k-1]*dp[0][k][j]));
					dp[1][i][j] = Min(dp[1][i][j], Min(dp[1][i][k-1]*dp[0][k][j], dp[0][i][k-1]*dp[1][k][j]));
				}
		}
	m = -1000000000;
	for (l = i = 0; i < n; i++)
	{
		if (m < dp[0][i][i+n-1])
		{
			m = dp[0][i][i+n-1];
			l = 0;
		}
		if (m == dp[0][i][i+n-1])
			d[l++] = i+1;
	}
	printf("%d\n", m);
	for (i = 0; i < l-1; i++)
		printf("%d ", d[i]);
	printf("%d\n", d[i]);
	return 0;
}
