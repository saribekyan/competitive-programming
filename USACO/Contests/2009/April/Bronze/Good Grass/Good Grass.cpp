/*
PROG: goodgrs
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int d[110][110];
int main()
{
	freopen("goodgrs.in", "r", stdin);
	freopen("goodgrs.out", "w", stdout);
	int n, m, p, q, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", d[i]+j);
	for (p = q = i = 0; i+2 < n; i++)
		for (j = 0; j+2 < m; j++)
			if (d[i][j]+d[i][j+1]+d[i][j+2]+
				d[i+1][j]+d[i+1][j+1]+d[i+1][j+2]+
				d[i+2][j]+d[i+2][j+1]+d[i+2][j+2] >
				d[p][q]+d[p][q+1]+d[p][q+2]+
				d[p+1][q]+d[p+1][q+1]+d[p+1][q+2]+
				d[p+2][q]+d[p+2][q+1]+d[p+2][q+2])
			{
				p = i;
				q = j;
			}
	printf("%d\n%d %d\n", d[p][q]+d[p][q+1]+d[p][q+2]+
				d[p+1][q]+d[p+1][q+1]+d[p+1][q+2]+
				d[p+2][q]+d[p+2][q+1]+d[p+2][q+2], p+1, q+1);
	return 0;
}
