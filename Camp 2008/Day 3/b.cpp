#include <stdio.h>
#include <string.h>
#define MOD 1000000007

int d[2][2010][2010];
char a[2010], b[2010];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, i, j;
	scanf("%s%s", a+1, b+1);
	n = strlen(a+1);
	m = strlen(b+1);
	for (i = 0; i <= n; i++)
	{
		d[0][i][0] = i;
		d[1][i][0] = 1;
	}
	for (j = 0; j <= m; j++)
	{
		d[0][0][j] = j;
		d[1][0][j] = 1;
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (a[i] == b[j])
			{
				d[0][i][j] = d[0][i-1][j-1]+1;
				d[1][i][j] = d[1][i-1][j-1];
			}
			else
			{
				if (d[0][i-1][j] < d[0][i][j-1])
				{
					d[0][i][j] = d[0][i-1][j]+1;
					d[1][i][j] = d[1][i-1][j];
				}
				if (d[0][i-1][j] > d[0][i][j-1])
				{
					d[0][i][j] = d[0][i][j-1]+1;
					d[1][i][j] = d[1][i][j-1];
				}
				if (d[0][i-1][j] == d[0][i][j-1])
				{
					d[0][i][j] = d[0][i-1][j]+1;
					d[1][i][j] = (d[1][i-1][j]+d[1][i][j-1])%MOD;
				}
			}
	printf("%d\n", d[1][n][m]);
	return 0;
}
