/*
PROG: rockers
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int d[20], n, m, p;
int rec(int cd, int t, int s)
{
	if (cd == 0 || s == n)
		return 0;
	int r, v;
	r = v = 0;
	if (d[s] <= t)
		r = rec(cd, t-d[s], s+1)+1;
	else
		if (cd > 1 && d[s] <= p)
			r = rec(cd-1, p-d[s], s+1)+1;
	v = rec(cd, t, s+1);
	return ((r)>(v)?(r):(v));
}
FILE* fin = fopen("rockers.in", "r");
FILE* fout = fopen("rockers.out", "w");
int main()
{
	int i;
	fscanf(fin, "%d%d%d", &n, &p, &m);
	for (i = 0; i < n; i++)
		fscanf(fin, "%d", d+i);
	fprintf(fout, "%d\n", rec(m, p, 0));
	return 0;
}