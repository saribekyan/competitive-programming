#include <stdio.h>

int main()
{
	long long n, i;
	while (scanf("%lld", &n) && n)
	{
		printf("%lld =", n);
		if (n<0)
		{
			n*=-1;
			printf(" -1 x");
		}
		while (n%2==0)
		{
			n /= 2;
			printf(" 2");
			if (n!=1)
				printf(" x");
		}
		for (i = 3; i*i <= n; i+=2)
			while (n%i==0)
			{
				n/=i;
				printf(" %lld", i);
				if (n!=1)
					printf(" x");
			}
		if (n!=1)printf(" %lld", n);
		putchar('\n');
	}
	return 0;
}