#include <stdio.h>

int main()
{
	int n, i, k, l, m, p;
	while (scanf("%d", &n)==1)
	{
		m = 1;
		k = l = 0;
		for (i = 2; i <= n; i++)
			if (i%5 && i%2)
				m=(m*i)%10;
			else
			{
				p = i;
				while (p%5==0)
				{
					p/=5;
					k++;
				}
				while (p%2==0)
				{
					p/=2;
					l++;
				}
				m = (m*p)%10;
			}
		p = 1;
		for (i = 0; i < l-k; i++)
			p=(p*2)%10;
		printf("%5d -> %d\n", n, (m*p)%10);
	}
	return 0;
}