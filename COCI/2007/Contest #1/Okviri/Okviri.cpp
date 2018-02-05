#include <cstdio>
#include <string.h>

char d[5][75], s[16];
FILE* fin = fopen("okviri.in", "r");
FILE* fout = fopen("okviri.out", "w");
int main()
{
	int n, i, j;
	fscanf(fin, "%s", s);
	n = strlen(s);
	d[2][0] = '#';
	for (i = 0; i < 5; i++)
		for (j = 0; j <= 4*n; j++)
			d[i][j] = '.';
	d[2][0] = '#';
	for (i = 0; i < n; i++)
	{
		d[2][i*4+2] = s[i];
		if (i%3)
			d[2][i*4] = '#';
		if (i%3 != 2)
			d[1][i*4+1] = d[0][i*4+2] = d[1][i*4+3] = d[2][i*4+4] = d[3][i*4+3] = d[4][i*4+2] = d[3][i*4+1] = '#';
		else
			d[2][i*4] = d[1][i*4+1] = d[0][i*4+2] = d[1][i*4+3] = d[2][i*4+4] = d[3][i*4+3] = d[4][i*4+2] = d[3][i*4+1] = '*';
	}
	for (i = 0; i < 5; i++)
		fprintf(fout, "%s\n", d[i]);
	return 0;
}
