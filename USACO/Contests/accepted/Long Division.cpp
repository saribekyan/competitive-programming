#include <cstdio>
FILE* fin = fopen("ldiv.in", "r");
FILE* fout = fopen("ldiv.out", "w");
int main()
{
	int n, m, i;
	fscanf(fin, "%d%d", &n, &m);
	fprintf(fout, "%d.", n/m);
	n %= m;
	for (i = 0; i < 35; i++)
	{
		n *= 10;
		fprintf(fout, "%d", n/m);
		n %= m;
	}
	fputc('\n', fout);
	return 0;
}