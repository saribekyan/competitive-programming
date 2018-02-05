#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXV 10000
#define MAXE 1000000
#define inf 123456789

int n, m, s, t;
int d[MAXV];
int deg[MAXV];
int H[MAXV];
int pl[MAXV];
int *G[MAXV], *W[MAXV];
int in[MAXE][3];
bool ex[MAXV];
void read()
{
	int i, j;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 3; j++)
			scanf("%d", in[i]+j);
		deg[in[i][0]]++;
		deg[in[i][1]]++;
	}
}
void build()
{
	int i, j, par;
	for (i = 1; i <= n; i++)
	{
		G[i] = new int[deg[i]];
		W[i] = new int[deg[i]];
	}
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < m; i++)
	{
		G[in[i][0]][deg[in[i][0]]] = in[i][1];
		G[in[i][1]][deg[in[i][1]]] = in[i][0];
		W[in[i][0]][deg[in[i][0]]++] = W[in[i][1]][deg[in[i][1]]++] = in[i][2];
	}
	for (i = 1; i <= n; i++)
	{
		d[i] = inf;
		H[i] = pl[i] = i;
	}
	d[s] = 0;
	m = n;
	for (i = n; i > 1; i--)
	{
		j = i;
		while (1)
		{
			par = j>>1;
			if (d[H[par]] <= d[H[j]])
				break;
			swap(H[par], H[j]);
			swap(pl[H[par]], pl[H[j]]);
			j = par;
		}
	}
}
int dijkstra()
{
	int i, j, par, l, r, sw;
	m = n;
	memset(ex, 0, sizeof(ex));
	while (m)
	{
		swap(H[1], H[m]);
		swap(pl[H[1]], pl[H[m]]);
		ex[H[m]] = 1;
		for (i = deg[H[m]]-1; i >= 0; i--)
			if (!ex[G[H[m]][i]])
			{
				d[G[H[m]][i]] = min(d[G[H[m]][i]], d[H[m]]+W[H[m]][i]);
				j = pl[G[H[m]][i]];
				while (1)
				{
					par = j>>1;
					if (d[H[par]] <= d[H[j]])
						break;
					swap(H[par], H[j]);
					swap(pl[H[par]], pl[H[j]]);
					j = par;
				}
			}
		m--;
		j = 1;
		while (1)
		{
			l = j<<1;
			r = l|1;
			sw = j;
			if (l <= m)
				if (d[H[sw]] > d[H[l]])
					sw = l;
			if (r <= m)
				if (d[H[sw]] > d[H[r]])
					sw = r;
			if (sw == j)
				break;
			swap(H[sw], H[j]);
			swap(pl[H[sw]], pl[H[j]]);
			j = sw;
		}
	}
	return d[t];
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	read();
	build();
	printf("%d\n", dijkstra());
	return 0;
}