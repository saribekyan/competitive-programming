#include <cstdio>
#include <algorithm>
using namespace std;
#define min(a, b) ((a)<(b)?(a):(b))
#define max(a, b) ((a)>(b)?(a):(b))

short n, x;
bool t[1001];
int d[2][1001];
int g[1001][1001];
void read()
{
	int m, w;
	short p, q, i, j;
	scanf("%hd%d%hd", &n, &m, &x);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			g[i][j] = 123456789;
	for (i = 0; i < m; i++)
	{
		scanf("%hd%hd%d", &p, &q, &w);
		g[p-1][q-1] = min(g[p-1][q-1], w);
	}
	x--;
}
void build()
{
	short i;
	for (i = 0; i < n; i++)
		d[0][i] = d[1][i] = 123456789;
	d[0][x] = d[1][x] = 0;
}
void dijkstra(short s)
{
	int m;
	short p, q, i, j;
	memset(t, 0, sizeof(t));
	p = x;
	for (i = 0; i < n; i++)
	{
		m = 123456789;
		for (j = 0; j < n; j++)
			if (!t[j])
				if (m > d[s][j])
				{
					p = j;
					m = d[s][j];
				}
		t[p] = 1;
		for (j = 0; j < n; j++)
			d[s][j] = min(d[s][j], d[s][p]+g[p][j]);
	}
}
void transpose()
{
	short i, j;
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
			swap(g[i][j], g[j][i]);
}
int solve()
{
	int m;
	short i;
	dijkstra(0);
	transpose();
	dijkstra(1);
	m = 0;
	for (i = 0; i < n; i++)
		m = max(m, d[0][i]+d[1][i]);
	return m;
}
int main()
{
	freopen("sparty.in", "r", stdin);
	freopen("sparty.out", "w", stdout);
	read();
	build();
	printf("%d\n", solve());
	return 0;
}
