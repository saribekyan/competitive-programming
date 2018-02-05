#include <cstdio>

bool d[100];
int g[100][100], way[100], min, n, s, t, f;
void dfs(int p, int m)
{
	int i;
	if (p == t-1)
	{
		min = g[way[0]][way[1]];
		for (i = 1; i < m-1; i++)
			if (min > g[way[i]][way[i+1]])
				min = g[way[i]][way[i+1]];
		for (i = 0; i < m-1; i++)
		{
			g[way[i]][way[i+1]] -= min;
			g[way[i+1]][way[i]] += min;
		}
		f += min;
		return ;
	}
	for (i = 1; i < n; i++)
		if (d[i] == 0 && g[p][i] > 0)
		{
			d[i] = 1;
			way[m] = i;
			dfs(i, m+1);
			d[i] = 0;
		}
}
FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
int main()
{
	int m, i, j, p, q, c;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			g[i][j] = 0;
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%d%d%d", &p, &q, &c);
		g[p-1][q-1] = c;
	}
	fscanf(fin, "%d%d", &s, &t);
	for (i = 1; i < n; i++)
		d[i] = 0;
	d[0] = 1;
	f = 0;
	way[0] = s-1;
	dfs(s-1, 1);
	fprintf(fout, "%d\n", f);
	return 0;
}