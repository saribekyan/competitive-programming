#include <cstdio>

int d[25000];
FILE* fin = fopen("cavecow2.in", "r");
FILE* fout = fopen("cavecow2.out", "w");
int main()
{
	int n, m, p, q, i, j;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
		fscanf(fin, "%d", d+i);
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%d%d", &p, &q);
		n = 2147483647;
		for (j = p-1; j < q; j++)
			if (n > d[j])
				n = d[j];
		fprintf(fout, "%d\n", n);
	}
	return 0;
}