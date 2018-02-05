/*
PROG: dice
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

int d[2][35][20];
double a[2][2][1030];
int main()
{
	freopen("dice.in", "r", stdin);
	freopen("dice.out", "w", stdout);
	int n[2], m[2], sw, p, q, l, i, j, k;
	for (l = 0; l < 2; l++)
	{
		scanf("%d%d", n+l, m+l);
		for (i = 0; i < n[l]; i++)
			for (j = 0; j < m[l]; j++)
				scanf("%d", d[l][i]+j);
		sw = 0;
		a[l][sw][0] = 1;
		for (i = 1; i <= 1024; i++)
			a[l][sw][i] = 0.0;
		for (i = 0; i < n[l]; i++)
		{
			for (j = 0; j <= 1024; j++)
				a[l][sw^1][j] = 0.0;
			for (j = 0; j < m[l]; j++)
				for (k = 0; k <= 1024-d[l][i][j]; k++)
					a[l][sw^1][k+d[l][i][j]] += a[l][sw][k]/m[l];
			sw ^= 1;
		}
	}
	p = q = 0;
	for (i = 0; i <= 1024; i++)
	{
		p += (a[0][n[0]&1][i] > 0);
		q += (a[1][n[1]&1][i] > 0);
	}
	if (p != q)
	{
		printf("N N\n%d %d\n", p, q); 
		return 0;
	}
	for (i = 0; i <= 1024; i++)
		if (a[0][n[0]&1][i] > 0 && a[1][n[1]&1][i] == 0.0 || a[0][n[0]&1][i] == 0.0 && a[1][n[1]&1][i] > 0)
			break;
	if (i <= 1024)
	{
		printf("N N\n%d %d\n", p, q);
		return 0;
	}
	for (i = 0; i <= 1024; i++)
		if (fabs(a[0][n[0]&1][i]-a[1][n[1]&1][i]) > (1e-9))
			break;
	if (i == 1025)
		printf("Y Y\n%d %d\n", p, q);
	else
		printf("Y N\n%d %d\n", p, q);
	return 0;
}
