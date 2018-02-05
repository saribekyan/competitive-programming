/*
PROG: iou
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int a[100010];
int main()
{
	freopen("iou.in", "r", stdin);
	freopen("iou.out", "w", stdout);
	int n, m, p, q, c, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", a+i);
	m = p = q = c = 0;
	for (i = 1; i <= n; i++)
	{
		m++;
		if (a[i] > 0)
			p += a[i];
		else
		{
			q -= a[i];
			if (c == 0)
				c = i;
		}
		if (p >= q && c)
		{
			p -= q;
			q = 0;
			m += 2*(i-c);
			c = 0;
		}
	}
	printf("%d\n", m);
	return 0;
}
