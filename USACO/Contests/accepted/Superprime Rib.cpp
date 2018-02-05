#include <cstdio>

int n;
FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
bool prime(__int64 n)
{
	if (n == 2)return 1;
	if (n%2 == 0)return 0;
	int i;
	for (i = 3; i*i <= n; i+=2)
		if (n%i == 0)
			return 0;
	return 1;
}
void rec(__int64 p, int m)
{
	if (m == n)
	{
		if (prime(p))
			fprintf(fout, "%lld\n", p);
		return;
	}
	if (!prime(p))
		return;
	rec(p*10+1, m+1);
	rec(p*10+3, m+1);
	rec(p*10+7, m+1);
	rec(p*10+9, m+1);
}
int main()
{
	fscanf(fin, "%d", &n);
	rec(2, 1);
	rec(3, 1);
	rec(5, 1);
	rec(7, 1);
	return 0;
}