#include <cstdio>
#include <queue>
using namespace std;

int t[1010][1010];
struct point
{
	int x, y;
} p, q, b;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
queue<point> Q;
int main()
{
	freopen("mud.in", "r", stdin);
	freopen("mud.out", "w", stdout);
	int n, i;
	scanf("%d%d%d", &b.x, &b.y, &n);
	memset(t, -1, sizeof(t));
	b.x += 501;
	b.y += 501;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &p.x, &p.y);
		t[p.x+501][p.y+501] = 0;
	}
	p.x = p.y = 501;
	Q.push(p);
	t[p.x][p.y] = 0;
	while (!Q.empty())
	{
		p = Q.front();
		if (p.x == b.x && p.y == b.y)
		{
			printf("%d\n", t[b.x][b.y]);
			return 0;
		}
		Q.pop();
		if (p.x == 502 && p.y == 504)
			i = i;
		for (i = 0; i < 4; i++)
		{
			q.x = p.x+dx[i];
			q.y = p.y+dy[i];
			if (q.x >= 0 && q.x <= 1002 && q.y >= 0 && q.y <= 1002 && t[q.x][q.y] == -1)
			{
				t[q.x][q.y] = t[p.x][p.y]+1;
				Q.push(q);
			}
		}
	}
	printf("-1\n");
	return 0;
}
