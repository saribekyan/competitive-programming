#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
long long s1, s2, s3, s;
int dep[500010], num[500010];
struct P
{
	int i;
	char c;
	long long x, y;
} d[100010], st[500010];
bool operator < (P a, P b)
{
	return a.x < b.x;
}
long long area(P a, P b, P c)
{
	long long ret = a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x;
	if (ret < 0)
		return -ret;
	return ret;
}
void solve(int a, int b, int c, int depth)
{
	int cc = -1, i;
	s = area(d[a], d[b], d[c]);
	for (i = m-1; dep[i]+1 == depth && i >= 0; i--)
	{
		s1 = area(d[a], d[b], st[i]);
		s2 = area(d[b], d[c], st[i]);
		s3 = area(d[c], d[a], st[i]);
		if (s1 && s2 && s3 && s == s1+s2+s3)
		{
			st[m] = st[i];
			dep[m] = depth;
			num[m] = num[i];
			if (st[i].c == d[c].c)
				cc = num[m];
			m++;
		}
	}
	if (cc != -1)
	{
		printf("%d %d %c\n", d[c].i, d[cc].i, d[c].c);
		solve(a, b, cc, depth+1);
		solve(c, cc, a, depth+1);
		solve(c, cc, b, depth+1);
		while (dep[m-1] == depth)
			m--;
		return;
	}
	while (dep[m-1] == depth)
	{
		m--;
		printf("%d %d %c\n", d[a].i, st[m].i, d[a].c);
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, c, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lld%lld", &d[i].x, &d[i].y);
		d[i].c = 'g';
		d[i].i = i+1;
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%lld%lld", &d[n].x, &d[n].y);
		d[n].c = 'r';
		d[n++].i = i+1;
	}
	m = n;
	for (i = 0; i < n; i++)
	{
		st[i] = d[i];
		dep[i] = 0;
		num[i] = i;
	}
	for (i = 0; i < n; i++)
	{
		if (d[i].x == 0 && d[i].y == 0)
			a = i;
		if (d[i].x > 0 && d[i].y == 0)
			b = i;
		if (d[i].x == 0 && d[i].y > 0)
			c = i;
	}
	printf("%d %d r\n", d[a].i, d[b].i);
	solve(a, b, c, 1);
	for (i = 0; i < n && d[i].x != d[c].y || d[i].y != d[c].y; i++);
	printf("%d %d g\n", d[c].i, d[i].i);
	solve(c, i, b, 1);
	return 0;
}
