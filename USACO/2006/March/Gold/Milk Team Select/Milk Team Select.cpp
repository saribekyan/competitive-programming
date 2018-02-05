/*
PROG: tselect
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#define inf 1000000000

int n;
int d[510][510][2], s[510], k[2][510];
int tree[510][510], val[510], deg[510];
void solve(int p)
{
	int sw, v, r, i, j;
	for (i = deg[p]-1; i >= 0; i--)
		solve(tree[p][i]);
	sw = 0;
	k[sw][0] = 0;
	for (i = 1; i < n; i++)
		k[sw][i] = -inf;
	for (i = deg[p]-1; i >= 0; i--)
	{
		for (j = 0; j < n; j++)
			k[sw^1][j] = -inf;
		for (r = 0; r < n; r++)
		{
			v = d[tree[p][i]][r][0];
			if (v < d[tree[p][i]][r][1])
				v = d[tree[p][i]][r][1];
			for (j = 0; j+r < n; j++)
				if (k[sw^1][j+r] < k[sw][j]+v)
					k[sw^1][j+r] = k[sw][j]+v;
		}
		sw ^= 1;
	}
	for (i = 0; i < n; i++)
		d[p][i][0] = k[sw][i];
	if (p == 0)
		return;
	sw = 0;
	k[sw][0] = 0;
	for (i = 1; i < n; i++)
		k[sw][i] = -inf;
	for (i = deg[p]-1; i >= 0; i--)
	{
		for (j = 0; j < n; j++)
			k[sw^1][j] = -inf;
		for (r = 0; r < n; r++)
		{
			v = d[tree[p][i]][r][0];
			for (j = 0; j+r < n; j++)
				if (k[sw^1][j+r] < k[sw][j]+v)
					k[sw^1][j+r] = k[sw][j]+v;
			v = d[tree[p][i]][r][1];
			for (j = 0; j+r+1 < n; j++)
				if (k[sw^1][j+r+1] < k[sw][j]+v)
					k[sw^1][j+r+1] = k[sw][j]+v;
		}
		sw ^= 1;
	}
	for (i = 0; i < n; i++)
		d[p][i][1] = k[sw][i]+val[p];
}
int main()
{
	freopen("tselect.in", "r", stdin);
	freopen("tselect.out", "w", stdout);
	int x, p, i, j, l;
	scanf("%d%d", &n, &x);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", val+i, &p);
		tree[p][deg[p]++] = i;
	}
	solve(0);
	for (i = n-1; i >= 0 && d[0][i][0] < x; i--);
	printf("%d\n", i);
	return 0;
}
/*
5 8
-1 0
3 1
5 1
-3 3
2 0

*/
