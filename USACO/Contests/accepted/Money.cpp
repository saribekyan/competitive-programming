#include <cstdio>

int d[5500] = {0}, money[6] = {1, 5, 10, 25, 50, 100};
FILE* fin = fopen("money.in", "r");
FILE* fout = fopen("money.out", "w");
int main()
{
	int n, i, j;
	fscanf(fin, "%d", &n);
	d[0] = 1;
	for (i = 0; i < 6; i++)
		for (j = 0; j <= n; j++)
			if (j+money[i] <= n)
				d[j+money[i]] += d[j];
	fprintf(fout, "%d\n", d[n]);
	return 0;
}