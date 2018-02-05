/*
PROG: fristeam
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#define MOD 100000000

int r[2010];
int d[2010][1010];
int main()
{
	freopen("fristeam.in", "r", stdin);
	freopen("fristeam.out", "w", stdout);
	int n, f, i, j;
	scanf("%d%d", &n, &f);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", r+i);
		r[i] %= f;
	}
	d[0][0] = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < f; j++)
		{
			d[i+1][(j+r[i+1])%f] = (d[i+1][(j+r[i+1])%f]+d[i][j])%MOD;
			d[i+1][j] = (d[i+1][j]+d[i][j])%MOD;
		}
	printf("%d\n", d[n][0]-1);
	return 0;
}
