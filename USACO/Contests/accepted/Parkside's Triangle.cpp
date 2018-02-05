#include <cstdio>
int d[20][20];
FILE* fin = fopen("pktri1.in", "r");
FILE* fout = fopen("pktri1.out", "w");
int main()
{
	int n, m, i, j;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
		{
			d[j][i] = m++;
			if (m == 10)
				m = 1;
		}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2*i; j++)
			fputc(' ', fout);
		for (j = i; j < n-1; j++)
			fprintf(fout, "%d ", d[i][j]);
		fprintf(fout, "%d\n", d[i][n-1]);
	}
	return 0;
}