#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> ans[3010];
int x[3010], y[3010], vx[3010], vy[3010];
int main()
{
	long long t, k;
	int n, m, p, c, l, i;
	scanf("%d%d%d", &n, &m, &p);
	for (i = 0; i < p; i++)
		scanf("%d%d%d%d", x+i, y+i, vx+i, vy+i);
	scanf("%d", &l);
	while (l--)
	{
		scanf("%lld", &t);
		for (i = 0; i < p; i++)
		{
			if (vx[i] == 0)
				c = x[i];
			else
			{
				k = t%(2*n);
				if (vx[i] == 1)
					if (x[i]+k <= n)
						c = x[i]+k;
					else
						if (k <= 2*n-x[i])
							c = 2*n-k-x[i];
						else
							c = x[i]+k-2*n;
				else
					if (x[i]-k >= 0)
						c = x[i]-k;
					else
						if (k <= x[i]+n)
							c = k-x[i];
						else
							c = x[i]+2*n-k;
			}
			ans[i].first = c;
			if (vy[i] == 0)
				c = y[i];
			else
			{
				k = t%(2*m);
				if (vy[i] == 1)
					if (y[i]+k <= m)
						c = y[i]+k;
					else
						if (k <= 2*m-y[i])
							c = 2*m-k-y[i];
						else
							c = y[i]+k-2*m;
				else
					if (y[i]-k >= 0)
						c = y[i]-k;
					else
						if (k <= y[i]+m)
							c = k-y[i];
						else
							c = y[i]+2*m-k;
			}
			ans[i].second = c;
		}
		sort(ans, ans+p);
		for (i = 0; i < p; i++)
			printf("%d %d\n", ans[i].first, ans[i].second);
		if (l)
			putchar('\n');
	}
	return 0;
}
