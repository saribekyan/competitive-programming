/*
TASK:diamonds
LANG:C
*/
#include <stdio.h>

int d[110][110][110];
int main()
{
	int n, m, l, i, j, k, p, q, r;
	scanf("%d%d%d", &l, &m, &n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			for (k = 1; k <= l; k++)
			{
				scanf("%d", d[i][j]+k);
				d[i][j][k] += d[i][j][k-1]+d[i][j-1][k]+d[i-1][j][k]-d[i][j-1][k-1]-d[i-1][j][k-1]-d[i-1][j-1][k]+d[i-1][j-1][k-1];
			}
	while (scanf("%d%d%d%d%d%d", &k, &j, &i, &r, &q, &p) == 6)
		printf("%d\n", d[p][q][r]-d[p][q][k]-d[p][j][r]-d[i][q][r]+d[i][j][r]+d[i][q][k]+d[p][j][k]-d[i][j][k]);
	return 0;
}
