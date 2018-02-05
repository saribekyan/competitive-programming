#include <stdio.h>
#include <limits.h>
#define MAX 20

int d[MAX][MAX];

int main()
{
	int i, j, k, l, c, u, v;
	l = 1;
	while (1)
	{
		for (i = 0; i < MAX; i++)
			for (j = 0; j < MAX; j++)
				d[i][j] = INT_MAX/2;
		for (i = 0; i < MAX; i++)
			d[i][i] = 0;
		scanf("%d", &k);
		if (feof(stdin)) break;
		for (i = 1; i < MAX; i++)
		{			
			if (i != 1) scanf("%d", &k);
			u = i;
			for (j = 0; j < k; j++)
			{
				scanf("%d", &v);
				d[u-1][v-1] = 1;
				d[v-1][u-1] = 1;
			}
		}
		for (k = 0; k < MAX; k++)
			for (i = 0; i < MAX; i++)
				for (j= 0; j < MAX; j++)
					if (d[i][k] + d[k][j] < d[i][j]) 
						d[i][j] = d[i][k] + d[k][j];
		scanf("%d", &c);
		printf("Test Set #%d\n", l);
		for (i = 0; i < c; i++)
		{
			scanf("%d%d", &u, &v);
			printf("%2d to %2d: %d\n", u, v, d[u-1][v-1]);
		}
		putchar('\n');
		l++;
	}
	return 0;
}