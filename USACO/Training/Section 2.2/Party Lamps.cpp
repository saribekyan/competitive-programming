/*
PROG: lamps
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#define MAX 100

int on[MAX], off[MAX], p, q, n;
bool d[8] = {0}, ans[8][MAX], s;
bool g[8][4] = {
	{1, 1, 1, 1},
	{1, 1, 0, 0},
	{0, 0, 1, 1},
	{0, 0, 0, 0},
	{1, 0, 1, 0},
	{1, 0, 0, 1},
	{0, 1, 1, 0},
	{0, 1, 0, 1}};

bool less(int i, int j)
{
	int k;
	for (k = 0; k < n; k++)
	{
		if (ans[i][k] < ans[j][k])
			return 1;
		if (ans[i][k] > ans[j][k])
			return 0;
	}
}

FILE* fin = fopen("lamps.in", "r");
FILE* fout = fopen("lamps.out", "w");

int main()
{
	int c, i, j, k, t, m;
	fscanf(fin, "%d%d", &n, &c);
	p = q = 0;
	while (fscanf(fin, "%d", on+p) && on[p] != -1)
		p++;
	while (fscanf(fin, "%d", off+q) && off[q] != -1)
		q++;
	for (i = 0; i < 8; i++)
		d[i] = 1;
	if (c == 0)
		d[1] = d[2] = d[3] = d[4] = d[5] = d[6] = d[7] = 0;
	if (c == 1)
		d[0] = d[5] = d[6] = d[7] = 0;
	if (c == 2)
		d[4] = 0;
	s = 1;
	m = 0;
	for (i = 0; i < 8; i++)
		if (d[i])
		{
			for (j = 1; j <= n; j++)
			{
				if (j%2 == 0)
					if (j%3 != 1)
						t = 0;
					else
						t = 1;
				else
					if (j%3 != 1)
						t = 2;
					else
						t = 3;
				c = 1;
				if (g[i][t])
					for (k = 0; k < q; k++)
						if (off[k] == j)
						{
							c = 0;
							break;
						}
				if (!g[i][t])
					for (k = 0; k < p; k++)
						if (on[k] == j)
						{
							c = 0;
							break;
						}
				if (c)
					ans[m][j-1] = g[i][t];
				else
					break;
			}
			if (j == n+1)
			{
				s = 0;
				m++;
			}
		}
	if (s)
		fprintf(fout, "IMPOSSIBLE\n");
	else
	{
		for (i = 0; i < m-1; i++)
			for (j = i+1; j < m; j++)
				if (less(j, i))
				{
					for (k = 0; k < n; k++)
					{
						t = ans[i][k];
						ans[i][k] = ans[j][k];
						ans[j][k] = t;
					}
				}
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				fprintf(fout, "%d", ans[i][j]);
			fputc('\n', fout);
		}
	}
	return 0;
}