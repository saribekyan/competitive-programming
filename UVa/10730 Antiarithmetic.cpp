#include <stdio.h>

int d[10000];
int main()
{
	int n, m, i, j;
	while (scanf("%d:", &n) && n)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &m);
			d[m] = i;
		}
		for (i = 0; i < n-2; i++)
			for (j = 1; i+2*j < n; j++)
				if (d[i+j] > d[i] && d[i+2*j] > d[i+j])
					goto there;
there:;
		if (i == n-2)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}