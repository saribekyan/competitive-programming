/*
PROG: smrtfun
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define Max(a, b) ((a)>(b)?(a):(b))

int d[2][200110];
int s[110], f[110];
int main()
{
	freopen("smrtfun.in", "r", stdin);
	freopen("smrtfun.out", "w", stdout);
	int n, sw, m, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", s+i, f+i);
	sw = 0;
	for (i = 0; i <= 2001*n; i++)
		d[sw][i] = -1001*n;
	d[sw][1001*n] = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= 2001*n; j++)
			d[sw^1][j] = -1001*n;
		for (j = 0; j <= 2001*n; j++)
			if (d[sw][j] != -1001*n)
			{
				d[sw^1][j] = Max(d[sw^1][j], d[sw][j]);
				d[sw^1][j+s[i]] = Max(d[sw^1][j+s[i]], d[sw][j]+f[i]);
			}
		sw ^= 1;
	}
	m = 0;
	for (i = 1001*n; i <= 2001*n; i++)
		if (d[sw][i] >= 0)
			m = Max(m, i-1001*n+d[sw][i]);
	printf("%d\n", m);
	return 0;
}
