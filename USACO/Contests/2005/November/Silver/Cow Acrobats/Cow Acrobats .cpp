#include <cstdio>
#include <algorithm>
using namespace std;
#define inf 1000000000

struct cow
{
	int w, s;
} d[50010];
bool operator < (cow a, cow b)
{
	return a.s < b.s;
}
int main()
{
	freopen("acrobat.in", "r", stdin);
	freopen("acrobat.out", "w", stdout);
	int n, s, r, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &d[i].w, &d[i].s);
		d[i].s += d[i].w;
	}
	s = 0;
	r = inf;
	sort(d, d+n);
	for (i = 0; i < n; i++)
	{
		s += d[i].w;
		if (r < s-d[i].s)
			r = s-d[i].s;
	}
	printf("%d\n", r);
	return 0;
}
