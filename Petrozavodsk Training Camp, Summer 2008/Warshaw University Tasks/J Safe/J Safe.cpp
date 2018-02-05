#include <cstdio>
#include <algorithm>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))

typedef long long LL;
LL t[1000010];
char s[1000010];
LL p[2000010], d[2000010];
int main()
{
	LL n, m, r, k, l, c, i, j;
	scanf("%lld%lld%s", &m, &n, s+1);
	t[0] = -1;
	for (i = 1; i <= n; i++)
	{
		j = i-1;
		if (i == n)
			i = i;
		while (j)
		{
			if (s[t[j]+1] == s[i])
			{
				t[i] = t[j]+1;
				break;
			}
			j = t[j];
		}
	}
	for (i = 1; (i<<1) < n; i++)
		if (t[n-(n%i)-1]+i+1 == n)
			break;
	if ((i<<1) < n)
		n = i;
	else
		if ((t[n]<<1) >= n)
			n -= t[n];
	d[0] = 0;
	for (i = 1; i <= m; i++)
	{
		scanf("%lld", p+i);
		p[i] %= n;
	}
	r = n*m;
	sort(p+1, p+m+1);
	for (i = 1; i <= m; i++)
		p[i+m] = p[i]+n;
	for (i = 1; i <= (m<<1); i++)
		d[i] = d[i-1]+p[i];
	for (i = 1; i <= m; i++)
	{
		k = i;
		l = i+m-1;
		while (l-k > 1)
		{
			c = (l+k)>>1;
			if (p[c]-p[i] > (n>>1))
				l = c;
			else
				k = c;
		}
		if (p[l]-p[i] <= (n>>1))
			k = l;
		r = Min(r, d[k]-d[i]-(k-i)*p[i]+
			(n+p[i])*(i+m-k-1)-d[i+m-1]+d[k]);
	}
	printf("%lld\n", r);
	return 0;
}
