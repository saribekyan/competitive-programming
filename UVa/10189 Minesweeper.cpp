#include <stdio.h>
#define MAX 100
int d[MAX+1][MAX+1];
char c;
int dx[8]={-1, 0, 1,-1,1,-1,0,1};
int dy[8]={-1,-1,-1, 0,0, 1,1,1};
int main()
{
	int n,m,i,j,k,u,v,l=1;
	while (scanf("%d%d", &n, &m)&&(n||m))
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)d[i][j]=0;
		for (i = 0; i < n; i++)
		{
			scanf("%c", &c);
			for (j = 0; j < m; j++)
			{
				scanf("%c", &c);
				if (c=='*')
				{
					d[i][j]=-1;
					for (k = 0; k < 8; k++)
					{
						u=i+dx[k];
						v=j+dy[k];
						if (u>=0&&u<n&&v>=0&&v<m&&d[u][v]!=-1)
							d[u][v]++;
					}
				}
			}
		}
		printf("Field #%d:\n", l);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				if (d[i][j]==-1)putchar('*');
				else printf("%d", d[i][j]);
			putchar('\n');
		}
		l++;
	}
	return 0;
}