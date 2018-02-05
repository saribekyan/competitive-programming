#include <stdio.h>

int d[101][100];
int main()
{
	int n, m, p, i, j, k;
	while (scanf("%d", &n) == 1)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				scanf("%d", &p);
				d[i+1][j] = d[i][j]+p;
			}
		m = 0;
		for (i = 0; i < n; i++)
			for (j = i+1; j <= n; j++)
			{
				p = 0;
				for (k = 0; k < n; k++)
				{
					if (p+d[j][k]-d[i][k] > 0)
						p += d[j][k]-d[i][k];
					else
						p = 0;
					if (m < p)
						m = p;
				}
			}
		printf("%d\n", m);
	}
	return 0;
}