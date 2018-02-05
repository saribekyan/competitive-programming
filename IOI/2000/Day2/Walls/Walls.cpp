#include <cstdio>
#include <algorithm>
using namespace std;
#define inf 123456789
#define Min(a, b) ((a)<(b)?(a):(b))

int f[300];
int d[300][300];
int t[300][300];
int reg[300][300], dr[300];
int dist[300][300], neig[300][300], dn[300];
int main()
{
	freopen("walls.in", "r", stdin);
	freopen("walls.out", "w", stdout);
	int a1, a2, n, m, w, mn, p, i, j, k, l;
	scanf("%d%d%d", &m, &n, &l);
	for (i = 0; i < l; i++)
	{
		scanf("%d", f+i);
		f[i]--;
	}
	memset(dn, 0, sizeof(dn));
	for (i = 0; i < m; i++)
	{
		scanf("%d", dr+i);
		for (j = 0; j < dr[i]; j++)
		{
			scanf("%d", reg[i]+j);
			neig[reg[i][j]-1][dn[reg[i][j]-1]++] = i;
		}
		reg[i][dr[i]] = reg[i][0];
	}
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			d[i][j] = inf;
	p = 1;
	memset(t, 0, sizeof(t));
	for (i = 0; i < m; i++)
		for (j = i+1; j < m; j++)
		{
			for (k = 0; k < dr[i]; k++)
				t[reg[i][k]][reg[i][k+1]] = t[reg[i][k+1]][reg[i][k]] = p;
			for (k = 0; k < dr[j]; k++)
				if (t[reg[j][k]][reg[j][k+1]] == p)
					d[i][j] = d[j][i] = 1;
			p++;
		}
	for (k = 0; k < m; k++)
		for (i = 0; i < m; i++)
			for (j = 0; j < m; j++)
				d[i][j] = Min(d[i][j], d[i][k]+d[k][j]);
	for (i = 0; i < m; i++)
		d[i][i] = 0;
	a1 = inf;
	for (i = 0; i < m; i++)
	{
		w = 0;
		for (j = 0; j < l; j++)
		{
			mn = inf;
			for (k = 0; k < dn[f[j]]; k++)
				mn = Min(mn, d[neig[f[j]][k]][i]);
			w += mn;
		}
		if (a1 > w)
		{
			a1 = w;
			a2 = i;
		}
	}
	printf("%d\n%d\n", a1, a2+1);
	return 0;
}
