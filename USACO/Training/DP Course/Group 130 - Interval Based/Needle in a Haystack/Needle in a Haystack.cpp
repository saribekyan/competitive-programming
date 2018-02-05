/*
PROG: haystack
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define inf 1000000000

struct P
{
	int x, y;
} p[210];
bool operator < (P a, P b)
{
	return a.x < b.x;
}
int d[210][210][2];
int solve(int l, int r, int s)
{
	int &it = d[l][r][s];
	if (it != -1)
		return it;
	if (l > r)
		return it = 0;
	int k, i;
	if (s == 0)
		k = l-1;
	else
		k = r+1;
	if (l == r)
		return it = abs(p[k].x-p[l].x)+abs(p[k].y)+abs(p[l].y);
	it = inf;
	for (i = l; i <= r; i++)
		it = min(it, max(solve(l, i-1, 1), solve(i+1, r, 0))+abs(p[i].x-p[k].x)+abs(p[i].y)+abs(p[k].y));
	return it;
}
int main()
{
	freopen("haystack.in", "r", stdin);
	freopen("haystack.out", "w", stdout);
	int m, n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	m = inf;
	sort(p, p+n);
	memset(d, -1, sizeof(d));
	for (i = 0; i < n; i++)
		m = min(m, max(solve(0, i-1, 1), solve(i+1, n-1, 0))+abs(p[i].x)+abs(p[i].y));
	printf("%d\n", m);
	return 0;
}
