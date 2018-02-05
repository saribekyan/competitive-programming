#include <cstdio>

int d[100];
FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
int main()
{
	int n, m, p, q, i;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
		fscanf(fin, "%d", d+i);
	p = 0;
	q = n-1;
	while (q-p > 1)
		if (d[(q+p+1)/2] > m)
			q = (q+p+1)/2;
		else
			p = (q+p+1)/2;
	if (d[p] == m)
		fprintf(fout, "%d\n", p+1);
	else
		if (d[q] == m)
			fprintf(fout, "%d\n", q+1);
		else
			fprintf(fout, "%d %d\n", p+1, q+1);
	return 0;
}