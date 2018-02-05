#include <cstdio>
#include <algorithm>
using namespace std;

int m, n;
int r[50010][4], g[50010];
struct P
{
	bool op;
	int x, y;
} d[200010], u, v;
bool operator < (P a, P b)
{
	if (a.x < b.x)return 1;
	if (a.x > b.x)return 0;
	if (a.y < b.y)return 1;
	if (a.y > b.y)return 0;
	if (a.op == b.op)return 0;
	return a.op;
}
bool operator == (P a, P b)
{
	return a.x == b.x && a.y == b.y && a.op == b.op;
}
int c[200010], p[200010];
int my_find(P x)
{
	int p, q, k;
	p = 0;
	q = m-1;
	while (q-p > 1)
	{
		k = ((p+q)>>1);
		if (d[k] == x)
			return k;
		if (d[k] < x)
			p = k;
		else
			q = k;
	}
	if (d[p] == x)
		return p;
	if (d[q] == x)
		return q;
}
void solve()
{
	int i, k, l;
	for (m = i = 0; i < n; i++, m+=4)
	{
		d[m].x = d[m+1].x = r[i][0];
		d[m].y = d[m+2].y = r[i][1];
		d[m+2].x = d[m+3].x = r[i][2];
		d[m+1].y = d[m+3].y = r[i][3];
		d[m].op = d[m+2].op = 1;
		d[m+1].op = d[m+3].op = 0;
	}
	sort(d, d+m);
	c[0] = 1;
	p[0] = 0;
	for (i = 1; i < m; i++)
		if (d[i].x != d[i-1].x)
		{
			c[i] = 1;
			p[i] = 0;
		}
		else
		{
			c[i] = c[i-1]+2*(d[i].op)-1;
			p[i] = p[i-1]+(!d[i].op);
		}
	for (i = 0; i < n; i++)
	{
		u.op = 1;
		v.op = 0;
		u.y = r[i][1];
		v.y = r[i][3];
		u.x = v.x = r[i][2];
		k = my_find(u);
		l = my_find(v);
		g[i] += (int)(c[k] == 1 && c[l] == 0 && p[k]+1 == p[l]);
		u.x = v.x = r[i][0];
		k = my_find(u);
		l = my_find(v);
		g[i] += (int)(c[k] == 1 && c[l] == 0 && p[k]+1 == p[l]);
	}
}
int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int i, j;
	scanf("%d", &n);
	memset(g, 0, sizeof(g));
	for (i = 0; i < n; i++)
		for (j = 0; j < 4; j++)
			scanf("%d", r[i]+j);
	solve();
	for (i = 0; i < n; i++)
	{
		swap(r[i][0], r[i][1]);
		swap(r[i][2], r[i][3]);
	}
	solve();
	for (j = i = 0; i < n; i++)
		j += (int)(g[i] == 4);
	printf("%d\n", j);
	return 0;
}
