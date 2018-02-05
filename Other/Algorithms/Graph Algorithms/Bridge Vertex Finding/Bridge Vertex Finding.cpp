#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXV 100
#define MAXE 10000
#define inf 12345
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

short l;
bool t[MAXV];
short *G[MAXV];
short deg[MAXV];
short low[MAXV];
short *tree[MAXV];
short degree[MAXV];
short parent[MAXV];
short st[MAXE], end[MAXE];
short Number[MAXV], number[MAXV];
void rec(short p)
{
	short par, i;
	par = l-1;
	for (i = 0; i < deg[p]; i++)
		if (!t[G[p][i]])
		{
			t[G[p][i]] = 1;
			tree[par][degree[par]++] = l;
			number[l] = G[p][i];
			parent[l] = par;
			Number[G[p][i]] = l++;
			rec(G[p][i]);
		}
}
FILE* fin = fopen("bridge.in", "r");
FILE* fout = fopen("bridge.out", "w");
int main()
{
	short n, m, i, j;
	fscanf(fin, "%hd%hd", &n, &m);
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%d%d", st+i, end+i);
		deg[--st[i]]++;
		deg[--end[i]]++;
	}
	for (i = 0; i < n; i++)
	{
		G[i] = new short[deg[i]];
		tree[i] = new short[deg[i]];
	}
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < m; i++)
	{
		G[st[i]][deg[st[i]]++] = end[i];
		G[end[i]][deg[end[i]]++] = st[i];
	}
	l = 1;
	t[0] = 1;
	rec(0);
	parent[0] = -1;
	for (i = 0; i < n; i++)
	{
		low[i] = inf;
		for (j = deg[number[i]]-1; j >= 0; j--)
			if (G[number[i]][j] != number[parent[i]])
				low[i] = Min(low[i], Number[G[number[i]][j]]);
	}
	memset(t, 0, sizeof(t));
	for (i = n-1; i > 0; i--)
	{
		m = -1;
		for (j = degree[i]-1; j >= 0; j--)
			m = Max(m, low[tree[i][j]]);
		if (m >= i)
			t[number[i]] = 1;
		for (j = degree[i]-1; j >= 0; j--)
			low[i] = Min(low[i], low[tree[i][j]]);
	}
	t[0] = degree[0] > 1;
	for (i = 0; i < n; i++)
		if (t[i])
			fprintf(fout, "%d\n", i+1);
	return 0;
}