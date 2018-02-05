#include <cstdio>
FILE* fin = fopen("mpy.in", "r");
FILE* fout = fopen("mpy.out", "w");
int main()
{
	int n, m;
	fscanf(fin, "%d%d", &n, &m);
	fprintf(fout, "   %d\n   %d\n------\n%6d\n%5d\n%4d\n------\n%6d\n",
		n, m, n*(m%10), n*((m/10)%10), n*(m/100), n*m);
	return 0;
}