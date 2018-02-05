#include <stdio.h>

int main()
{
	unsigned long long n;
	while (scanf("%lld", &n) == 1)
		printf("%lld\n", n*n*(n+1)*(n+1)/4);
	return 0;
}