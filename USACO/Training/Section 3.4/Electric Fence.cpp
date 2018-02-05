/*
PROG: fence9
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <cmath>

int gcd(int m, int n)
{
	while (n)
	{
		m %= n;
		m ^= n;
		n ^= m;
		m ^= n;
	}
	return m;
}
FILE* fin = fopen("fence9.in", "r");
FILE* fout = fopen("fence9.out", "w");
int main()
{
	int m, n, p, in;
	double on, s;
	fscanf(fin, "%d%d%d", &n, &m, &p);
	s = m*p/2.0;
	on = (gcd(m, n)+gcd(abs(p-n), m)+p)/2.0;
	in = s-on+1;
	fprintf(fout, "%d\n", in);
	return 0;
}