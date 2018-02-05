/*
PROG: holstein
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int d[25], a[25], g[15][25], m;
bool t[15], p[15];

bool next()
{
	int i;
	i = m-1;
	while (t[i])
		t[i--] = 0;
	if (i==-1)
		return 0;
	t[i] = 1;
	return 1;
}

bool small()
{
	int i;
	for (i = 0; i < m; i++)
	{
		if (p[i] && t[i]==0)
			return 0;
		if (p[i]==0 && t[i])
			return 1;
	}
}
FILE* fin = fopen("holstein.in", "r");
FILE* fout = fopen("holstein.out", "w");
int main()
{
	int n, k, ans, i, j;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%d", d+i);
	fscanf(fin, "%d", &m);
	for (i = 0; i < m; i++)
	{
		t[i] = 0;
		p[i] = 1;
		for (j = 0; j < n; j++)
			fscanf(fin, "%d", &g[i][j]);
	}
	ans = 16;
	do
	{
		for (i = 0; i < n; i++)
			a[i] = 0;
		k = 0;
		for (i = 0; i < m; i++)
			if (t[i])
			{
				for (j = 0; j < n; j++)
					a[j] += g[i][j];
				k++;
			}
		if (k < ans)
		{
			for (i = 0; i < n; i++)
				if (a[i] < d[i])
					break;
			if (i == n)
			{
				ans = k;
				for (i = 0; i < m; i++)
					p[i] = t[i];
			}
		}
		if (k == ans)
		{
			for (i = 0; i < n; i++)
				if (a[i] < d[i])
					break;
			if (i == n)
				if (small())
					for (i = 0; i < m; i++)
						p[i] = t[i];
		}
	}
	while (next());
	fprintf(fout, "%d", ans);
	for (i = 0; i < m; i++)
		if (p[i])
			fprintf(fout, " %d", i+1);
	fputc('\n', fout);
	return 0;
}