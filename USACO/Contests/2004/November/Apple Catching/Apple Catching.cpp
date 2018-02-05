/*
PROG: bcatch
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#define Max(a, b) ((a)>(b)?(a):(b))

int t[1010];
int d[2][35][2];
int main()
{
	freopen("bcatch.in", "r", stdin);
	freopen("bcatch.out", "w", stdout);
	int n, m, i, j, k, l, sw;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", t+i);
		t[i]--;
	}
	l = 0;
	sw = 0;
	memset(d, -1, sizeof(d));
	d[0][0][sw] = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= m; j++)
			for (k = 0; k < 2; k++)
				if (d[k][j][sw] != -1)
				{
					d[k][j][sw^1] = Max(d[k][j][sw^1], d[k][j][sw]);
					if (t[i+1] == k)
						d[k][j][sw^1] = Max(d[k][j][sw^1], d[k][j][sw]+1);
					else
					{
						if (j < m)
							d[1^k][j+1][sw^1] = Max(d[1^k][j+1][sw^1], d[k][j][sw]+1);
						d[k][j][sw^1] = Max(d[k][j][sw^1], d[k][j][sw]);
					}
					l = Max(l, d[k][j][sw]);
				}
		sw ^= 1;
	}
	for (j = 0; j <= m; j++)
		for (k = 0; k < 2; k++)
			l = Max(l, d[k][j][sw]);
	printf("%d\n", l);
	return 0;
}
