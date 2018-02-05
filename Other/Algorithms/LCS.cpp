// Longest Common Subsequence
#include <cstdio>
#include <string.h>

char a[1000], b[1000], s[1000];
int d[1001][1001], p[1000][1000];
FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
int main()
{
	int n, m, k, i, j;
	fscanf(fin, "%s%s", a, b);
	n = strlen(a);
	m = strlen(b);
	for (i = 0; i < n; i++)
		d[i][0] = 0;
	for (i = 0; i < m; i++)
		d[0][i] = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (a[i-1] == b[j-1])
			{
				d[i][j] = d[i-1][j-1]+1;
				p[i][j] = 0;
			}
			else
				if (d[i-1][j] > d[i][j-1])
				{
					d[i][j] = d[i-1][j];
					p[i][j] = 1;
				}
				else
				{
					d[i][j] = d[i][j-1];
					p[i][j] = -1;
				}
	fprintf(fout, "%d\n", d[n][m]);
	k = d[n][m]-1;
	s[k+1] = 0;
	while (k != -1)
	{
		if (p[n][m] == 0)
		{
			s[k--] = a[n-1];
			n--;
			m--;
		}
		else
			if (p[n][m-1] == 1)
				n--;
			else
				m--;
	}
	fprintf(fout, "%s\n", s);
	return 0;
}