#include <stdio.h>

typedef long long LL;
LL p[20];
LL count(LL n, LL l)
{
	LL m=0, s, k, i, j;
	for (i = 2; i*i <= n; i++)
		if (n%i == 0)
		{
			p[m++] = i;
			while (n%i == 0)
				n /= i;
		}
	if (n != 1)
		p[m++] = n;
	n = 0;
	for (i = 1; i < (1<<m); i++)
	{
		s = 1;
		for (k = j = 0; j < m; j++)
			if ((i>>j)&1)
			{
				k++;
				s *= p[j];
			}
		if (k&1)
			n += l/s;
		else
			n -= l/s;
	}
	return n;
}
int main()
{
	LL a, b, l, y;
	LL none, one, both, c1, c2, c3;
	scanf("%lld%lld%lld", &a, &b, &l);
	c1 = count(a+b, l);
	none = 2*c1;
	one = 2*(l-c1-1);
	both = 2;
	for (y = 1; y < a+b; y++)
	{
		c1 = l-count(y, l);
		c2 = l-count(a+b-y, l);
		c3 = l-count(y*(a+b-y), l);
		none += l-c1-c2+c3;
		one += c1+c2-2*c3;
		both += c3;
	}
	printf("%lld\n%lld\n%lld\n", none, one, both);
	return 0;
}
