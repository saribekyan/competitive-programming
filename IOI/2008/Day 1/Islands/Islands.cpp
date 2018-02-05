#include <stdio.h>
#define MAXN 1000010

int n;
long long ans, add;
int e[MAXN<<1][2], st[MAXN], end[MAXN], in[MAXN][2];
void init()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", in[i], in[i]+1);
		end[i]++;
		end[--in[i][0]]++;
	}
	st[0] = 0;
	for (i = 1; i < n; i++)
		st[i] = st[i-1]+end[i-1];
	for (i = 0; i < n; i++)
		end[i] = st[i];
	for (i = 0; i < n; i++)
	{
		e[end[i]][0] = in[i][0];
		e[end[in[i][0]]][0] = i;
		e[end[in[i][0]]++][1] = e[end[i]++][1] = in[i][1];
	}
}

int pr[MAXN];
int cycle[MAXN], len;
long long s[MAXN], a[MAXN];

int C[MAXN], T[MAXN];
void init_cycle(int u)
{
	int sz, v, i;
	sz = 0;
	C[sz] = u;
	T[sz++] = st[u];
	pr[u] = u;
	while (sz)
	{
		u = C[sz-1];
		for (i = T[sz-1]; i < end[u]; i++)
		{
			v = e[i][0];
			if (pr[v] == -1)
			{
				pr[v] = u;
				T[sz-1] = i+1;
				C[sz] = v;
				T[sz++] = st[v];
				break;
			}
			else
				if (pr[u] != v || pr[u] == v && in[u][0] == v && in[v][0] == u)
				{
					pr[v] = u;
					sz = 0;
					break;
				}
		}
		if (i == end[u])
			sz--;
	}
	len = 0;
	s[len] = 0;
	cycle[len++] = i = u;
	for (v = pr[u]; v != u; v = pr[v])
	{
		if (in[i][0] == v)
			s[len] = s[len-1]+in[i][1];
		else
			s[len] = s[len-1]+in[v][1];
		cycle[len++] = i = v;
	}
	if (in[i][0] == v)
		s[len] = s[len-1]+in[i][1];
	else
		s[len] = s[len-1]+in[v][1];
	cycle[len] = u;
}

bool vis[MAXN];
long long f[MAXN];
void tree_paths()
{
	long long t, x, y;
	int sz, l, prev, next, p, q, i;
	for (l = 0; l < len; l++)
	{
		sz = 0;
		p = cycle[l];
		vis[p] = 1;
		T[sz] = st[p];
		C[sz++] = cycle[l];
		if (l)
			prev = cycle[l-1];
		else
			prev = cycle[len-1];
		next = cycle[l+1];
		pr[p] = p;
		while (sz)
		{
			p = C[sz-1];
			if (T[sz-1] == end[p])
			{
				x = y = 0;
				for (i = st[p]; i < end[p]; i++)
					if (e[i][0] != pr[p] && e[i][0] != prev && e[i][0] != next)
					{
						t = f[e[i][0]]+e[i][1];
						if (t > x)
						{
							y = x;
							x = t;
						}
						else
							if (t > y)
								y = t;
					}
				if (add < x+y)
					add = x+y;
				f[p] = x;
				sz--;
			}
			else
			{
				q = e[T[sz-1]++][0];
				while (T[sz-1] < end[p] && (vis[q] || q == prev || q == next))
					q = e[T[sz-1]++][0];
				if (!vis[q] && q != prev && q != next)
				{
					C[sz] = q;
					T[sz++] = st[q];
					vis[q] = 1;
					pr[q] = p;
				}
			}
		}
		a[l] = f[cycle[l]];
	}
	a[len] = a[0];
}
long long d[MAXN][2];
void cycle_paths()
{
	int i;
	d[0][0] = a[0]-s[0];
	d[0][1] = a[0]+s[0];
	for (i = 1; i < len; i++)
	{
		if (d[i-1][0] > a[i]-s[i])
			d[i][0] = d[i-1][0];
		else
			d[i][0] = a[i]-s[i];
		if (d[i-1][1] > a[i]+s[i])
			d[i][1] = d[i-1][1];
		else
			d[i][1] = a[i]+s[i];
	}
	for (i = 1; i < len; i++)
	{
		if (add < a[i]+s[i]+d[i-1][0])
			add = a[i]+s[i]+d[i-1][0];
		if (add < s[len]+a[i]-s[i]+d[i-1][1])
			add = s[len]+a[i]-s[i]+d[i-1][1];
	}
}
void solve()
{
	int i;
	for (i = 0; i < n; i++)
		pr[i] = -1;
	for (i = 0; i < n; i++)
		if (pr[i] == -1)
		{
			add = 0;
			init_cycle(i);
			tree_paths();
			cycle_paths();
			ans += add;
		}
	printf("%I64d\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
