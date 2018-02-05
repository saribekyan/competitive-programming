#include <cstdio>

int g[1000], d[1001] = {1000};

FILE* fin = fopen("", "r");
FILE* fout = fopen("", "w");

int main()
{
	int n, m, i, j;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < m; i++)
		fscanf(fin, "%d", g+i);
	d[0] = 0;
	for (i = 1; i <= n; i++)
		d[i] = 1000;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (j+g[i] <= n)
				if (d[j+g[i]] > d[j]+1)
					d[j+g[i]] = d[j]+1;
	fprintf(fout, "%d\n", d[n]);
	return 0;
}