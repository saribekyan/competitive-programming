/*
PROG: subset
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

unsigned long int d[411] = {0};
FILE* fin = fopen("subset.in", "r");
FILE* fout = fopen("subset.out", "w");

int main()
{
	int n, m, i, j, k;
	fscanf(fin, "%d", &n);
	m = n*(n+1)>>1;
	if (m%2 == 0)
	{
		m >>= 1;
		d[0] = 1;
		for (i = 1; i <= n; i++)
			for (j = m; j >= 0; j--)
				if (i+j <= m)
					d[i+j] += d[j];
		fprintf(fout, "%d\n", d[m]/2);
	}
	else
		fprintf(fout, "0\n");
	return 0;
}