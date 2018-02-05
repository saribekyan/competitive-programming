#include <stdio.h>
#include <string.h>

struct node
{
	int left;
	int total;
} d[262145];
int main()
{
	int n, k, p, m, l, w, i;
	scanf("%d%d", &n, &k);
	p = 1;
	while (p < n)
		p <<= 1;
	memset(d, 0, sizeof(d));
	for (i = p+n-1; i >= 1; i--)
		if (i >= p)
		{
			d[i].total = -1;
			if (!(i&1))
				d[i>>1].left = 1;
			d[i>>1].total++;
		}
		else
		{
			if (!(i&1))
				d[i>>1].left = d[i].total;
			d[i>>1].total += d[i].total;
		}
	for (m = k, i = 0; i < n; i++)
	{
		l = 1;
		w = m;
		while (d[l].total != -1)
		{
			d[l].total--;
			if (d[l].left >= w)
			{
				d[l].left--;
				l <<= 1;
			}
			else
			{
				w -= d[l].left;
				l = ((l<<1)|1);
			}
		}
		if (i+1 != n)
			if ((m+k-1)%(n-i-1))
				m = (m+k-1)%(n-i-1);
			else
				m = n-i-1;
		printf("%d", l-p+1);
		if (i+1 == n)
			putchar('\n');
		else
			putchar(' ');
	}
	return 0;
}
