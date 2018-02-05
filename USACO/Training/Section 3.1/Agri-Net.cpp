/*
PROG: agrinet
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

bool t[100];
int g[100][100];
FILE* fin = fopen("agrinet.in", "r");
FILE* fout = fopen("agrinet.out", "w");
int main()
{
	int n, m, w, p, i, j, k, l;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			fscanf(fin, "%d", &g[i][j]);
	t[0] = 1;
	for (i = 1; i < n; i++)
		t[i] = 0;
	w = 0;
	while (1)
	{
		k = 2147483647;
		for (i = 0; i < n; i++)
			if (t[i])
			{
				for (j = 0; j < n; j++)
					if (!t[j] && k > g[i][j])
					{
						l = j;
						k = g[i][j];
					}
			}
		if (k == 2147483647)
			break;
		t[l] = 1;
		w += k;
	}
	fprintf(fout, "%d\n", w);
	return 0;
}