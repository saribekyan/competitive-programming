#include <stdio.h>
#define MAX 6000

long long D[MAX+1];
int a[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};

int main()
{
	double n;
	int i, j, m;
	for (i = 1; i <= MAX; i++)
		D[i] = 0;
	D[0] = 1;
	for (i = 0; i < 11; i++)
		for (j = a[i]; j <= MAX; j++)
			D[j] += D[j-a[i]];
	while (scanf("%lf", &n) && n)
	{
		m = 20*n+0.4;
		printf("%6.2lf%17lld\n", n, D[(int)m]);
	}
	return 0;
}