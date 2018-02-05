#include <cstdio>
#include <set>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))

int n;
int c[10010];
int e[100010][3];
int *g[10010], *w[10010], deg[10010];
struct node
{
	int p;
} p, q;
int d[10010];
bool operator < (node a, node b)
{
	return d[a.p] < d[b.p] || d[a.p] == d[b.p] && a.p < b.p;
}
set<node> s;
int prim()
{
	int ret=0, i;
	for (i = 0; i < n; i++)
		d[i] = 123456789;
	d[0] = 0;
	p.p = 0;
	s.insert(p);
	while (!s.empty())
	{
		p = *s.begin();
		ret += d[p.p];
		d[p.p] = -1;
		s.erase(s.begin());
		for (i = 0; i < deg[p.p]; i++)
		{
			q.p = g[p.p][i];
			if (d[q.p] != -1)
				if (d[q.p] == 123456789)
				{
					d[q.p] = w[p.p][i];
					s.insert(q);
				}
				else
					if (d[q.p] > w[p.p][i])
					{
						s.erase(s.find(q));
						d[q.p] = w[p.p][i];
						s.insert(q);
					}
		}
	}
	return ret;
}
int main()
{
	freopen("cheer.in", "r", stdin);
	freopen("cheer.out", "w", stdout);
	int m, mc, i;
	scanf("%d%d", &n, &m);
	mc = 123456789;
	for (i = 0; i < n; i++)
	{
		scanf("%d", c+i);
		mc = Min(mc, c[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", e[i], e[i]+1, e[i]+2);
		deg[--e[i][0]]++;
		deg[--e[i][1]]++;
		e[i][2] += e[i][2]+c[e[i][0]]+c[e[i][1]];
	}
	for (i = 0; i < n; i++)
	{
		g[i] = new int[deg[i]+1];
		w[i] = new int[deg[i]+1];
		deg[i] = 0;
	}
	for (i = 0; i < m; i++)
	{
		g[e[i][0]][deg[e[i][0]]] = e[i][1];
		w[e[i][0]][deg[e[i][0]]] = e[i][2];
		g[e[i][1]][deg[e[i][1]]] = e[i][0];
		w[e[i][1]][deg[e[i][1]]] = e[i][2];
		deg[e[i][0]]++;
		deg[e[i][1]]++;
	}
	printf("%d\n", prim()+mc);
	return 0;
}
