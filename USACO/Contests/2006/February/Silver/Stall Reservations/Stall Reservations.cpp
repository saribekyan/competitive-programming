#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

set<int> s;
struct point
{
	int i;
	int coord;
	bool open;
} d[100010];
int ans[50010];
bool operator < (point a, point b)
{
	if (a.coord == b.coord && a.open == b.open)
		return 0;
	return a.coord < b.coord || a.coord == b.coord && a.open;
}
int main()
{
	freopen("reserve.in", "r", stdin);
	freopen("reserve.out", "w", stdout);
	int n, m, p, i;
	scanf("%d", &n);
	for (i = 0; i < 2*n; i+=2)
	{
		scanf("%d%d", &d[i].coord, &d[i+1].coord);
		d[i].i = d[i+1].i = i/2;
		d[i].open = 1;
		d[i+1].open = 0;
	}
	sort(d, d+2*n);
	m = 0;
	for (i = 0; i < n; i++)
		s.insert(i+1);
	for (i = 0; i < 2*n; i++)
		if (d[i].open)
		{
			p = *s.begin();
			s.erase(s.begin());
			m = max(m, p);
			ans[d[i].i] = p;
		}
		else
			s.insert(ans[d[i].i]);
	printf("%d\n", m);
	for (i = 0; i < n; i++)
		printf("%d\n", ans[i]);
	return 0;
}
