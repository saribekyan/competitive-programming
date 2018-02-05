#include <stdio.h>

int n;
int d[100010];
int can(int m)
{
	int p, q, i;
	for (i = 0; i < n; i++)
		if (d[i] > m)
			return 1000000;
	for (p = q = i = 0; i <= n; i++)
	{
		p += d[i];
		if (p > m)
		{
			p = 0;
			i--;
			q++;
		}
	}
	return q+(int)(p != 0);
}
int main()
{
	freopen("expense.in", "r", stdin);
	freopen("expense.out", "w", stdout);
	int m, p, q, k, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", d+i);
	p = 1;
	q = 1000000000;
	d[n] = 0;
	while (q-p > 1)
	{
		k = (p+q)/2;
		if (can(k) > m)
			p = k;
		else
			q = k;
	}
	if (can(p) == m)
		printf("%d\n", p);
	else
		printf("%d\n", q);
	return 0;
}
