#include <stdio.h>
#define Min(a, b) ((a)<(b)?(a):(b))

int n;
int t[25010];
int d[15][25010];

void buildRMQ()
{
	int i, j, l;
	t[0] = -1;
	for (i = 1; i <= n; i++)
		if (i&(i-1))
			t[i] = t[i-1];
		else
			t[i] = t[i-1]+1;
	for (l = i = 1; i <= t[n]; i++, l<<=1)
		for (j = 1; (l<<1)+j <= n+1; j++)
			d[i][j] = Min(d[i-1][j], d[i-1][j+l]);
}
int minVal(int x, int y)
{
	int l=t[y-x+1];
	return Min(d[l][x], d[l][y-(1<<l)+1]);
}
int main()
{
	freopen("cavecow2.in", "r", stdin);
	freopen("cavecow2.out", "w", stdout);
	int m, x, y, i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", d[0]+i);
	buildRMQ();
	while (m--)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", minVal(x, y));
	}
	return 0;
}
