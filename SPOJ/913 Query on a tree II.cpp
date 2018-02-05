#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))

int c[2][10010], l;
int Q[100010][5], m;
int R[20010], d[20][20010], N;
int *g[10010], *w[10010], deg[10010], e[10010][3], n;

bool vis[10010];
int dist[10010], d1[10010];
void dfs(int p)
{
	int i;
	R[N++] = c[0][p];
	for (i = 0; i < deg[p]; i++)
		if (!vis[g[p][i]])
		{
			vis[g[p][i]] = 1;
			c[0][g[p][i]] = l;
			c[1][l++] = g[p][i];
			d1[g[p][i]] = d1[p]+1;
			dist[g[p][i]] = dist[p]+w[p][i];
			dfs(g[p][i]);
			R[N++] = c[0][p];
		}
}

int L[20010], V[10010];
void build_LCA()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		L[i] = 0;
		while ((1<<L[i]) <= i)
			L[i]++;
		L[i]--;
	}
	for (i = N; i > 0; i--)
	{
		d[0][i] = R[i];
		V[R[i]] = i;
	}
	for (i = 1; i <= L[N]; i++)
		for (j = 1; j+(1<<i) <= N+1; j++)
			d[i][j] = Min(d[i-1][j], d[i-1][j+(1<<(i-1))]);
}
int min_val(int p, int q)
{
	if (p > q)
	{
		p ^= q;
		q ^= p;
		p ^= q;
	}
	return c[1][Min(d[L[q-p+1]][p], d[L[q-p+1]][q-(1<<L[q-p+1])+1])];
}

int *K[10010], *ans[10010], dk[10010], way[10010];
void Kth(int p, int s)
{
	int i;
	for (i = 0; i < dk[p]; i++)
		ans[p][i] = way[s+K[p][i]-1];
	for (i = 0; i < deg[p]; i++)
		if (!vis[g[p][i]])
		{
			vis[g[p][i]] = 1;
			way[s-1] = g[p][i];
			Kth(g[p][i], s-1);
		}
}
int main()
{
	char s[10];
	int t, p, q, x, i;
	scanf("%d", &t);
	while (t)
	{
		scanf("%d", &n);
		memset(deg, 0, sizeof(deg));
		for (i = 0; i < n-1; i++)
		{
			scanf("%d%d%d", e[i], e[i]+1, e[i]+2);
			deg[e[i][0]]++;
			deg[e[i][1]]++;
		}
		for (i = 1; i <= n; i++)
		{
			g[i] = new int[deg[i]+1];
			w[i] = new int[deg[i]+1];
		}
		memset(deg, 0, sizeof(deg));
		for (i = 0; i < n-1; i++)
		{
			g[e[i][0]][deg[e[i][0]]] = e[i][1];
			g[e[i][1]][deg[e[i][1]]] = e[i][0];
			w[e[i][0]][deg[e[i][0]]] = w[e[i][1]][deg[e[i][1]]] = e[i][2];
			deg[e[i][0]]++;
			deg[e[i][1]]++;
		}
		N = 1;
		l = 2;
		c[0][1] = c[1][1] = 1;
		memset(vis, 0, sizeof(vis));
		vis[1] = 1;
		dist[1] = 0;
		dfs(1);
		build_LCA();
		m = 0;
		memset(dk, 0, sizeof(dk));
		while (1)
		{
			scanf("%s", s);
			if (s[1] == 'O')
				break;
			scanf("%d%d", &p, &q);
			Q[m][1] = p;
			Q[m][2] = q;
			x = min_val(V[c[0][p]], V[c[0][q]]);
			if (s[1] == 'I')
			{
				Q[m][0] = 0;
				Q[m][4] = dist[p]+dist[q]-2*dist[x];
			}
			else
			{
				Q[m][0] = 1;
				scanf("%d", Q[m]+3);
				if (d1[p]-d1[x]+1 >= Q[m][3])
					dk[p]++;
				else
				{
					Q[m][1] = q;
					Q[m][2] = p;
					Q[m][3] = d1[p]+d1[q]-2*d1[x]-Q[m][3]+2;
					dk[q]++;
				}
			}
			m++;
		}
		for (i = 1; i <= n; i++)
		{
			K[i] = new int[dk[i]+1];
			ans[i] = new int[dk[i]+1];
		}
		memset(dk, 0, sizeof(dk));
		for (i = 0; i < m; i++)
			if (Q[i][0])
				K[Q[i][1]][dk[Q[i][1]]++] = Q[i][3];
		way[n-1] = 1;
		memset(vis, 0, sizeof(vis));
		vis[1] = 1;
		Kth(1, n-1);
		memset(dk, 0, sizeof(dk));
		for (i = 0; i < m; i++)
			if (Q[i][0] == 0)
				printf("%d\n", Q[i][4]);
			else
				printf("%d\n", ans[Q[i][1]][dk[Q[i][1]]++]);
		for (i = 1; i <= n; i++)
		{
			delete g[i];
			delete w[i];
			delete K[i];
			delete ans[i];
		}
		t--;
		if (t)
			putchar('\n');
	}
	return 0;
}
/*
3

6
1 2 1
2 4 1
2 5 2
1 3 1
3 6 2
DIST 4 6
KTH 4 6 4
DONE

5
1 2 1
1 3 1
1 4 1
1 5 1
DIST 1 5
DIST 2 4
KTH 1 2 1
KTH 2 3 2
DONE

1
6
1 2 1
2 3 2
2 4 3
2 5 4
2 6 5
DIST 3 6
DIST 1 4
KTH 2 6 1
KTH 1 2 1
KTH 1 2 2
DONE
 
*/
