#include <stdio.h>
#define MAX 24
int d[MAX][MAX+1];
char c[5],w[5];

void onto(int u, int v)
{
	int i, n;
	n = d[u][0];
	for (i=v+1; i<=n; i++)
	{
		d[ d[u][i] ][0]++;
		d[ d[u][i] ][ d[ d[u][i] ][0] ]=d[u][i];
		d[u][0]--;
		
	}
}

void pile(int u, int v, int p)
{
	int i, n;
	n = d[u][0];
	for (i=v; i<=n; i++)
	{
		d[p][0]++;
		d[p][ d[p][0] ]=d[u][i];
		d[u][0]--;
	}
}
void move(int u, int v, int p)
{
	d[p][0]++;
	d[p][ d[p][0] ]=d[u][v];	
	d[u][0]--;
}
int main()
{
	int n, i, a, b, j, u, v, p, q;
	while (scanf("%d", &n)==1)
	{
		for (i=0; i<n; i++){d[i][0]=1;d[i][1]=i;}
		while (scanf("%s", c)&&c[0]!='q')
		{
			scanf("%d%s%d", &a, w, &b);
			if (a!=b)
			{
				for (i=0; i<n; i++)
					for (j=1; j<=d[i][0]; j++)				
					{
						if (d[i][j]==a){ u=i;v=j; }
						if (d[i][j]==b){ p=i;q=j; }
					}
				if (u!=p)
				{
					if (c[0]=='m')
					{
						onto(u, v);
						if (w[1]=='n') onto(p,q);
						move(u,v,p);
					}
					if (c[0]=='p')
					{
						if (w[1]=='n') onto(p,q);
						pile(u,v,p);
					}
				}
			}
		}
		for (i=0; i<n; i++)
		{
			printf("%d:", i);
			for (j=1; j<=d[i][0]; j++) printf(" %d", d[i][j]);
			putchar('\n');
		}
	}
	return 0;
}