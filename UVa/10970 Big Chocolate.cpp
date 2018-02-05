#include <stdio.h>
#define MAX 1000
int d[MAX][MAX];

int main()
{
	int i, j, n, m;
	for (i = 0; i < MAX; i++)d[0][i]=d[i][0]=i;
	for (i = 1; i < MAX; i++)
		for (j = 1; j < MAX; j++)
			d[i][j]=d[i-1][j]+d[0][j]+1;
	while (scanf("%d%d", &n, &m)==2)printf("%d\n", d[n-1][m-1]);
	return 0;
}