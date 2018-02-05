#include <stdio.h>
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

int t[1000010];
int main()
{
	char ch;
	int n, m, p, q, c, d, k, l, i;
	scanf("%d%d", &n, &m);
	getchar();
	t[0] = 1;
	for (i = 1; i <= n; i++)
		t[i] = (t[i-1]<<1)%m;
	p = q = c = d = 0;
	for (i = 1; i <= n; i++)
	{
		ch = getchar();
		c++;
		if (ch == 'P')
		{
			k = Min(p, c);
			l = Max(q, c);
			if (l-k == 2)
				if (c == k || c == l)
					d = (d+t[(n-i)>>1])%m;
				else
					d = (d+t[(n-i+1)>>1])%m;
			if (l-k == 1)
				d = (d+t[(n-i)>>1]+t[(n-i+1)>>1]-1+m)%m;
			c -= 2;
		}
		p = Min(p, c);
		q = Max(q, c);
	}
	printf("%d\n", (d+1)%m);
	return 0;
}
