#include <stdio.h>

int d[1000];
int edge[10000][3];
int main()
{
	int n, m, s, p, q, i, j;
	scanf("%d%d%d", &n, &m, &s);
	for (i = 0; i < m; i++)
		scanf("%d%d%d", edge[i], edge[i]+1, edge[i]+2);
	for (i = 0; i < n; i++)
		d[i] = 123456789;
	d[s] = 0;
	for (i = 0; i < n-1; i++)
		for (j = 0; j < m; j++)
			if (d[edge[j][1]] > d[edge[j][0]]+edge[j][2])
				d[edge[j][1]] = d[edge[j][0]]+edge[j][2];
	for (i = 0; i < n; i++)
		printf("%d ", d[i]);
	putchar('\n');
	return 0;
}
