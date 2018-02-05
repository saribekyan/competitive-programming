#include <cstdio>

int d[202][202];
FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
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
			for (k = m+1; i+k <= n+1 && j+k <= n+1; k++)
				if (d[i+k-1][j+k-1]-d[i+k-1][j-1]-d[i-1][j+k-1]+d[i-1][j-1] == 0)
					m = k;
	fprintf(fout, "%d\n", m);
	return 0;
}