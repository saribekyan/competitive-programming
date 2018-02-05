#include <stdio.h>
#define MAX 50
int d[MAX][MAX], n;
int dx[8] = {-2, -2, -1, -1,  1, 1,  2, 2};
int dy[8] = {-1,  1, -2,  2, -2, 2, -1, 1};
int horse(int x, int y)
{
	int i, j, c=0, min, m, a, b;
	min = 10;
	for (i = 0; i < 8; i++)
		if (x+dx[i]>=0&&x+dx[i]<n&&y+dy[i]>=0&&y+dy[i]<n&&d[x+dx[i]][y+dy[i]]==0)
		{
			m = 0;
			for (j = 0; j < 8; j++)
				if (x+dx[i]+dx[j]>=0&&x+dx[i]+dx[j]<n&&y+dy[i]+dy[j]>=0&&y+dy[i]+dy[j]<n&&d[x+dx[i]+dx[j]][y+dy[i]+dy[j]]==0)
					m++;
			if (m<min){min=m; a = x+dx[i]; b = y+dy[i];}
		}
	if (min!=10)
	{
		d[a][b] = d[x][y]+1;
		c+=horse(a, b);
	}
	if (c==0&&d[x][y]!=n*n){d[x][y] = 0; return 0;}
	return 1;
}
int main()
{
	int x, y, i, j;
	scanf("%d%d%d", &n, &x, &y);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			d[i][j] = 0;
	d[x-1][y-1] = 1;
	horse(x-1, y-1);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%5d", d[i][j]);
		printf("\n\n");
	}
	return 0;
}