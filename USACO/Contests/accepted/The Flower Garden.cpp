#include <cstdio>

bool d[10001];
FILE* fin = fopen("flowers.in", "r");
FILE* fout = fopen("flowers.out", "w");
int main()
{
	int n, m, i, j, p, q;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
		d[i] = 0;
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%d%d", &p, &q);
		for (j = p-1; j < n; j += q)
			d[j] = 1;
	}
	p = 0;
	for (i = 0; i < n; i++)
		if (!d[i])
			p++;
	fprintf(fout, "%d\n", p);
	return 0;
}
