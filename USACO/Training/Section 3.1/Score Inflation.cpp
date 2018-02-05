/*
PROG: inflate
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int d[10001];
struct problem{int minute, point;}s[10000];
FILE* fin = fopen("inflate.in", "r");
FILE* fout = fopen("inflate.out", "w");
int main()
{
	int n, m, p, i, j;
	fscanf(fin, "%d%d", &m, &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%d%d", &s[i].point, &s[i].minute);
	d[0] = 0;
	for (i = 1; i <= m; i++)
		d[i] = -1;
	for (i = 0; i < n; i++)
		for (j = 0; j <= m; j++)
			if (d[j] != -1 && j+s[i].minute <= m)
				if (d[j+s[i].minute] < d[j]+s[i].point)
					d[j+s[i].minute] = d[j]+s[i].point;
	p = -1;
	for (i = 0; i <= m; i++)
		if (p < d[i])
			p = d[i];
	fprintf(fout, "%d\n", p);
	return 0;
}