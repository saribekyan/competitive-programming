#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct P
{
	int x, y;
} p[50010], q;
int d[50010];
queue<int> Q;
bool operator < (P a, P b)
{
	return a.x < b.x || a.x == b.x && a.y < b.y;
}
int main()
{
	freopen("cavecow4.in", "r", stdin);
	freopen("cavecow4.out", "w", stdout);
	int n, t, k, l, i;
	scanf("%d%d", &n, &t);
	p[0].x = p[0].y = 0;
	for (i = 1; i <= n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	sort(p+1, p+n+1);
	memset(d, -1, sizeof(d));
	d[0] = 0;
	Q.push(0);
	while (!Q.empty())
	{
		k = Q.front();
		if (p[k].y == t)
		{
			printf("%d\n", d[k]);
			return 0;
		}
		Q.pop();
		for (q.x = p[k].x-2; q.x <= p[k].x+2; q.x++)
			for (q.y = p[k].y-2; q.y <= p[k].y+2; q.y++)
				if (binary_search(p+1, p+n+1, q))
				{
					l = lower_bound(p+1, p+n+1, q)-p;
					if (l != n+1 && d[l] == -1)
					{
						d[l] = d[k]+1;
						Q.push(l);
					}
				}
	}
	printf("-1\n");
	return 0;
}
