#include <stdio.h>

int main()
{
	int m, n, p, k, d;
	while (scanf("%d",&m)==1)
	{
		n = d = p = 1;
		k = 10%m;
		while (p%m)
		{
			d = (d*k)%m;
			p += d;
			n++;
		}
		printf("%d\n", n);
	}
	return 0;
}