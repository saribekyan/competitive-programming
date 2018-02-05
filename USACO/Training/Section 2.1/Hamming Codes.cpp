/*
PROG: hamming
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#define MAX 256

int ans[MAX+1], n, p;
bool g[MAX+1][MAX+1], t;
FILE* fin = fopen("hamming.in", "r");
FILE* fout = fopen("hamming.out", "w");
int dist(int a, int b)
{
	int q, u;
	u = a^b;
	q = 0;
	while (u)
	{
		if (u%2)
			q++;
		u >>= 1;
	}
	return q;
}

void rec(int m, int i)
{
	if (m==n)
	{
		int j;
		fprintf(fout, "%d", ans[0]);
		for (j = 1; j < n; j++)
		{
			if (j%10==0)fputc('\n', fout);
			else fputc(' ', fout);
			fprintf(fout, "%d", ans[j]);
		}
		fputc('\n', fout);
		t = 1;
		return;
	}
	int j, k;
	for (j = 0; j <= p; j++)
		if (g[i][j]==1)
		{
			for (k = 0; k < m; k++)
				if (!g[j][ans[k]])
					break;
			if (k == m)
			{
				ans[m] = j;
				g[i][j] = g[j][i] = 0;
				rec(m+1, j);
				if (t)return;
				g[i][j] = g[j][i] = 1;
			}
		}
}

int main()
{
	int b, d, i, j;
	fscanf(fin, "%d%d%d", &n, &b, &d);
	p = 1<<b;
	for (i = 0; i <= p; i++)
		for (j = 0; j <= p; j++)
			if (dist(i, j) >= d)
				g[i][j] = 1;
			else
				g[i][j] = 0;
	i = 0;
	t = 0;
	while (!t && i <= p)
	{
		ans[0] = i;
		rec(1, i);
		i++;
	}
	return 0;
}