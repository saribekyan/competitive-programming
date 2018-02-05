#include <stdio.h>
#include <string.h>
#define N 100001
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

int a[100010];
int l[200010];
int d[20][200010];
int s[200010], t[200010];
int main()
{
	int n, m, p, q, x, y, r, i, j;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			return 0;
		scanf("%d", &m);
		memset(d, 0, sizeof(d));
		memset(t, 0, sizeof(t));
		for (i = 0; i <= 2*N; i++)
			s[i] = 10000000;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", a+i);
			a[i] += N;
			d[0][a[i]]++;
			s[a[i]] = Min(s[a[i]], i);
			t[a[i]] = Max(t[a[i]], i);
		}
		n = 2*N;
		for (i = 1; i <= n; i++)
		{
			p = i;
			l[i] = 0;
			while (p)
			{
				l[i]++;
				p >>= 1;
			}
		}
		for (i = 1; i < l[n]; i++)
			for (j = 1; j+(1<<i) <= n; j++)
				d[i][j] = Max(d[i-1][j], d[i-1][j+(1<<(i-1))]);
		while (m)
		{
			scanf("%d%d", &x, &y);
			if (a[x] == a[y])
				printf("%d\n", y-x+1);
			else
			{
				r = 0;
				p = a[t[a[x]]+1];
				q = a[s[a[y]]-1];
				if (q >= p)
					r = Max(d[l[q-p+1]-1][p], d[l[q-p+1]-1][q-(1<<(l[q-p+1]-1))+1]);
				printf("%d\n", Max(r, Max(y-s[a[y]]+1, t[a[x]]-x+1)));
			}
			m--;
		}
	}
	return 0;
}
