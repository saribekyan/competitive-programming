/*
PROG: money
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

long long d[10001], a[25];
FILE* fin = fopen("money.in", "r");
FILE* fout = fopen("money.out", "w");
int main()
{
	int n, m, i, j;
	fscanf(fin, "%d%d", &m, &n);
	for (i = 0; i < m; i++)
		fscanf(fin, "%lld", a+i);
	d[0] = 1;
	for (j = 0; j < m; j++)
		for (i = 0; i <= n; i++)
			if (i-a[j] >= 0)
				d[i] += d[i-a[j]];
	fprintf(fout, "%lld\n", d[n]);
	return 0;
}