// 10551 Basic Remains
#include <iostream>
#include <math.h>
using namespace std;

int minus(int a, int b, int k)
{
	char s[10];
	int a1, b1, c, d, l1, l2, i;
	c = a;
	l1 = 0;
	while (c)
	{
		c /= 10;
		l1++;
	}
	d = b;
	l2 = 0;
	while (d)
	{
		d /= 10;
		l2++;
	}
	a1 = 0;
	c = a;
	for (i = 0; i < l1; i++)
	{
		a1 += pow(k, i) * (c % 10);
		c /= 10;
	}
	b1 = 0;
	d = b;
	for (i = 0; i < l2; i++)
	{
		b1 += pow(k, i) * (d % 10);
		d /= 10;
	}
	c = a1 - b1;
	i = 0;
	while (c >= k)
	{
		s[i] = (c % k) + '0';		
		c /= k;
		i++;
	}
	s[i] = c + '0';
	c = 0;
	while (i >= 0)
	{
		c = c * 10 + (s[i] - '0');
		i--;
	}
	return c;
}

int main()
{
	char p[10000];
	int i, k, l, b, m;
	while (cin >> b >> p >> m)
	{
		i = 0;
		l = strlen(p);
		k = 0;
		while (i < l)
		{
			k = 10 * k + (p[i] - '0');
			while (k >= m)
				k = minus(k, m, b);
			i++;
		}
		cout << k << "\n";
	}
	return 0;
}