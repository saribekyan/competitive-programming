/*
PROG: fact4
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

FILE* fin = fopen("fact4.in", "r");
FILE* fout = fopen("fact4.out", "w");
int main()
{
	int n, m, p, k, l, i;
	fscanf(fin, "%d", &n);
	m = 1;
	k = l = 0;
	for (i = 1; i <= n; i++)
	{
		p = i;
		while (p%2 == 0)
		{
			p >>= 1;
			k++;
		}
		while (p%5 == 0)
		{
			p /= 5;
			l++;
		}
		m = (m*p)%10;
	}
	for (i = 0; i < k-l; i++)
		m = (m<<1)%10;
	fprintf(fout, "%d\n", m);
	return 0;
}