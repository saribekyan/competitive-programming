#include <cstdio>

bool t[1000];
int g[1000][1000];
FILE* fin = fopen("cowtract.in", "r");
FILE* fout = fopen("cowtract.out", "w");
int main()
{
	int n, m, p, q, w, i, j;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			g[i][j] = -1;
	for (i = 0; i < n; i++)
		t[i] = 0;
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%d%d%d", &p, &q, &w);
		if (g[p-1][q-1] < w)
			g[p-1][q-1] = g[q-1][p-1] = w;
	}
	t[0] = 1;
	m = 1;
	w = 0;
	while (m != n)
	{
		q = -1;
		for (i = 0; i < n; i++)
			if (t[i])
				for (j = 0; j < n; j++)
					if (!t[j])
						if (g[i][j] > q)
						{
							q = g[i][j];
							p = j;
						}
		if (q == -1)
			break;
		t[p] = 1;
		w += q;
		m++;
	}
	if (m == n)
		fprintf(fout, "%d\n", w);
	else
		fprintf(fout, "-1\n");
	return 0;
}