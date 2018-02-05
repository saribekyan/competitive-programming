#include <cstdio>

int prime[10000], d[5000];
FILE* fin = fopen("bigfact.in", "r");
FILE* fout = fopen("bigfact.out", "w");
int main()
{
	int n, m, p, q, i, j;
	fscanf(fin, "%d", &n);
	p = -1;
	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%d", d+i);
		if (p < d[i])
			p = d[i];
	}
	m = 2;
	prime[0] = 1;
	prime[1] = 2;
	for (i = 3; i <= p; i+=2)
	{
		for (j = 1; j < m && prime[j]*prime[j] <= i; j++)
			if (i%prime[j] == 0)
			{
				j = 100000;
				break;
			}
		if (j != 100000)
			prime[m++] = i;
	}
	p = -1;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (d[i]%prime[j] == 0 && p < prime[j])
			{
				p = prime[j];
				q = d[i];
			}
	fprintf(fout, "%d\n", q);
	return 0;
}