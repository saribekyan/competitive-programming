/*
PROG: fc
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct P{double x, y;} p[10000], sw;
FILE* fin = fopen("fc.in", "r");
FILE* fout = fopen("fc.out", "w");
int main()
{
	double len;
	int n, i, j, k, l, st;
	fscanf(fin, "%d", &n);
	k = 0;
	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%lf%lf", &p[i].x, &p[i].y);
		if (p[i].x < p[k].x)
			k = i;
	}
	len = 0.0;
	sw = p[0];
	p[0] = p[k];
	p[k] = sw;
	st = i = 0;
	while (i || (i == 0 && len <= 0.000001))
	{
		l = 0;
		if (l == i)
			l = (i+1)%n;
		for (j = 0; j < n; j++)
			if ((p[j].x-p[i].x)*(p[l].y-p[i].y)-(p[j].y-p[i].y)*(p[l].x-p[i].x) > 0)
				l = j;
			else
				if (fabs((p[j].x-p[i].x)*(p[l].y-p[i].y)-(p[j].y-p[i].y)*(p[l].x-p[i].x)) <= 0.000001 &&
					(p[j].x-p[i].x)*(p[j].x-p[i].x)+(p[j].y-p[i].y)*(p[j].y-p[i].y) >
					(p[l].x-p[i].x)*(p[l].x-p[i].x)+(p[l].y-p[i].y)*(p[l].y-p[i].y))
					l = j;
		len += sqrt((p[l].x-p[i].x)*(p[l].x-p[i].x)+(p[l].y-p[i].y)*(p[l].y-p[i].y));
		i = l;
	}
	fprintf(fout, "%.2lf\n", len);
	return 0;
}