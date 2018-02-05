#include <stdio.h>
#include <limits.h>
#define MAX 100
int d[MAX][MAX], path[MAX][MAX];

void print_path(int i, int j)
{
	if (i!=j)
		print_path(i,path[i][j]);
	printf("%d ", j+1);
}

int main()
{
	int i, j, k, u, v, n, w;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			d[i][j] = INT_MAX/2;
			path[i][j] = i;
		}
	while (1)
	{
		scanf("%d%d%d", &u, &v, &w);
		d[u-1][v-1] = w;
		if (feof(stdin))
			break;
	}
	for (i = 0; i < n; i++)
		d[i][i] = 0;
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					path[i][j] = path[k][j];
				}
	scanf("%d%d", &u, &v);
	printf("%d\n", d[u-1][v-1]);
	print_path(u-1, v-1);
	putchar('\n');
	return 0;
}