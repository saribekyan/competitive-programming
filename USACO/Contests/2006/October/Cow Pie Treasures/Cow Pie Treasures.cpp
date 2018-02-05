/*
PROG: pie1
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#define Max(a, b) ((a)>(b)?(a):(b))

int p[110][110];
int d[110][110];
int main()
{
	freopen("pie1.in", "r", stdin);
	freopen("pie1.out", "w", stdout);
	int n, m, i, j, k;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", p[i]+j);
	memset(d, -1, sizeof(d));
	d[0][0] = p[0][0];
	for (j = 0; j < m-1; j++)
		for (i = 0; i < n; i++)
			if (d[i][j] != -1)
				for (k = -1; k <= 1; k++)
					if (i+k >= 0 && i+k < n)
						d[i+k][j+1] = Max(d[i+k][j+1], d[i][j]+p[i+k][j+1]);
	printf("%d\n", d[n-1][m-1]);
	return 0;
}
