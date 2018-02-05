#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 2000000000
#define eps (1e-9)
const double pi = 2*acos(0.0);

struct P
{
	long long x, y;
} t[100010], as[100010];
bool intersect(P s, int dir, P a, P b)
{
	if (a.y < b.y)
		swap(a, b);
	if (a.y < s.y || b.y > s.y)
		return 0;
	P p;
	p.y = s.y;
	p.x = s.x+dir;
	double a1 = acos((1.0+(a.x-s.x)*(a.x-s.x)+(a.y-s.y)*(a.y-s.y)-(a.x-p.x)*(a.x-p.x)-(a.y-p.y)*(a.y-p.y))/
		(2*sqrt((a.x-s.x)*(a.x-s.x)+(a.y-s.y)*(a.y-s.y)*1.0)));
	double a2 = acos((1.0+(b.x-s.x)*(b.x-s.x)+(b.y-s.y)*(b.y-s.y)-(b.x-p.x)*(b.x-p.x)-(b.y-p.y)*(b.y-p.y))/
		(2*sqrt((b.x-s.x)*(b.x-s.x)+(b.y-s.y)*(b.y-s.y)*1.0)));
	return a1+a2 <= pi+eps;
}
int main()
{
	int n, m, i;
	P a, b, c, d;
	scanf("%d", &n);
	a.y = -inf;
	b.y = inf;
	c.y = -inf;
	d.y = inf;
	for (i = 0; i < n; i++)
	{
		scanf("%lld%lld", &t[i].x, &t[i].y);
		if (a.y < t[i].y)
			a = t[i];
		if (b.y > t[i].y)
			b = t[i];
	}
	t[n] = t[0];
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%lld%lld", &as[i].x, &as[i].y);
		if (c.y < as[i].y)
			c = as[i];
		if (d.y > as[i].y)
			d = as[i];
	}
	as[m] = as[0];
	for (i = 0; i < m; i++)
		if (intersect(a, 1, as[i], as[i+1]) ||
			intersect(b, 1, as[i], as[i+1]))
		{
			printf("YES\n");
			return 0;
		}
	for (i = 0; i < n; i++)
		if (intersect(c, -1, t[i], t[i+1]) ||
			intersect(d, -1, t[i], t[i+1]))
		{
			printf("YES\n");
			return 0;
		}
	printf("NO\n");
	return 0;
}
