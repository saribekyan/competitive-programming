#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n;
char s[310][310];
int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};
int a[310][310], b[310][310];

int ds[310][310];
queue<int> Qi, Qj;
void bfs(int p, int q)
{
	int k, i, j;
	Qi.push(p);
	Qj.push(q);
	for (i = 0; i <= n+1; i++)
		for (j = 0; j <= n+1; j++)
			ds[i][j] = -1;
	ds[p][q] = 0;
	while (!Qi.empty())
	{
		p = Qi.front(); Qi.pop();
		q = Qj.front(); Qj.pop();
		for (k = 0; k < 4; k++)
		{
			i = p+di[k];
			j = q+dj[k];
			if (s[i][j] != '#' && ds[i][j] == -1)
			{
				ds[i][j] = ds[p][q]+1;
				Qi.push(i);
				Qj.push(j);
			}
		}
	}
}

bool d[2][310][310];
int pa[310][310], pb[310][310];
int *Ai[50000], *Aj[50000], *Bi[50000], *Bj[50000], da[50000], db[50000];
int main()
{
	int ts, l, p, q, u, v, x, y, w, t, sw, i, j, k, r;
	scanf("%d", &ts);
	while (ts--)
	{
		scanf("%d", &n);
		for (i = 0; i <= n+1; i++)
			s[0][i] = s[n+1][i] = '#';
		for (i = 1; i <= n; i++)
		{
			scanf("%s", s[i]+1);
			s[i][0] = s[i][n+1] = '#';
		}
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				if (s[i][j] == 'A')
				{
					bfs(i, j);
					memcpy(a, ds, sizeof(ds));
					p = i;
					q = j;
				}
				if (s[i][j] == 'B')
				{
					bfs(i, j);
					memcpy(b, ds, sizeof(ds));
					u = i;
					v = j;
				}
			}
		l = a[u][v];
		if (l&1)
		{
			printf("A\n");
			continue;
		}
		l >>= 1;
		memset(pa, -1, sizeof(pa));
		memset(pb, -1, sizeof(pb));
		memset(da, 0, sizeof(da));
		memset(db, 0, sizeof(db));
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (a[i][j] != -1 && b[i][j] != -1 && a[i][j]+b[i][j] == 2*l)
				{
					if (a[i][j] <= l)
						pa[i][j] = da[a[i][j]]++;
					else
						pa[i][j] = -1;
					if (b[i][j] <= l)
						pb[i][j] = db[b[i][j]]++;
					else
						pb[i][j] = -1;
				}
				else
					a[i][j] = b[i][j] = pa[i][j] = pb[i][j] = -1;
		for (i = 0; i <= l; i++)
		{
			Ai[i] = new int[da[i]+1];
			Aj[i] = new int[da[i]+1];
			Bi[i] = new int[db[i]+1];
			Bj[i] = new int[db[i]+1];
			da[i] = db[i] = 0;
		}
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (a[i][j] != -1 && b[i][j] != -1)
				{
					if (a[i][j] <= l)
					{
						Ai[a[i][j]][da[a[i][j]]] = i;
						Aj[a[i][j]][da[a[i][j]]++] = j;
					}
					if (b[i][j] <= l)
					{
						Bi[b[i][j]][db[b[i][j]]] = i;
						Bj[b[i][j]][db[b[i][j]]++] = j;
					}
				}
		sw = 0;
		memset(d[sw], 0, sizeof(d[sw]));
		for (i = da[l]-1; i >= 0; i--)
		{
			p = Ai[l][i];
			q = Aj[l][i];
			for (j = db[l]-1; j >= 0; j--)
				d[sw][i][j] = p != Bi[l][j] || q != Bj[l][j];
		}
		while (l--)
		{
			sw ^= 1;
			memset(d[sw], 0, sizeof(d[sw]));
			for (i = da[l]-1; i >= 0; i--)
			{
				p = Ai[l][i];
				q = Aj[l][i];
				for (j = db[l]-1; j >= 0; j--)
					if (!d[sw][i][j])
					{
						u = Bi[l][j];
						v = Bj[l][j];
						for (k = 0; k < 4; k++)
						{
							x = p+di[k];
							y = q+dj[k];
							if (a[x][y] == a[p][q]+1)
							{
								for (r = 0; r < 4; r++)
								{
									w = u+di[r];
									t = v+dj[r];
									if (b[w][t] == b[u][v]+1 && !d[sw^1][pa[x][y]][pb[w][t]])
										break;
								}
								if (r == 4)
								{
									d[sw][i][j] = 1;
									break;
								}
							}
						}
					}
			}
		}
		if (d[sw][0][0])
			printf("A\n");
		else
			printf("B\n");
		for (i = 0; i <= l; i++)
		{
			delete Ai[i];
			delete Aj[i];
			delete Bi[i];
			delete Bj[i];
		}
	}
	return 0;
}
