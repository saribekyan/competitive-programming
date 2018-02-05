#include <cstdio>

bool t[1000];
int g[1000][1000], d[1000];
FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
int main()
{
	int n, m, p, q, start, w, k, i;
	fscanf(fin, "%d%d%d", &n, &m, &start);
	for (i = 0; i < n; i++)
		for (k = 0; k < n; k++)
			g[i][k] = 1073741823;
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%d%d%d", &p, &q, &w);
		g[p-1][q-1] = g[q-1][p-1] = w;
	}
	p = start-1;
	for (i = 0; i < n; i++)
	{
		t[i] = 0;
		d[i] = 1073741823;
	}
	d[p] = 0;
	while (t[p] == 0)
	{
		t[p] = 1;
		for (i = 0; i < n; i++)
			if (d[p]+g[p][i] < d[i])
				d[i] = d[p]+g[p][i];
		q = 1073741823;
		for (i = 1; i < n; i++)
			if (!t[i] && g[p][i] < q)
			{
				k = i;
				q = g[p][i];
			}
		p = k;
	}
	for (i = 0; i < n-1; i++)
		fprintf(fout, "%d ", d[i]);
	fprintf(fout, "%d\n", d[n-1]);
	return 0;
}