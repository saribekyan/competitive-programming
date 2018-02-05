#include <cstdio>
#include <algorithm>
using namespace std;

struct P
{
	long long x, y;
} v[60010], s;
bool operator < (P a, P b)
{
	if (a.y > 0)
	{
		if (b.y > 0)
			return a.x*b.y > a.y*b.x;
		if (b.y == 0)
			return b.x < 0;
		return 1;
	}
	if (a.y == 0)
	{
		if (b.y > 0)
			return a.x > 0;
		if (b.y == 0)
			return 0;
		return 1;
	}
	if (b.y >= 0)
		return 0;
	return a.x*b.y > a.y*b.x;
}
int main()
{
	long long ans;
	int n, p, q, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%lld%lld", &v[i].x, &v[i].y);
	sort(v, v+n);
	for (i = 1; i < n; i++)
		if (!(v[i] < v[i-1]) && !(v[i-1] < v[i]))
		{
			v[i].x += v[i-1].x;
			v[i].y += v[i-1].y;
			v[i-1].x = 0;
			v[i-1].y = 0;
		}
	for (p = i = 0; i < n; i++)
		if (v[i].x || v[i].y)
			v[p++] = v[i];
	n = p;
	for (i = 0; i < n; i++)
		v[i+n] = v[i];
	for (s.x = s.y = q = 0; q < n; q++)
	{
		if (s.x*s.x+s.y*s.y >= (s.x+v[q].x)*(s.x+v[q].x)+(s.y+v[q].y)*(s.y+v[q].y))
			break;
		s.x += v[q].x;
		s.y += v[q].y;
	}
	ans = s.x*s.x+s.y*s.y;
	for (p = 1; p < n; p++)
	{
		s.x -= v[p-1].x;
		s.y -= v[p-1].y;
		if (p == q)
		{
			s.x += v[q].x;
			s.y += v[q++].y;
		}
		while (q-p <= n)
		{
			if (s.x*s.x+s.y*s.y >= (s.x+v[q].x)*(s.x+v[q].x)+(s.y+v[q].y)*(s.y+v[q].y))
				break;
			s.x += v[q].x;
			s.y += v[q++].y;
		}
		if (ans < s.x*s.x+s.y*s.y)
			ans = s.x*s.x+s.y*s.y;
	}
	printf("%lld\n", ans);
	return 0;
}
