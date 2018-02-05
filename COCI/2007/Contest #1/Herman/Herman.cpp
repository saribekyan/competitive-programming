#include <cstdio>
#include <cmath>
FILE* fin = fopen("herman.in", "r");
FILE* fout = fopen("herman.out", "w");
int main()
{
	double r;
	fscanf(fin, "%lf", &r);
	fprintf(fout, "%.6lf\n%.6lf\n", 2.0*acos(0.0)*r*r, r*r*2.0);
	return 0;
}
