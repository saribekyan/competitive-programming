#include <cstdio>

bool d[500][500];
int main()
{
	int n, m, p, x1, y1, x2, y2, i, j, k;
	while (scanf("%d%d%d", &m, &n, &p) && (n || m || p))
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				d[i][j] = 0;
		for (i = 0; i < p; i++)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x1 < x2)
			{
				if (y1 > y2)
				{
					y1 ^= y2;
					y2 ^= y1;
					y1 ^= y2;
				}
			}
			else
				if (y1 < y2)
				{
					x1 ^= x2;
					x2 ^= x1;
					x1 ^= x2;
				}
				else
				{
					x1 ^= x2;
					x2 ^= x1;
					x1 ^= x2;
					y1 ^= y2;
					y2 ^= y1;
					y1 ^= y2;
				}
			for (j = y1-1; j < y2; j++)
				for (k = x1-1; k < x2; k++)
					d[j][k] = 1;
		}
		p = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (!d[i][j])
					p++;
		if (p == 0)printf("There is no empty spots.\n");
		if (p == 1)printf("There is one empty spot.\n");
		if (p > 1)printf("There are %d empty spots.\n", p);
	}
	return 0;
}