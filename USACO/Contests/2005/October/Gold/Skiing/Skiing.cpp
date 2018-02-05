#include <cstdio>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define eps (1e-9)
#define inf 1000000000000.0

int n, m, v;
int h[110][110];
double d[110][110];
int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};
priority_queue<pair<double, pair<int, int> >, vector<pair<double, pair<int, int> > >, greater<pair<double, pair<int, int> > > > Q;
int main()
{
	freopen("cowski.in", "r", stdin);
	freopen("cowski.out", "w", stdout);
	int i, j;
	double t;
	pair<double, pair<int, int> > p, q;
	scanf("%d%d%d", &v, &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			scanf("%d", h[i]+j);
			d[i][j] = inf;
		}
	d[0][0] = 0.0;
	Q.push(make_pair(0.0, make_pair(0, 0)));
	while (!Q.empty())
	{
		p = Q.top(); Q.pop();
		if (p.second == make_pair(n-1, m-1))
		{
			printf("%.2lf\n", p.first);
			return 0;
		}
		if (fabs(p.first-d[p.second.first][p.second.second]) > eps)
			continue;
		t = pow(0.5, h[0][0]-h[p.second.first][p.second.second]+0.0)/v;
		for (i = 0; i < 4; i++)
		{
			q.second.first = p.second.first+di[i];
			q.second.second = p.second.second+dj[i];
			if (q.second.first >= 0 && q.second.first < n &&
				q.second.second >= 0 && q.second.second < m &&
				d[q.second.first][q.second.second] > p.first+t+eps)
			{
				d[q.second.first][q.second.second] = q.first = p.first+t;
				Q.push(q);
			}
		}
	}
	printf("-1.00\n");
	return 0;
}
