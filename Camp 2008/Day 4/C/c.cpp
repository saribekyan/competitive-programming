#include <cstdio>
#include <cstring>
//#include <iostream>
#include <algorithm>
using namespace std;
#define inf (1000000000000000000LL)

int n, m;
struct pos
{
	long long x, y;
} s[510], p[4010], st, end, w, sw;

bool operator < (pos a, pos b)
{
	return a.x < b.x || a.x == b.x && a.y < b.y;
}
bool operator == (pos a, pos b)
{
	return a.x == b.x && a.y == b.y;
}
long long dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
long long dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

long long g[4010][4010];
long long check(pos a, pos b)
{
	pos a1;
	int k, l, u, v, q, w, i;
	if (a.x < b.x)
		a1.x = a.x;
	else
		a1.x = b.x;
	if (a.y < b.y)
		a1.y = a.y;
	else
		a1.y = b.y;
	k = abs(b.x-a.x);
	l = abs(b.y-a.y);
	for (i = 0; i < n; i++)
		if (s[i].x >= a1.x && s[i].y >= a1.y && s[i].x <= a1.x+k && s[i].y <= a1.y+l)
		{
			u = abs(s[i].x-a.x);
			v = abs(s[i].y-a.y);
			q = abs(s[i].x-b.x);
			w = abs(s[i].y-b.y);
////////////////////////
//			if (a.x == 0 && a.y == 0 && b.x == 2 && b.y == 2)
//				cerr << k << ' ' << l << ' ' << u << ' ' << v << ' ' << q << ' ' << w << '\n';
////////////////////////
			if ((k >= l && u >= v && q >= w) || (k < l && u <= v && q <= w))
				return inf;
		}
	if (k > l)
		return k;
	return l;
}

bool t[4010];
long long d[4010];
void dijkstra()
{
	int l, i;
	memset(t, 0, sizeof(t));
	d[0] = 0;
	for (i = 1; i < m; i++)
		d[i] = inf;
	while (1)
	{
		l = -1;
		for (i = 0; i < m; i++)
			if (!t[i] && (l == -1 || d[l] > d[i]))
				l = i;
		if (l == -1 || l == m-1)
			return;
		t[l] = 1;
/////////////////
//		cerr << l << ": " << d[l] << '\n';
/////////////////
		for (i = 0; i < m; i++)
			if (!t[i] && d[i] > d[l]+g[l][i])
				d[i] = d[l]+g[l][i];
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, k, l;
	scanf("%lld%lld%lld%lld%d", &st.x, &st.y, &end.x, &end.y, &n);
	for (i = 0; i < n; i++)
		scanf("%lld%lld", &s[i].x, &s[i].y);
	m = 1;
	p[0] = st;
	for (i = 0; i < n; i++)
		for (j = 0; j < 8; j++)
		{
			w.x = s[i].x+dx[j];
			w.y = s[i].y+dy[j];
			for (k = 0; k < n && !(w == s[k]); k++);
			if (k == n)
				p[m++] = w;
		}
	p[m++] = end;
        sort(p+1, p+m-1);
	l = 1;
	for (i = 1; i < m-1; i++)
		if (!(p[i] == p[i-1]) && !(p[i] == st) && !(p[i] == end))
			p[l++] = p[i];
	p[l++] = end;
	m = l;
	for (i = 0; i < m; i++)
	{
		g[i][i] = 0;
		for (j = i+1; j < m; j++)
			g[i][j] = g[j][i] = check(p[i], p[j]);
	}
///////////////////
/*	cerr << m << '\n';
	for (i = 0; i < m; i++)
		cerr << i << ": " << p[i].x << ' ' << p[i].y << '\n';
	cerr << '\n';
	cerr << "   ";
	for (i = 0; i < m; i++)
		cerr << i%10 << ' ';
	cerr << '\n';
	for(i = 0; i < m; i++)
	{
		cerr << i << ": ";
		for (j = 0; j < m; j++)
			if (g[i][j] != inf)
				cerr << g[i][j] << ' ';	
			else
				cerr << "# ";
		cerr << '\n';
	}*/
///////////////////;
	dijkstra();
	if (d[m-1] == inf)
		printf("-1\n");
	else
		printf("%lld\n", d[m-1]);
	return 0;
}

