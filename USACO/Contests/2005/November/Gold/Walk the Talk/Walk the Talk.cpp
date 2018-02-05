#include <stdio.h>
#include <string.h>

char s[10];
char b[40][40];
int d[40][40][10];
int main()
{
	FILE *dict = fopen("dict.txt", "r");
	long long ans = 0;
	int n, m, t, l, k, i, j;
	scanf("%d%d", &n, &m);
	for (i = n; i >= 1; i--)
		scanf("%s", b[i]+1);
	ans = 0;
	for (t = 0; t < 2265; t++)
	{
		fscanf(dict, "%s", s+1);
		l = strlen(s+1);
		for (i = 0; i <= n; i++)
			for (j = 0; j <= m; j++)
				d[i][j][0] = 1;
		for (k = 1; k <= l; k++)
			for (i = 1; i <= n; i++)
				for (j = 1; j <= m; j++)
				{
					d[i][j][k] = d[i-1][j][k]+d[i][j-1][k]-d[i-1][j-1][k];
					if (s[k] == b[i][j])
						d[i][j][k] += d[i-1][j][k-1]+d[i][j-1][k-1]-d[i-1][j-1][k-1];
				}
		ans += d[n][m][l];
	}
	printf("%lld\n", ans);
	return 0;
}
