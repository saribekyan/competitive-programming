/*
PROG: humble
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

long long prime[100], d[100001], w;
FILE* fin = fopen("humble.in", "r");
FILE* fout = fopen("humble.out", "w");
int main()
{
	int n, m, i, j, s, t;
	fscanf(fin, "%d%d", &m, &n);
	for (i = 0; i < m; i++)
		fscanf(fin, "%lld", prime+i);
	for (i = 0; i <= n; i++)
		d[i] = 2147483647;
	d[0] = 1;
	for (i = 1; i <= n; i++)
		for (j = 0; j < m; j++)
		{
			s = 0;
			t = i-1;
			while (s != t)
			{
				if (d[(s+t)>>1]*prime[j] <= d[i-1])
					s = ((s+t)>>1)+1;
				else
					t = (s+t)>>1;
			}
			w = d[s]*prime[j];
			if (d[i] > w)
				d[i] = w;
		}
	fprintf(fout, "%lld\n", d[n]);
	return 0;
}