#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

struct P
{
	double x, y;
} p[10000];
bool cmp(P a, P b)
{
	return a.x < b.x || a.x == b.x && a.y < b.y;
}
bool operator < (P a, P b)
{
	return a.y < b.y || a.y == b.y && a.x < b.x;
}
double dist(P a, P b)
{
	return hypot(a.x-b.x, a.y-b.y);
}
multiset<P> s;
int main()
{
	P a, b;
	int n, st, i;
	double l;
	multiset<P>::iterator I, J;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%lf%lf", &p[i].x, &p[i].y);
	sort(p, p+n, cmp);
	l = 987651321;
	s.insert(p[0]);
	st = 0;
	for (i = 1; i < n; i++)
	{
		a = b = p[i];
		a.y -= l;
		b.y += l;
		J = s.upper_bound(b);
		for (I = s.lower_bound(a); I != J; ++I)
			l = min(l, dist(p[i], (*I)));
		s.insert(p[i]);
		while (p[i].x-p[st].x >= l && st < i)
		{
			s.erase(p[st]);
			st++;
		}
	}
	printf("%.5lf\n", l);
	return 0;
}
