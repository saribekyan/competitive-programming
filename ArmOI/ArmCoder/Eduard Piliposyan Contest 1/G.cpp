#include <stdio.h>
#include <math.h>
#define eps (1e-9)

int main()
{
	long long s = 1, k, n;
	scanf("%lld", &n);
	for (k = 1; n >= k; k++)
	{
		n -= k;
		s += 2*k-1;
	}
	if (n)
		s += 2*(n-1);
	else
		s--;
	printf("%lld\n", s);
	return 0;
}
