#include <cstdio>

FILE* fin = fopen("count.in", "r");
FILE* fout = fopen("count.out", "w");
int main()
{
	int n, m, p, q, i;
	fscanf(fin, "%d%d", &n, &m);
	p = 0;
	for (i = 1; p < n; i++)
	{
		q = i;
		while (q)
		{
			if (q%10 == m)
				break;
			q /= 10;
		}
		if (q == 0)
			p++;
	}
	fprintf(fout, "%d\n", i-1);
	return 0;
}