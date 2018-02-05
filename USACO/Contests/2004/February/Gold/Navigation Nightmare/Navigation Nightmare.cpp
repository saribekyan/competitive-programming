#include <cstdio>
#include <algorithm>
using namespace std;
#define inf (1000000000LL)

int ans[40010];
struct query
{
	int s, t, i, in;
} q[40010];

bool operator < (query a, query b)
{
	return a.i < b.i;
}
bool t[40010];
char ch[40010];
int e[40010][3];
int *g[40010], *x[40010], *y[40010], deg[40010];

long long dx[40010], dy[40010], df, st, end;
void update(int p)
{
	int i;
	for (i = 0; i < deg[p]; i++)
		if (dx[g[p][i]] >= st && dx[g[p][i]] < end)
		{
			dx[g[p][i]] = dx[p]-x[p][i];
			dy[g[p][i]] = dy[p]-y[p][i];
			update(g[p][i]);
		}
}
int main()
{
	freopen("navigate.in", "r", stdin);
	freopen("navigate.out ", "w", stdout);
	int n, m, p, i, j;
	scanf("%d%d", &n, &m);
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d%c%c", e[i], e[i]+1, e[i]+2, ch+i, ch+i);
		deg[--e[i][0]]++;
		deg[--e[i][1]]++;
	}
	scanf("%d", &p);
	for (i = 0; i < p; i++)
	{
		scanf("%d%d%d", &q[i].s,  &q[i].t, &q[i].i);
		q[i].s--;
		q[i].t--;
		q[i].i--;
		q[i].in = i;
	}
	sort(q, q+p);
	for (i = 0; i < n; i++)
	{
		x[i] = new int[deg[i]+1];
		y[i] = new int[deg[i]+1];
		g[i] = new int[deg[i]+1];
		deg[i] = 0;
	}
	for (i = 0; i < n; i++)
		dx[i] = dy[i] = i*inf+inf/2;
	for (i = j = 0; i < m && j < p; i++)
	{
		g[e[i][0]][deg[e[i][0]]] = e[i][1];
		g[e[i][1]][deg[e[i][1]]] = e[i][0];
		if (ch[i] == 'N' || ch[i] == 'S')
			x[e[i][0]][deg[e[i][0]]] = x[e[i][1]][deg[e[i][1]]] = 0;
		else
			y[e[i][0]][deg[e[i][0]]] = y[e[i][1]][deg[e[i][1]]] = 0;
		if (ch[i] == 'N')
		{
			y[e[i][0]][deg[e[i][0]]] = -e[i][2];
			y[e[i][1]][deg[e[i][1]]] = e[i][2];
		}
		if (ch[i] == 'S')
		{
			y[e[i][0]][deg[e[i][0]]] = e[i][2];
			y[e[i][1]][deg[e[i][1]]] = -e[i][2];
		}
		if (ch[i] == 'E')
		{
			x[e[i][0]][deg[e[i][0]]] = -e[i][2];
			x[e[i][1]][deg[e[i][1]]] = e[i][2];
		}
		if (ch[i] == 'W')
		{
			x[e[i][0]][deg[e[i][0]]] = e[i][2];
			x[e[i][1]][deg[e[i][1]]] = -e[i][2];
		}
		deg[e[i][0]]++;
		deg[e[i][1]]++;

		if (dx[e[i][0]]/inf != dx[e[i][1]]/inf)
		{
			st = inf*(dx[e[i][1]]/inf);
			end = st+inf;
			dx[e[i][1]] = dx[e[i][0]]-x[e[i][0]][deg[e[i][0]]-1];
			dy[e[i][1]] = dy[e[i][0]]-y[e[i][0]][deg[e[i][0]]-1];
			update(e[i][1]);
		}
		while (i == q[j].i)
		{
			if (dx[q[j].s]/inf == dx[q[j].t]/inf)
				ans[q[j].in] = abs(dx[q[j].s]-dx[q[j].t])+abs(dy[q[j].s]-dy[q[j].t]);
			else
				ans[q[j].in] = -1;
			j++;
		}
	}
	for (i = 0; i < p; i++)
		printf("%d\n", ans[i]);
	return 0;
}
