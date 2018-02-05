/*
PROG: fracdec
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int d[100000], t[100000];
FILE* fin = fopen("fracdec.in", "r");
FILE* fout = fopen("fracdec.out", "w");
int main()
{
	int n, m, p, q, i;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < m; i++)
		t[i] = 0;
	fprintf(fout, "%d.", n/m);
	p = n/m;
	q = 1;
	if (p == 0)q = 2;
	while (p)
	{
		q++;
		p /= 10;
	}
	n %= m;
	p = 0;
	while (t[n] == 0)
	{
		t[n] = p+1;
		n *= 10;
		d[p++] = n/m;
		n %= m;
	}
	for (i = 0; i < t[n]-1; i++, q++)
	{
		if (q%76 == 0)
			fputc('\n', fout);
		fprintf(fout, "%d", d[i]);
	}
	if (p != t[n] || d[t[n]-1])
	{
		fputc('(', fout);
		q++;
		for (i = t[n]-1; i < p; i++, q++)
		{
			if (q%76 == 0)
				fputc('\n', fout);
			fprintf(fout, "%d", d[i]);
		}
		if (q%76 == 0)
			fputc('\n', fout);
		fputc(')', fout);
	}
	if (p == t[n] && d[p-1] == 0 && p == 1)
		fputc('0', fout);
	fputc('\n', fout);
	return 0;
}