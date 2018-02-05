#include <stdio.h>

int t[1010][6];
int d[1010][1010];
int main()
{
	freopen("camp.in", "r", stdin);
	freopen("camp.out", "w", stdout);
	int n, m, p, ai, aj, am, s, a, b, s1, s2, x1, y1, x2, y2, i, j, k;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			scanf("%d", d[i]+j);
			d[i][j] += d[i-1][j]+d[i][j-1]-d[i-1][j-1];
		}
	scanf("%d%d%d", &a, &b, &p);
	for (i = 0; i < p; i++)
		for (j = 0; j < 6; j++)
			scanf("%d", t[i]+j);
	am = ai = aj = 0;
	for (i = 1; i+a <= n+1; i++)
		for (j = 1; j+b <= m+1; j++)
		{
			for (s = k = 0; k < p && s+p-k > am; k++)
			{
				x1 = i+t[k][0]-1;
				y1 = j+t[k][1]-1;
				x2 = x1+t[k][2]-1;
				y2 = y1+t[k][3]-1;
				s1 = d[x2][y2]-d[x2][y1-1]-d[x1-1][y2]+d[x1-1][y1-1];
				if (t[k][4] == 0)
				{
					y1 += t[k][3];
					y2 += t[k][3];
				}
				else
				{
					x1 += t[k][2];
					x2 += t[k][2];
				}
				s2 = d[x2][y2]-d[x2][y1-1]-d[x1-1][y2]+d[x1-1][y1-1];
				if (t[k][5] == 0 && s1 < s2 || t[k][5] && s1 >= s2)
					s++;
			}
			if (s > am)
			{
				am = s;
				ai = i;
				aj = j;
			}
		}
	printf("%d %d\n", ai, aj);
	return 0;
}
