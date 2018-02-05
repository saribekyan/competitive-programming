/*
PROG: numtri
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#define MAX 1000

int d[MAX][MAX];
FILE* fin = fopen("numtri.in", "r");
FILE* fout = fopen("numtri.out", "w");
int main()
{
	int n, i, j;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			fscanf(fin, "%d", &d[i][j]);
	for (i = n-2; i >= 0; i--)
		for (j = 0; j <= i; j++)
			if (d[i+1][j] > d[i+1][j+1])
				d[i][j] += d[i+1][j];
			else
				d[i][j] += d[i+1][j+1];
	fprintf(fout, "%d\n", d[0][0]);
	return 0;
}