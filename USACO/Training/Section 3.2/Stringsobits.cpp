/*
PROG: kimbits
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int c[32][32], d[32][32];
FILE* fin = fopen("kimbits.in", "r");
FILE* fout = fopen("kimbits.out", "w");
int main()
{
	long long m;
	int n, l, i, j, k;
	fscanf(fin, "%d%d%lld", &n, &l, &m);
	for (i = 0; i <= n; i++)
		c[i][i] = c[i][0] = 1;
	for (i = 1; i <= n; i++)
		for (j = 1; j < i; j++)
			c[i][j] = c[i-1][j-1]+c[i-1][j];
	for (i = 0; i <= n; i++)
		for (j = 0; j <= n; j++)
			for (k = 0; k <= j; k++)
				d[i][j] += c[i][k];
	for (i = n-1; i >= 0; i--)
	{
		if (m > d[i][l])
		{
			fputc('1', fout);
			l--;
			m -= d[i][l+1];
		}
		else
			fputc('0', fout);
	}
	fputc('\n', fout);
	return 0;
}