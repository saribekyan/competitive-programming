/*
PROG: badgras
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int n, m;
int d[1010][1010];
int st[2][1000010];
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void flood(int i, int j)
{
	int l=0, k;
	d[i][j] = 0;
	st[0][l] = i;
	st[1][l++] = j;
	while (l)
	{
		i = st[0][--l];
		j = st[1][l];
		for (k = 0; k < 8; k++)
			if (d[i+di[k]][j+dj[k]])
			{
				st[0][l] = i+di[k];
				st[1][l++] = j+dj[k];
				d[i+di[k]][j+dj[k]] = 0;
			}
	}
}
int main()
{
	freopen("badgras.in", "r", stdin);
	freopen("badgras.out", "w", stdout);
	int p=0, i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", d[i]+j);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (d[i][j])
			{
				flood(i, j);
				p++;
			}
	printf("%d\n", p);
	return 0;
}
