#include <cstdio>

int a[35000];
bool d[35000];
FILE* fin = fopen("eatpuz.in", "r");
FILE* fout = fopen("eatpuz.out", "w");
int main()
{
	int n, m, i, j;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < m; i++)
		fscanf(fin, "%d", a+i);
	d[0] = 1;
	for (i = 1; i < n; i++)
		d[i] = 0;
	for (i = 0; i < m; i++)
		for (j = n; j >= 0; j--)
			 if (j+a[i] <= n)
				d[j+a[i]] = d[j+a[i]] || d[j];
	for (i = n; i >= 0; i--)
		if (d[i])
			break;
	fprintf(fout, "%d\n", i);
	return 0;
}