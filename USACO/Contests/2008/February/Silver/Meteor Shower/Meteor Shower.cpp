#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int,int> > Q;
int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};
int bum[310][310], t[310][310];
bool check(pair<int,int> p)
{
	return (p.first >= 0 && p.first <= 305 && p.second >= 0 && p.second <= 305);
}
int main()
{
	freopen("meteor.in", "r", stdin);
	freopen("meteor.out", "w", stdout);
	int n, m, i, j;
	pair<int,int> p, q;
	scanf("%d", &n);
	for (i = 0; i <= 305; i++)
		for (j = 0; j <= 305; j++)
			bum[i][j] = 123456789;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d", &p.first, &p.second, &m);
		bum[p.first][p.second] = min(bum[p.first][p.second], m);
		for (j = 0; j < 4; j++)
		{
			q.first = p.first+di[j];
			q.second = p.second+dj[j];
			if (check(q))
				bum[q.first][q.second] = min(bum[q.first][q.second], m);
		}
	}
	p = make_pair(0, 0);
	memset(t, -1, sizeof(t));
	t[p.first][p.second] = 0;
	Q.push(p);
	while (!Q.empty())
	{
		p = Q.front();
		if(bum[p.first][p.second] == 123456789)
		{
			printf("%d\n", t[p.first][p.second]);
			return 0;
		}
		Q.pop();
		for (i = 0; i < 4; i++)
		{
			q.first = p.first+di[i];
			q.second = p.second+dj[i];
			if (check(q) && t[q.first][q.second] == -1 && bum[q.first][q.second] > t[p.first][p.second]+1)
			{
				t[q.first][q.second] = t[p.first][p.second]+1;
				Q.push(q);
			}
		}
	}
	printf("-1\n");
	return 0;
}
