#include <stdio.h>
#include <string.h>

long long n, k;
long long d[510];
bool check(long long s)
{
	long long p, i, j;
	for (i = 0; i < n; i++)
		if (d[i] > s)
			return 0;
	for (p = i = j = 0; i < n; i++)
	{
		if (p+d[i] > s)
		{
			p = 0;
			j++;
		}
		p += d[i];
	}
	return j+1 <= k;
}
bool c[510];
void print(long long s)
{
	long long p=0, q=0, i;
	memset(c, 0, sizeof(c));
	for (i = n-1; i >= 0; i--)
	{
		if (p+d[i] > s)
		{
			p = 0;
			c[i] = 1;
			q++;
		}
		p += d[i];
	}
	for (i = 0; i < n-1 && q != k-1; i++)
		if (!c[i])
		{
			c[i] = 1;
			q++;
		}
	for (i = 0; i < n-1; i++)
	{
		printf("%lld ", d[i]);
		if (c[i])
			printf("/ ");
	}
	printf("%lld\n", d[n-1]);
}
int main()
{
	long long t, p, q, l, i;
	scanf("%lld", &t);
	while (t)
	{
		scanf("%lld%lld", &n, &k);
		p = q = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%lld", d+i);
			q += d[i];
		}
		while (q-p > 1)
		{
			l = (p+q)>>1;
			if (check(l))
				q = l;
			else
				p = l;
		}
		if (check(p))
			print(p);
		else
			print(q);
		t--;
	}
	return 0;
}
