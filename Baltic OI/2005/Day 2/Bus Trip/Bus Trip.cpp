#include <cstdio>
#include <algorithm>
using namespace std;

int d[100010], w[100010];
int st[50010], end[50010];
struct bus
{
	int p, q, s, w, t;
} e[100010];
bool operator < (bus a, bus b)
{
	return a.t < b.t;
}
int main()
{
	freopen("trip.in", "r", stdin);
	freopen("trip.out", "w", stdout);
	int n, m, u, t, p, q, k, i;
	scanf("%d%d%d%d", &n, &m,  &u, &t);
	u--;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d%d%d%d", &e[i].p, &e[i].q, &e[i].s, &p, &q, &e[i].t);
		e[i].w = p-e[i].s+e[i].t-q;
		end[--e[i].q]++;
		e[i].p--;
	}
	end[0]++;
	st[0] = 0;
	for (i = 1; i <= n; i++)
	{
		st[i] = st[i-1]+end[i-1];
		end[i-1] = st[i-1];
	}
	sort(e, e+m);
	d[end[0]++] = w[end[0]] = 0;
	for (i = 0; i < m; i++)
	{
		if (e[i].q > t || st[e[i].p] == end[e[i].p] || d[st[e[i].p]] > e[i].s)
			continue;
		p = st[e[i].p];
		q = end[e[i].p]-1;
		while (q-p > 1)
		{
			k = (p+q)>>1;
			if (d[k] <= e[i].s)
				p = k;
			else
				q = k;
		}
		if (d[q] <= e[i].s)
			p = q;
		d[end[e[i].q]] = e[i].t;
		w[end[e[i].q]] = w[p]+e[i].s-d[p]+e[i].w;
		if (st[e[i].q] != end[e[i].q] && w[end[e[i].q]] > w[end[e[i].q]-1]+e[i].t-d[end[e[i].q]-1])
			w[end[e[i].q]] = w[end[e[i].q]-1]+e[i].t-d[end[e[i].q]-1];
		end[e[i].q]++;
	}
	if (st[u] == end[u])
		printf("-1\n");
	else
	{
		p = st[u];
		q = end[u]-1;
		while (q-p > 1)
		{
			k = (p+q)>>1;
			if (d[k] <= t)
				p = k;
			else
				q = k;
		}
		if (d[q] <= t)
			p = q;
		printf("%d\n", w[p]+t-d[p]);
	}
	return 0;
}
