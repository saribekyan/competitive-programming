#include <stdio.h>

int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97};

int main()
{
	int n, i, d, k;
	while (scanf("%d", &n) && n)
	{
		printf("%3d! =", n);
		for (i = 0; i < 25 && prime[i]<=n; i++)
		{
			d = prime[i];
			k = 0;
			while (d<=n)
			{
				k += n/d;
				d *= prime[i];
			}
			if (i!=15)
				printf("%3d", k);
			else
				printf("\n%9d", k);
		}
		putchar('\n');
	}
	return 0;
}