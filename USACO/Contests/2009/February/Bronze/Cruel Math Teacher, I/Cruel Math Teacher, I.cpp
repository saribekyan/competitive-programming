/*
PROG: cruel1
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#define B 1000000000

char a[20000], *b;
long long d[20000];
int main()
{
	freopen("cruel1.in", "r", stdin);
	freopen("cruel1.out", "w", stdout);
	long long n, l, c, p, m, i;
	scanf("%lld%lld", &n, &p);
	l = 0;
	d[0] = 1;
	while (p--)
	{
		c = 0;
		for (i = 0; i <= l || c; i++)
		{
			m = d[i]*n+c;
			d[i] = m%B;
			c = m/B;
			if (i > l && d[i])
				l = i;
		}
	}
	b = a;
	sprintf(b, "%d", d[l]);
	while (*b)
		b++;
	for (i = l-1; i >= 0; i--)
	{
		sprintf(b, "%09.9d", d[i]);
		while (*b)
			b++;
	}
	for (i = 0; a[i]; i+=70)
		printf("%.70s\n", &a[i]);
	return 0;
}
