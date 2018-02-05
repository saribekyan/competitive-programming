#include <stdio.h>
#define MAX 100
int d[MAX+2][MAX+2], max, m;

void rec(int i, int j, int m)
{
	if (d[i-1][j]<d[i][j])
		rec(i-1, j, m+1);
	if (d[i][j-1]<d[i][j])
		rec(i, j-1, m+1);
	if (d[i+1][j]<d[i][j])
		rec(i+1, j, m+1);
	if (d[i][j+1]<d[i][j])
		rec(i, j+1, m+1);
	if (max<m)
		max = m;
}

int main()
{
	int R, C, N, l, i, j;
	char c[255];
	scanf("%d", &N);
	for (l = 0; l < N; l++)
	{
		scanf("%s%d%d", c, &R, &C);
		for (i = 0; i <= R+1; i++)
			d[i][0] = d[i][C+1] = 1000;
		for (j = 0; j <= C+1; j++)
			d[0][j] = d[R+1][j] = 1000;
        for (i = 1; i <= R; i++)
			for (j = 1; j <= C; j++)
				scanf("%d", &d[i][j]);
		max = 0;
		for (i = 1; i <= R; i++)
			for (j = 1; j <= C; j++)
				rec(i, j, 1);
		printf("%s: %d\n", c, max);
	}
	return 0;
}