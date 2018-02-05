#include <cstdio>

int d[10][10];
FILE* fin = fopen("solitair.in", "r");
FILE* fout = fopen("solitair.out", "w");
int main()
{
	char c;
	int n, i, j;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			fgetc(fin);
			fscanf(fin, "%c", &c);
			if (c >= '2' && c <= '9')
				d[i][j] = c-'0';
			if (c == 'A')
				d[i][j] = 1;
			if (c == 'T')
				d[i][j] = 10;
			if (c == 'J')
				d[i][j] = 11;
			if (c == 'Q')
				d[i][j] = 12;
			if (c == 'K')
				d[i][j] = 13;
			fgetc(fin);
		}
	for (i = n-2; i >= 0; i--)
		d[i][0] += d[i+1][0];
	for (i = 1; i < n; i++)
		d[n-1][i] += d[n-1][i-1];
	for (i = n-2; i >= 0; i--)
		for (j = 1; j < n; j++)
			if (d[i+1][j] > d[i][j-1])
				d[i][j] += d[i+1][j];
			else
				d[i][j] += d[i][j-1];
	fprintf(fout, "%d\n", d[0][n-1]);
	return 0;
}