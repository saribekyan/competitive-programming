/*
PROG: schlnet
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define max(a, b) ((a)>(b)?(a):(b))

bool t[100];
int deg[100];
bool g[100][100], d[100][100];
FILE* fin = fopen("schlnet.in", "r");
FILE* fout = fopen("schlnet.out", "w");
int main()
{
	int n, m, s, r, w, l, p, i, j, k;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		while (fscanf(fin, "%d", &p) && p)
		{
			if (i != p-1)
				deg[p-1]++;
			d[p-1][i] = g[i][p-1] = 1;
		}
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
	for (i = 0; i < n; i++)
		g[i][i] = 1;
	for (m = n, s = 0; m; s++)
	{
		l = -1;
		for (i = 0; i < n; i++)
			if (!t[i])
			{
				w = 0;
				for (j = 0; j < n; j++)
					if (g[i][j] && !t[j])
						w++;
				if (l < w)
				{
					l = w;
					p = i;
				}
			}
		for (i = 0; i < n; i++)
			if (g[p][i] && !t[i])
			{
				m--;
				t[i] = 1;
			}
	}
	memset(t, 0, sizeof(t));
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i != j)
				deg[i] += (int)(d[j][i]);
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
	for (i = 0; i < n; i++)
		d[i][i] = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (!d[i][j])
				goto there;
	fprintf(fout, "%d\n0\n", s);
	return 0;
there:;
	for (m = n, r = 0; m; r++)
	{
		l = -1;
		for (i = 0; i < n; i++)
			if (!t[i])
			{
				w = 0;
				for (j = 0; j < n; j++)
					if (d[i][j] && !t[j])
						w++;
				if (l < w)
				{
					l = w;
					p = i;
				}
			}
		for (i = 0; i < n; i++)
			if (d[p][i] && !t[i])
			{
				m--;
				t[i] = 1;
			}
	}
	fprintf(fout, "%d\n%d\n", s, max(s, r));
	return 0;
}