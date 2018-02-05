/*
define (p->q) there exists a way from vertex p to vertex q
*/
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))
#define inf 2147483647
#define MAXV 1000
#define MAXE 1000000
#define DFS 0
#define BFS 0
#define FLOYD_WARSHALL 0
#define DIJKSTRA 1

int edges[MAXE][3];
int deg[MAXV];
int *G[MAXV];
int *W[MAXV];
int con_W[MAXV][MAXV];

#if DFS
/*
dfs(p);
if (p->q)
	colour[q] = 1;
else
	colour[q] = 0;
/////////////////// O(E)
*/
bool tDFS[MAXV];
void dfs(int p)
{
	int i;
	tDFS[p] = 1;
	for (i = 0; i < deg[p]; i++)
		if (!tDFS[G[p][i]])
		{
			tDFS[G[p][i]] = 1;
			dfs(G[p][i]);
		}
}
#endif

#if BFS
// works if the weights of the edges are 1
/*
bfs(p, V);
if (p->q)
	dist[q] = the minimum distance from vertex p to vertex q;
else
	dist[q] = inf;
//////////////////// O(E)
*/
int distBFS[MAXV];
void bfs(int p, int n)
{
	int i;
	queue<int> QBFS;
	for (i = 0; i < n; i++)
		distBFS[i] = inf;
	distBFS[p] = 0;
	QBFS.push(p);
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		for (i = 0; i < deg[p]; i++)
			if (distBFS[G[p][i]] == inf)
			{
				distBFS[G[p][i]] = distBFS[p]+1;
				Q.push(G[p][i]);
			}
	}
}
#endif
#if FLOYD_WARSHALL
/*
floyd(V);
if (p->q)
	distFW[p][q] = minimum distance from vertex p to vertex q;
else
	distFW[p][q] = inf;
///////////////////////// O(V^3)
*/
int distFW[MAXV][MAXV];
void floyd(int n)
{
	int i, j, k;
	memcpy(distFW, con_G, sizeof(con_G));
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				distFW[i][j] = Min(distFW[i]d[j], distFW[i][k]+distFW[k][j]);
}
#endif
#if DIJKSTRA
/*
// works if weights of the edges are non-negative
dijkstra(p, V);
if (p->q)
	distDJKS[q+1] = minimum distance from vertex p to vertex q;
else
	distDJKS[q+1] = inf;
////////////////////// O(E*logV)
*/
int distDJKS[MAXV+1];
int heapDJKS[MAXV+1];
int placeDJKS[MAXV+1];
void heapifyUP(int p)
{
	int par;
	while (1)
	{
		par = p>>1;
		if (distDJKS[heapDJKS[par]] <= distDJKS[heapDJKS[p]])
			break;
		swap(heapDJKS[par], heapDJKS[p]);
		swap(placeDJKS[heapDJKS[par]], placeDJKS[heapDJKS[p]]);
		p = par;
	}
}
void heapifyDOWN(int p, int n)
{
	int l, r, sw;
	while (1)
	{
		l = p<<1;
		r = l|1;
		sw = p;
		if (l <= n)
			if (distDJKS[sw] > distDJKS[l])
				sw = l;
		if (r <= n)
			if (distDJKS[sw] > distDJKS[r])
				sw = r;
		if (sw == p)
			break;
		swap(heapDJKS[sw], heapDJKS[p]);
		swap(placeDJKS[heapDJKS[sw]], placeDJKS[heapDJKS[p]]);
		p = sw;
	}
}
void buildDJKS(int p, int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		distDJKS[i] = inf;
		heapDJKS[i] = placeDJKS[i] = i;
	}
	distDJKS[0] = distDJKS[p] = 0;
	for (i = n; i > 1; i--)
		heapifyUP(i);
}
void dijkstra(int p, int n)
{
	int m, i;
	buildDJKS(p, n);
	m = n;
	while (m)
	{
		swap(heapDJKS[1], heapDJKS[m]);
		swap(placeDJKS[heapDJKS[1]], placeDJKS[heapDJKS[m]]);
		for (i = 0; i < deg[heapDJKS[m]]; i++)
			if (distDJKS[G[heapDJKS[m]][i]] > distDJKS[heapDJKS[m]]+W[heapDJKS[m]][i])
			{
				distDJKS[G[heapDJKS[m]][i]] = distDJKS[heapDJKS[m]]+W[heapDJKS[m]][i];
				heapifyUP(placeDJKS[G[heapDJKS[m]][i]]);
			}
		heapifyDOWN(1, n);
		m--;
	}
}
#endif
int main()
{
	int n, m, s, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", edges[i], edges[i]+1, edges[i]+2);
		deg[edges[i][0]]++;
		deg[edges[i][1]]++;
	}
	for (i = 1; i <= n; i++)
	{
		G[i] = new int[deg[i]];
		W[i] = new int[deg[i]];
	}
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < m; i++)
	{
		G[edges[i][0]][deg[edges[i][0]]] = edges[i][1];
		G[edges[i][1]][deg[edges[i][1]]] = edges[i][0];
		W[edges[i][0]][deg[edges[i][0]]++] = W[edges[i][1]][deg[edges[i][1]]++] = edges[i][2];
	}
	scanf("%d", &s);
	dijkstra(s, n);
	for (i = 1; i <= n; i++)
		printf("%d ", distDJKS[i]);
	putchar('\n');
	return 0;
}
/*
5 4
1 2 1
2 3 2
3 4 3
4 5 4

*/
