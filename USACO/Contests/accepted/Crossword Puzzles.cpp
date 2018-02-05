#include <cstdio>
char d[101][101];
FILE* fin = fopen("xword.in", "r");
FILE* fout = fopen("xword.out", "w");
int main()
{
	int n, m, k, i, j;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%s", d[i]);
	m = 0;
	for (j = 0; j < n; j++)
	{
		i = 0;
		while (1)
		{
			while (d[i][j] == '#' && i < n)i++;
			if (i < n-1 && d[i+1][j] == '-')
				m++;
			while (d[i][j] == '-' && i < n)i++;
			if (i == n)break;
		}
	}
	k = 0;
	for (i = 0; i < n; i++)
	{
		j = 0;
		while (1)
		{
			while (d[i][j] == '#' && j < n)j++;
			if (j < n-1 && d[i][j+1] == '-')
				k++;
			while (d[i][j] == '-' && j < n)j++;
			if (j == n)break;
		}
	}
	fprintf(fout, "%d %d\n", k, m);
	return 0;
}