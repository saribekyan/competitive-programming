/*
PROG: stamps
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int d[2000002], s[50];
FILE* fin = fopen("stamps.in", "r");
FILE* fout = fopen("stamps.out", "w");
int main()
{
	int n, m, k, i, j;
	fscanf(fin, "%d%d", &k, &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%d", s+i);
	for (i = 0; i < 2000002; i++)
		d[i] = -1;
	d[0] = 0;
	m = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (d[j] != -1 && d[j] < k)
				if (d[j+s[i]] == -1 || d[j+s[i]] > d[j]+1)
				{
					d[j+s[i]] = d[j]+1;
					if (m < j+s[i]+1)
						m = j+s[i]+1;
				}
	for (i = 0; d[i] != -1; i++);
	fprintf(fout, "%d\n", i-1);
	return 0;
}