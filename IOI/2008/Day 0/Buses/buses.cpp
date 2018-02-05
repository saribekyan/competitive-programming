#include <stdio.h>
#include <string.h>
#define inf 1000000000
#define Min(a, b) ((a)<(b)?(a):(b))

#define swap_i(a, b) {a^=b;b^=a;a^=b;}
#define swap_p(a, b) {a.x^=b.x;b.x^=a.x;a.x^=b.x;a.y^=b.y;b.y^=a.y;a.y^=b.y;}

int p, n;
int g[110][110];
int l[110], f[110];
struct P
{
	int x, y;
} r[110][60], a, b;

int abs(int w)
{
	if (w < 0)
		return -w;
	return w;
}

int D(P p, P q, P u, P v)
{
	if (p.x > q.x)
		swap_p(p, q);
	if (p.y > q.y)
		swap_i(p.y, q.y);
	if (u.x > v.x)
		swap_p(u, v);
	if (u.y > v.y)
		swap_i(u.y, v.y);
	int ret, i, j, k, l;
	ret = inf;
	if (p.x != q.x)
	{
		swap_p(p, u);
		swap_p(q, v);
	}
	if (u.x <= p.x && v.x >= p.x && p.y <= u.y && q.y >= u.y)
		return 0;
	if (u.x >= p.x && u.x <= q.x || p.x >= u.x && p.x <= v.x)
	{
		i = abs(p.y-u.y);
		j = abs(p.y-v.y);
		k = abs(q.y-u.y);
		l = abs(q.y-v.y);
		ret = Min(Min(i, j), Min(k, l));
	}
	if (u.y >= p.y && u.y <= q.y || p.y >= u.y && p.y <= v.y)
	{
		i = abs(p.x-u.x);
		j = abs(p.x-v.x);
		k = abs(q.x-u.x);
		l = abs(q.x-v.x);
		ret = Min(ret, Min(Min(i, j), Min(k, l)));
	}
	i = abs(p.x-u.x)+abs(p.y-u.y);
	j = abs(p.x-v.x)+abs(p.y-v.y);
	k = abs(q.x-u.x)+abs(q.y-u.y);
	l = abs(q.x-v.x)+abs(q.y-v.y);
	return Min(ret, Min(Min(i, j), Min(k, l)));
}

bool t[110];
int d[310][110];
void dijkstra(int s, int c)
{
	int k, i;
	memset(t, 0, sizeof(t));
	while (1)
	{
		k = -1;
		for (i = 0; i <= n; i++)
			if (!t[i] && (k == -1 || d[c][k] > d[c][i]))
				k = i;
		if (k == -1 || d[c][k] == inf)
			return;
		t[k] = 1;
		for (i = 0; i <= n; i++)
			if (!t[i] && g[k][i] == 0 && d[c][i] > d[c][k]+f[k])
				d[c][i] = d[c][k]+f[k];
	}
}
int main()
{
	int gr, i, j, k, c;
	scanf("%d%d%d%d%d%d", &p, &a.x, &a.y, &b.x, &b.y, &n);
	f[0] = 0;
	l[0] = 1;
	r[0][0] = r[0][1] = a;
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", l+i, f+i);
		for (j = 0; j < l[i]; j++)
			scanf("%d%d", &r[i][j].x, &r[i][j].y);
		r[i][l[i]] = r[i][0];
	}
	n++;
	f[n] = 0;
	l[n] = 1;
	r[n][0] = r[n][1] = b;
	for (i = 0; i <= n; i++)
		for (j = i+1; j <= n; j++)
			if (i == j)
				g[i][j] = 0;
	else
	{
		g[i][j] = inf;
		for (k = 0; k < l[i]; k++)
			for (c = 0; c < l[j]; c++)
			{
				gr = D(r[i][k], r[i][k+1], r[j][c], r[j][c+1]);
				g[i][j] = g[j][i] = Min(g[i][j], gr);
			}
	}
	gr = inf;
	for (i = 0; i <= p; i++)
		for (j = 0; j <= n; j++)
			d[i][j] = inf;
	d[0][0] = 0;
	for (i = 0; i <= p; i++)
	{
		c = 0;
		for (j = 1; j <= n; j++)
			if (d[i][j] < d[i][c])
				c = i;
		dijkstra(c, i);
		for (j = 0; j <= n; j++)
			for (k = 0; k <= n; k++)
				if (i+g[j][k] <= p && d[i+g[j][k]][k] > d[i][j]+f[j])
					d[i+g[j][k]][k] = d[i][j]+f[j];
		gr = Min(gr, d[i][n]);
	}
	if (gr == inf)
		printf("-1\n");
	else
		printf("%d\n", gr);
	return 0;
}
