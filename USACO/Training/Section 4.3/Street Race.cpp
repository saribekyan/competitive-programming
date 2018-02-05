/*
PROG: race3
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int n;
bool g[50][50], d[50][50], gr[50], t[50];
void rec(int p)
{
	int i;
	for (i = 0; i < n; i++)
		if (g[p][i] && !gr[i])
		{
			gr[i] = 1;
			rec(i);
		}
}
FILE* fin = fopen("race3.in", "r");
FILE* fout = fopen("race3.out", "w");
int main()
{
	int p, i, j, k, l;
	n = 0;
	while (1)
	{
		while (fscanf(fin, "%d", &p) && p != -2 && p != -1)
			g[n][p] = d[n][p] = 1;
		if (p == -1)
			break;
		n++;
	}
	p = 0;
	for (i = 1; i < n-1; i++)
	{
		for (j = 0; j < n; j++)
			g[i][j] = g[j][i] = 0;
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				for (l = 0; l < n; l++)
					g[k][l] = g[k][l] || (g[k][j] && g[j][l]);
		if (!g[0][n-1])
		{
			p++;
			t[i] = 1;
		}
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				g[j][k] = d[j][k];
	}
	fprintf(fout, "%d", p);
	for (i = 0; i < n; i++)
		if (t[i])
			fprintf(fout, " %d", i);
	fputc('\n', fout);
	for (i = 0; i < n; i++)
		t[i] = 0;
	for (j = 0; j < n; j++)
		for (k = 0; k < n; k++)
			g[j][k] = d[j][k];
	for (i = 1; i < n-1; i++)
	{
		for (j = 0; j < n; j++)
			gr[j] = 0;
		gr[i] = 1;
		rec(i);
		for (j = 0; j < n; j++)
			if (gr[j] == 0)
				break;
		if (j == n)
			goto there;
		for (j = 0; j < n; j++)
			g[i][j] = g[j][i] = 0;
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				for (l = 0; l < n; l++)
					g[k][l] = g[k][l] || (g[k][j] && g[j][l]);
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				if (gr[j] != gr[k] && (g[j][k] || g[k][j]))
					goto there;
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				g[j][k] = d[j][k];
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				for (l = 0; l < n; l++)
					g[k][l] = g[k][l] || (g[k][j]&&g[j][l]);
		for (j = 0; j < n-1; j++)
			if (gr[j] && !g[j][n-1])
				goto there;
		for (j = 1; j < n; j++)
			if (!gr[j] && (!g[0][j] || !g[j][i]))
				goto there;
		t[i] = 1;
there:;
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				g[j][k] = d[j][k];
	}
	p = 0;
	for (i = 1; i < n-1; i++)
		if (t[i])
			p++;
	fprintf(fout, "%d", p);
	for (i = 0; i < n; i++)
		if (t[i])
			fprintf(fout, " %d", i);
	fputc('\n', fout);
	return 0;
}