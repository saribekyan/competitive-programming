#include <stdio.h>

int main()
{
	int c;
	long long n, m, p, w, q, i, j;
	while (scanf("%lld%lld", &n, &m)==2)
		if (n <= 1 && m>1 || m==0)printf("%lld does not divide %lld!\n", m, n);
		else
			if (n <= 1 && m==1)printf("%lld divides %lld!\n", m, n);
			else
			{
				p = m;
				w = q = 0;
				while (p%2==0){p/=2; w++;}
				i = 2;
				while (i<=n)
				{
					q += n/i;
					i *= 2;
				}
				if (q<w)printf("%lld does not divide %lld!\n", m, n);
				else
				{
					c = 1;
					for (i = 3; i*i <= p; i+=2)
						if (p%i==0)
						{
							w = q = 0;
							while (p%i==0)
							{
								p /= i;
								w++;
							}
							j =	i;
							while (j<=n)
							{
								q += n/j;
								j *= i;
							}
							if (q<w){printf("%lld does not divide %lld!\n", m, n);c=0;break;}
						}
					if (c)
						if (p>n)printf("%lld does not divide %lld!\n", m, n);
						else printf("%lld divides %lld!\n", m, n);
				}
			}
	return 0;
}
/*
0 0 
1 0 
2 0 
10 0 
2147483647 0 
0 1 
1 1 
2 1 
10 1 
2147483647 1 
10 2 
2147483647 2 
10 3 
5 5 
6 9 
0 10 
6 18 
6 27 
1009 1000 
1000 1009 
20 10000 
20 100000 
1073741824 1000000 
43213 93390991 
123456789 123456871 
123456789 123456873 
123456789 123456790 
123456789 124880621 
123456789 124925329 
43213 906190609 
1073741824 1073741824 
2147483647 1073741824 
0 2147483647 
1 2147483647 
2 2147483647 
1073741824 2147483647 
2147483647 2147483647

0 does not divide 0! 
0 does not divide 1! 
0 does not divide 2! 
0 does not divide 10! 
0 does not divide 2147483647! 
1 divides 0! 
1 divides 1! 
1 divides 2! 
1 divides 10! 
1 divides 2147483647! 
2 divides 10! 
2 divides 2147483647! 
3 divides 10! 
5 divides 5! 
9 divides 6! 
10 does not divide 0! 
18 divides 6! 
27 does not divide 6! 
1000 divides 1009! 
1009 does not divide 1000! 
10000 divides 20! 
100000 does not divide 20! 
1000000 divides 1073741824! 
93390991 divides 43213! 
123456871 does not divide 123456789! 
123456873 divides 123456789! 
123456790 divides 123456789! 
124880621 divides 123456789! 
124925329 divides 123456789! 
906190609 does not divide 43213! 
1073741824 divides 1073741824! 
1073741824 divides 2147483647! 
2147483647 does not divide 0! 
2147483647 does not divide 1! 
2147483647 does not divide 2! 
2147483647 does not divide 1073741824! 
2147483647 divides 2147483647!
*/