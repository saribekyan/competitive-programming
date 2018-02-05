/*
PROG: nocows
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int d[201][101];
FILE* fin = fopen("nocows.in", "r");
FILE* fout = fopen("nocows.out", "w");
int main()
{
	int n, k, i, j, l;
	fscanf(fin, "%d%d", &n, &k);
	for (i = 0; i <= n; i++)
		for (j = 0; j <= k; j++)
			d[i][j] = 0;
	for (i = 0; i <= k; i++)
		d[1][i] = 1;
	for (i = 2; i <= k; i++)
		for (l = 0; l <= n; l++)
		{
			j = 0;
			while (l+j+1 <= n)
			{
				d[l+j+1][i] = (d[l+j+1][i]+d[l][i-1]*d[j][i-1]+99010)%9901;
				j++;
			}
		}
	fprintf(fout, "%d\n", (d[n][k]-d[n][k-1]+9901)%9901);
	return 0;
}