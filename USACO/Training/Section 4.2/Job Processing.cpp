/*
PROG: job
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
#define max(a, b) ((a)>(b)?(a):(b))

int a[30], b[30], enda[30], endb[30], outa[1000], outb[1000];
FILE* fin = fopen("job.in", "r");
FILE* fout = fopen("job.out", "w");
int main()
{
	int n, m1, m2, i, j, k, t;
	fscanf(fin, "%d%d%d", &n, &m1, &m2);
	for (i = 0; i < m1; i++)
		fscanf(fin, "%d", a+i);
	for (i = 0; i < m2; i++)
		fscanf(fin, "%d", b+i);
	sort(a, a+m1);
	sort(b, b+m2);
	t = -1;
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 1; j < m1; j++)
			if (enda[j]+a[j] < enda[k]+a[k])
				k = j;
		enda[k] += a[k];
		t = max(t, enda[k]);
		outa[i] = enda[k];
	}
	fprintf(fout, "%d ", t);
	t = -1;
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 1; j < m2; j++)
			if (endb[j]+b[j] < endb[k]+b[k])
				k = j;
		endb[k] += b[k];
		outb[i] = endb[k];
	}
	for (i = 0; i < n; i++)
		t = max(t, outa[i]+outb[n-i-1]);
	fprintf(fout, "%d\n", t);
	return 0;
}