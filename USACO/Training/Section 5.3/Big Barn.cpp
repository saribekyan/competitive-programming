/*
PROG: bigbrn
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int d[1001][1001];
FILE* fin = fopen("bigbrn.in", "r");
FILE* fout = fopen("bigbrn.out", "w");
int main()
{
	int n, m, i, j, k;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i <= n; i++)
		for (j = 0; j <= n; j++)
			d[i][j] = 0;
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%d%d", &k, &j);
		d[k][j] = 1;
	}
	for (i = 2; i <= n; i++)
	{
		d[1][i] += d[1][i-1];
		d[i][1] += d[i-1][1];
	}
	for (i = 2; i <= n; i++)
		for (j = 2; j <= n; j++)
			d[i][j] += d[i-1][j]+d[i][j-1]-d[i-1][j-1];
	m = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			k = m+1;
			if (d[i][j]-d[i][j-k]-d[i-k][j]+d[i-k][j-k] == 0 && i >= k && j >= k)
				m = k;
		}
	fprintf(fout, "%d\n", m);
	return 0;
}