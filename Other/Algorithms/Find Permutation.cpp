//	Finds the n_th permutation of length m that has k 1's
//	Input: m, k, n: m<=63
//	Output: w - the permutation on base 10
#include <cstdio>

unsigned long long d[32][32], w;
void rec(int m, unsigned long long n, int k)
{
	if (k == 0)
	{
		w *= 1<<m;
		return;
	}
	if (n > d[m-1][k])
	{
		w = (w<<1)+1;
		rec(m-1, n-d[m-1][k], k-1);
	}
	else
	{
		w = w<<1;
		rec(m-1, n, k);
	}
}

FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
int main()
{
	int k, m, i, j;
	unsigned long long n;
	fscanf(fin, "%d%d%lld", &m, &k, &n);
	for (i = 0; i <= m; i++)
		d[i][i] = d[i][0] = 1;
	for (i = 1; i <= m; i++)
		for (j = 1; j <= m; j++)
			d[i][j] = d[i-1][j]+d[i-1][j-1];
	w = 0;
	rec(m, n, k);
	fprintf(fout, "%lld\n", w);
	return 0;
}