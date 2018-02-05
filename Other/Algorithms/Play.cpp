// Okulov, p.202, 4.11, pr.1
#include <stdio.h>
#define MAX 50
int G[MAX][MAX], C[MAX], p, ans[MAX], V[MAX], n, k;
void play(int u, int v)
{
	int i;
	if (u==p-1||v==p-1)
	{
		for (i = 0; i < k; i++)
			printf("%d->%d\n", V[i], ans[i]);
		putchar('\n');
	}
	for (i = 0; i < n; i++)
	{
		if (G[u][i]==C[v])
		{			
			ans[k] = i+1;
			V[k] = 1;
			k++;
			play(i, v);
			k--;
			ans[k] = V[k] = 0;
		}
		if (G[v][i]==C[u])
		{			
			ans[k] = i+1;
			V[k] = 2;
			k++;
			play(u, i);
			k--;
			ans[k] = V[k] = 0;
		}
	}
}
int main()
{
	int m, i, u, v, g, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &C[i]);
		ans[i] = V[i] = 0;
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			G[i][j] = 7;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &g);
		G[u-1][v-1]=g;
	}
	scanf("%d%d%d", &u, &v, &p);
	k = 0;
	play(u-1, v-1);
	return 0;
}
/*
6 5
1 2 3 4 5 6
1 2 4
1 3 2
2 4 3
3 5 4
4 6 5
1 2 6
*/