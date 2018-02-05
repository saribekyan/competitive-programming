/*
PROG: theme
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int notes[5001];
int d1[5001], d2[5001];
FILE* fin = fopen("theme.in", "r");
FILE* fout = fopen("theme.out", "w");
// --- d1
// --- d2
int main()
{
	int n, w, m, i, j;
	fscanf(fin, "%d", &n);
	for (i = 1; i <= n; i++)
		fscanf(fin, "%d", notes+i);
	w = 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			d1[j] = d2[j];
			d2[j] = 1;
		}
		for (j = i+1; j <= n; j++)
			if (notes[j]-notes[i] == notes[j-1]-notes[i-1] && i < j-d1[j-1] && d2[j] < d1[j-1]+1)
			{
				d2[j] = d1[j-1]+1;
				if (w < d2[j])
					w = d2[j];
			}
	}
	if (w < 5)
		w = 0;
	fprintf(fout, "%d\n", w);
	return 0;
}
/*
#include <cstdio>

int notes[5001];
short d[5001][5001];
FILE* fin = fopen("theme.in", "r");
FILE* fout = fopen("theme.out", "w");
int main()
{
	int n, w, m, i, j;
	fscanf(fin, "%d", &n);
	for (i = 1; i <= n; i++)
		fscanf(fin, "%d", notes+i);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			d[i][j] = 1;
	for (i = 1; i <= n; i++)
		for (j = i+1; j <= n; j++)
			if (notes[j]-notes[i] == notes[j-1]-notes[i-1] && i < j-d[i-1][j-1] && d[i][j] < d[i-1][j-1]+1)
				d[i][j] = d[i-1][j-1]+1;
	w = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (w < d[i][j] && d[i][j] >= 5)
				w = d[i][j];
	fprintf(fout, "%d\n", w);
	return 0;
}*/