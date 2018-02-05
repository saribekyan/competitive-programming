#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-9;
const double pi = 2.0*acos(0.0);

int ans, l, m;
struct P
{
	int x, y;
} p, q, c, s;

int prod(P a, P p, P b)
{
	long long d = (a.x-p.x+(0LL))*(b.y-p.y+(0LL))-(a.y-p.y+(0LL))*(b.x-p.x+(0LL));
	if (d > 0)
		return 1;
	if (d < 0)
		return -1;
	return 0;
}

double polar(P p, P a)
{
	if (a.x-p.x < eps && p.x-a.x < eps)
	{
		if (a.y > p.y)
			return pi/2;
		return 3*pi/2;
	}
	if (a.x > p.x)
	{
		if (a.y > p.y)
			return atan((a.y-p.y)*1.0/(a.x-p.x));
		return 2*pi-atan((p.y-a.y)*1.0/(a.x-p.x));
	}
	if (a.y > p.y)
		return pi-atan((a.y-p.y)*1.0/(p.x-a.x));
	return pi+atan((p.y-a.y)*1.0/(p.x-a.x));
}

struct interval
{
	double angle;
	bool open;
} d[100010];
bool operator < (interval a, interval b)
{
	return a.angle+eps < b.angle || a.angle-b.angle <= eps && a.open && !b.open;
}

int cur[100010];
int main()
{
	freopen("boundary.in", "r", stdin);
	freopen("boundary.out", "w", stdout);
	double high, low, angle;
	int n, a, b, k, i, j;
	scanf("%d%d%d%d", &l, &n, &s.x, &s.y);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d", &j, &c.x, &c.y);
		p = q = c;
		while (j-- > 1)
		{
			scanf("%d%d", &c.x, &c.y);
			if (prod(p, s, c) > 0)
				p = c;
			if (prod(q, s, c) < 0)
				q = c;
		}
		high = polar(s, p);
		low = polar(s, q);
		if (low > high)
		{
		//	high += 2*pi;
			d[m].angle = low-2*pi;
			d[m++].open = 1;
			d[m].angle = high;
			d[m++].open = 0;

			d[m].angle = low;
			d[m++].open = 1;
			d[m].angle = high+2*pi;
			d[m++].open = 0;
		}
		else
		{
			d[m].angle = low;
			d[m++].open = 1;
			d[m].angle = high;
			d[m++].open = 0;
		}
	}
	d[m].angle = -5*pi;
	d[m++].open = 0;
	d[m].angle = 5*pi;
	d[m++].open = 0;
	sort(d, d+m);
/////////////////////////
	for (i = 1; i < m; i++)
		if (d[i].open)
			cur[i] = cur[i-1]+1;
		else
			cur[i] = cur[i-1]-1;
	c.x = 0;
	for (c.y = 0; c.y < l; c.y++)
	{
		angle = polar(s, c);
		a = 0;
		b = m-1;
		while (b-a > 1)
		{
			k = (a+b)>>1;
			if (d[k].angle > angle+eps)
				b = k;
			else
				if (angle-d[k].angle <= eps)
					break;
				else
					a = k;
		}
		if (cur[a] == 0 && b-a <= 1)
			ans++;
	}
	c.y = l;
	for (c.x = 0; c.x < l; c.x++)
	{
		angle = polar(s, c);
		a = 0;
		b = m-1;
		while (b-a > 1)
		{
			k = (a+b)>>1;
			if (d[k].angle > angle+eps)
				b = k;
			else
				if (angle-d[k].angle <= eps)
					break;
				else
					a = k;
		}
		if (cur[a] == 0 && b-a <= 1)
			ans++;
	}
	c.x = l;
	for (c.y = l; c.y > 0; c.y--)
	{
		angle = polar(s, c);
		a = 0;
		b = m-1;
		while (b-a > 1)
		{
			k = (a+b)>>1;
			if (d[k].angle > angle+eps)
				b = k;
			else
				if (angle-d[k].angle <= eps)
					break;
				else
					a = k;
		}
		if (cur[a] == 0 && b-a <= 1)
			ans++;
	}
	c.y = 0;
	for (c.x = l; c.x > 0; c.x--)
	{
		angle = polar(s, c);
		a = 0;
		b = m-1;
		while (b-a > 1)
		{
			k = (a+b)>>1;
			if (d[k].angle > angle+eps)
				b = k;
			else
				if (angle-d[k].angle <= eps)
					break;
				else
					a = k;
		}
		if (cur[a] == 0 && b-a <= 1)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
