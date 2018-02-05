#include <stdio.h>

int main()
{
	int t, l, n, m, p, q, d, i, ans;
	scanf("%d", &t);
	for (l = 1; l <= t; l++)
	{
		scanf("%d%d", &m, &n);
		ans = 1000000000;
		if (m%2==0)
		{
			p = q = 0;
			while (m%2==0)
			{
				m /= 2;
				p++;
			}
			d = 2;
			while (d<=n)
			{
				q+=n/d;
				d *= 2;
			}
			ans = q/p;
		}
		for (i = 3; i*i <= m; i+=2)
			if (m%i==0)
			{
				p = q = 0;
				while (m%i==0)
				{
					m/=i;
					p++;
				}
				d = i;
				while (d<=n)
				{
					q += n/d;
					d *= i;
				}
				if (ans>q/p)
					ans = q/p;
			}
		if (m!=1)
		{
			p = m;
			q = 0;
			while (p<=n)
			{
				q += n/p;
				p *= m;
			}
			if (q < ans)ans = q;
		}
		printf("Case %d:\n", l);
		if (ans==0)printf("Impossible to divide\n");
		else printf("%d\n", ans);
	}
	return 0;
}