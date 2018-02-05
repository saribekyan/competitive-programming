/*
PROG: frac1
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 25600

struct frac{int a, b;}d[MAX];
bool operator <(frac a, frac b){return a.a*b.b < a.b*b.a;}
int gcd(int m, int n)
{
	while (n)
	{
		m %= n;
		n ^= m;
		m ^= n;
		n ^= m;
	}
	return m;
}
FILE* fin = fopen("frac1.in", "r");
FILE* fout = fopen("frac1.out", "w");
int main()
{
	int n, m, i, j, k, a, b;
	fscanf(fin, "%d", &n);
	fprintf(fout, "0/1\n");
	m = 0;
	for (i = 1; i < n; i++)
		for (j = i+1; j <= n; j++)
		{
			k = gcd(i, j);
			a = i/k;
			b = j/k;
			for (k = 0; k < m; k++)
				if (a == d[k].a && b == d[k].b)
					break;
			if (k==m)
			{
				d[m].a = a;
				d[m].b = b;
				m++;
			}
		}
	sort(d, d+m);
	for (i = 0; i < m; i++)
		fprintf(fout, "%d/%d\n", d[i].a, d[i].b);
	fprintf(fout, "1/1\n");
	return 0;
}