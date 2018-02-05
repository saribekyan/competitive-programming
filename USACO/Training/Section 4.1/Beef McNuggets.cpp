/*
PROG: nuggets
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int d[10];
bool can[65537];
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
FILE* fin = fopen("nuggets.in", "r");
FILE* fout = fopen("nuggets.out", "w");
int main()
{
	int n, m, i, j;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%d", d+i);
	m = d[0];
	for (i = 1; i < n; i++)
		m = gcd(m, d[i]);
	if (m != 1)
	{
		fprintf(fout, "0\n");
		return 0;
	}
	can[0] = 1;
	for (i = 1; i < 65537; i++)
		can[i] = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < 65537; j++)
			if (can[j] && j+d[i] < 65537)
				can[j+d[i]] = 1;
	for (i = 65536; i >= 0; i--)
		if (!can[i])
		{
			fprintf(fout, "%d\n", i);
			return 0;
		}
	fprintf(fout, "0\n");
	return 0;
}