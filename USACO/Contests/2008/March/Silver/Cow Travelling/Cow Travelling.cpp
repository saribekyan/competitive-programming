#include <stdio.h>
#include <string.h>

char s[110][110];
int d[20][110][110];
int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};
int main()
{
	freopen("ctravel.in", "r", stdin);
	freopen("ctravel.out", "w", stdout);
	int n, m, t, k, l, p, q, i, j;
	scanf("%d%d%d", &n, &m, &t);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);
	scanf("%d%d", &i, &j);
	memset(d, 0, sizeof(d));
	d[0][i-1][j-1] = 1;
	for (l = 1; l <= t; l++)
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				for (k = 0; k < 4; k++)
				{
					p = i+di[k];
					q = j+dj[k];
					if (p >= 0 && p < n && q >= 0 && q < m && s[p][q] == '.')
						d[l][i][j] += d[l-1][p][q];
				}
	scanf("%d%d", &i, &j);
	printf("%d\n", d[t][i-1][j-1]);
	return 0;
}
