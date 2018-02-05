#include <cstdio>

int n, m, w;
char d[1000][81];
void rec(int p, int q)
{
	if (p > 0)
		if (d[p-1][q] == '*')
		{
			w++;
			d[p-1][q] = '.';
			rec(p-1, q);
		}
	if (p < n-1)
		if (d[p+1][q] == '*')
		{
			w++;
			d[p+1][q] = '.';
			rec(p+1, q);
		}
	if (q > 0)
		if (d[p][q-1] == '*')
		{
			w++;
			d[p][q-1] = '.';
			rec(p, q-1);
		}
	if (q < m-1)
		if (d[p][q+1] == '*')
		{
			w++;
			d[p][q+1] = '.';
			rec(p, q+1);
		}
}
FILE* fin = fopen("satpix.in", "r");
FILE* fout = fopen("satpix.out", "w");
int main()
{
	int max, i, j;
	fscanf(fin, "%d%d", &m, &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%s", d[i]);
	max = -1;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (d[i][j] == '*')
			{
				w = 1;
				d[i][j] = '.';
				rec(i, j);
				if (w > max)
					max = w;
			}
	fprintf(fout, "%d\n", max);
	return 0;
}