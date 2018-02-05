/*
PROG: palpath
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>

int a[21][21];
int d[3][21][21][21][21];
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main()
{
	freopen("palpath.in", "r", stdin);
	freopen("palpath.out", "w", stdout);
	int n, m, sw, t, i, j, p, q, k, l, x, y, u, v;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", a[i]+j);
	sw = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			d[1][i][j][i][j] = 1;
			for (k = 0; k < 8; k++)
			{
				p = i+di[k];
				q = j+dj[k];
				if (p >= 0 && p < n && q >= 0 && q < n)
					d[2][i][j][p][q] = (a[i][j] == a[p][q]);
			}
		}
	for (t = 3; t <= m; t++)
	{
		memset(d[t%3], 0, sizeof(d[t%3]));
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				for (p = 0; p < n; p++)
					for (q = 0; q < n; q++)
						if (a[i][j] == a[p][q])
							for (k = 0; k < 8; k++)
							{
								x = i+di[k];
								y = j+dj[k];
								if (x >= 0 && x < n && y >= 0 && y < n)
									for (l = 0; l < 8; l++)
									{
										u = p+di[l];
										v = q+dj[l];
										if (u >= 0 && u < n && v >=0 && v < n)
											d[t%3][i][j][p][q] += d[(t-2)%3][x][y][u][v];
									}
							}
	}
	t = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				for (l = 0; l < n; l++)
					t += d[m%3][i][j][k][l];
	printf("%d\n", t);
	return 0;
}
