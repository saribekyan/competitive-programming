#include <stdio.h>
#define NMAX 100
int d[NMAX+1][NMAX+1], a[NMAX+1], b[NMAX+1];

int main()
{
	int n, m, i, j, l=1;
	while (scanf("%d%d", &n, &m) && n || m)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < m; i++)
			scanf("%d", &b[i]);
		for (i = 0; i <= n; i++)
			for (j = 0; j <= m; j++)
				d[i][j] = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				if (a[i-1]==b[j-1])
					d[i][j]=d[i-1][j-1]+1;
				else
				{
					if (d[i-1][j]>d[i][j-1])
						d[i][j]=d[i-1][j];
					else
						d[i][j]=d[i][j-1];
				}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n", l, d[n][m]);
		l++;
	}
	return 0;
}