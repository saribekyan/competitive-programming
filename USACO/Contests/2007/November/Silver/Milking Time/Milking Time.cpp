#include <cstdio>
#include <algorithm>
using namespace std;
#define Max(a, b) ((a)>(b)?(a):(b))

int d[1010];
pair<pair<int,int>, int> intervals[1010];
int main()
{
	freopen("milkprod.in", "r", stdin);
	freopen("milkprod.out", "w", stdout);
	int n, m, r, p, q, w, i, j;
	scanf("%d%d%d", &n, &m, &r);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &p, &q, &w);
		intervals[i] = make_pair(make_pair(q, p), w);
	}
	d[0] = 0;
	sort(intervals+1, intervals+m+1);
	for (i = 1; i <= m; i++)
	{
		d[i] = intervals[i].second;
		for (j = i-1; j > 0; j--)
		{
			if (intervals[j].first.first+r <= intervals[i].first.second)
				d[i] = Max(d[i], d[j]+intervals[i].second);
			d[i] = Max(d[i], d[j]);
		}
	}
	printf("%d\n", d[m]);
	return 0;
}
