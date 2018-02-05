/*
PROG: apples
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define Max(a, b) ((a)>(b)?(a):(b))

struct P
{
	long long x, y, t;
} p[5010];
bool operator < (P a, P b)
{
	return a.t < b.t;
}
int d[5010];
int main()
{
	freopen("apples.in", "r", stdin);
	freopen("apples.out", "w", stdout);
	long long s;
	int n, m, i, j;
	scanf("%d%lld", &n, &s);
	for (i = 0; i < n; i++)
		scanf("%lld%lld%lld", &p[i].x, &p[i].y, &p[i].t);
	m = 0;
	sort(p, p+n);
	for (i = 0; i < n; i++)
	{
		d[i] = (p[i].t*p[i].t*s*s >= p[i].x*p[i].x+p[i].y*p[i].y);
		for (j = 0; j < i; j++)
			if (d[j] && (p[i].t-p[j].t)*(p[i].t-p[j].t)*s*s >= (p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y))
				d[i] = Max(d[i], d[j]+1);
		m = Max(m, d[i]);
	}
	printf("%d\n", m);
	return 0;
}
