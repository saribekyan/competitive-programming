#include <stdio.h>
#define MAX 1000

int d[MAX], n;

void heapify(int i)
{
	int l, p, q;
	l = i;
	p = i<<1;
	q = p|1;
	if (p < n)
		if (d[l] < d[p])
			l = p;
	if (q < n && l < n)
		if (d[l] < d[q])
			l = q;
	if (i!=l)
	{
		d[i] ^= d[l];
		d[l] ^= d[i];
		d[i] ^= d[l];
		heapify(l);
	}
}

int main()
{
	int m, i;
	while (scanf("%d", &n) == 1)
	{
		for (i = 0; i < n; i++)
			scanf("%d", d+i);
		for (i = n/2-1; i >= 0; i--)
			heapify(i);
		m = n;
		for (i = n-1; i > 0; i--)
		{
			d[i] ^= d[0];
			d[0] ^= d[i];
			d[i] ^= d[0];
			n--;
			heapify(0);
		}
		for (i = 0; i < m-1; i++)
			printf("%d ", d[i]);
		printf("%d\n", d[m-1]);
	}
	return 0;
}