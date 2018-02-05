/*
PROG: range
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int g[250][250], d[251][251];
FILE* fin = fopen("range.in", "r");
FILE* fout = fopen("range.out", "w");
int main()
{
	char c;
	int n, i, j, k, count;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fgetc(fin);
		for (j = 0; j < n; j++)
		{
			fscanf(fin, "%c", &c);
			g[i][j] = c-'0';
		}
	}
	for (i = 0; i <= n; i++)
		d[i][0] = d[0][i] = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			d[i][j] = d[i][j-1]+d[i-1][j]-d[i-1][j-1]+g[i-1][j-1];
	for (k = 2; k <= n; k++)
	{
		count = 0;
		for (i = 1; i+k-1 <= n; i++)
			for (j = 1; j+k-1 <= n; j++)
				if (d[k+i-1][k+j-1]-d[i-1][k+j-1]-d[k+i-1][j-1]+d[i-1][j-1] == k*k)
					count++;
		if (count == 0)return 0;
		fprintf(fout, "%d %d\n", k, count);
	}
	return 0;
}