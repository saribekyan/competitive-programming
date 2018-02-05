#include <stdio.h>

unsigned long long d[10];
int main()
{
	int m, i;
	unsigned long long n;
	while (scanf("%lld", &n) && n)
	{
		m = 0;
		for (i = 9; i >= 0; i--)
			if ((n-i)%9 == 0)
				 d[m++] = 10*(n-i)/9+i;
		for (i = 0; i < m-1; i++)
			printf("%lld ", d[i]);
		printf("%lld\n", d[m-1]);
	}
	return 0;
}