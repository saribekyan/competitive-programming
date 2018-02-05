#include <stdio.h>
#include <math.h>

int main()
{
	long double n, p;
	while (scanf("%Lf%Lf", &n, &p)==2)
		printf("%lld\n", (long long)(pow(p, 1/n)+0.5));
	return 0;
}