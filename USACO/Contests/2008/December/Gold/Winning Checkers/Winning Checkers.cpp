/*
PROG: winchk
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <iostream>
using namespace std;

char s[510][510];
int num[510][510];
int I[250010], J[250010];
int *g[130000], deg[130000];
int di[4] = {-1, -1, 1, 1};
int dj[4] = {-1, 1, 1, -1};

int a, b;
int st[2][400000];
void euler()
{
	int p, q, i;
	while (a)
	{
		p = st[0][a-1];
		if (deg[p])
		{
			q = g[p][--deg[p]];
			st[0][a++] = q;
			for (i = 0; i < deg[q]; i++)
				if (g[q][i] == p)
					break;
			g[q][i] = g[q][--deg[q]];
		}
		else
		{
			st[1][b++] = p;
			a--;
		}
	}
}
void print(int s)
{
	int i;
		for (i = b-s-1; i >= 0; i--)
			printf("%d %d\n", I[st[1][i]]+1, J[st[1][i]]+1);
}
int main()
{
	freopen("winchk.in", "r", stdin);
	freopen("winchk.out", "w", stdout);
	int n, m, o, p, q, u, v, i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (i = 0; i < n; i++)
		if (s[i][0] == 'o' || s[i][n-1] == 'o' || s[0][i] == 'o' || s[n-1][i] == 'o')
		{
			printf("impossible\n");
			return 0;
		}
	m = o = 0;
	for (i = 0; i < n; i++)
		for (j = !(i&1); j < n; j+=2)
			if (s[i][j] != 'o')
			{
				I[m] = i;
				J[m] = j;
				num[i][j] = m++;
			}
			else
				o++;
	for (i = 0; i < n; i++)
		for (j = !(i&1); j < n; j+=2)
			if (s[i][j] == 'o')
				for (k = 0; k < 4; k++)
				{
					p = i+di[k];
					q = j+dj[k];
					u = i+di[(k+2)%4];
					v = j+dj[(k+2)%4];
					if (p >= 0 && p < n && q >= 0 && q < n && s[p][q] != 'o' &&
						u >= 0 && u < n && v >= 0 && v < n && s[u][v] != 'o')
						deg[num[p][q]]++;
				}
	for (i = 0; i < m; i++)
	{
		g[i] = new int[deg[i]+1];
		deg[i] = 0;
	}
	for (i = 0; i < n; i++)
		for (j = !(i&1); j < n; j+=2)
			if (s[i][j] == 'o')
				for (k = 0; k < 4; k++)
				{
					p = i+di[k];
					q = j+dj[k];
					u = i+di[(k+2)%4];
					v = j+dj[(k+2)%4];
					if (p >= 0 && p < n && q >= 0 && q < n && s[p][q] != 'o' &&
						u >= 0 && u < n && v >= 0 && v < n && s[u][v] != 'o')
						g[num[p][q]][deg[num[p][q]]++] = num[u][v];
				}
	for (j = 1; j < 4; j+=2)
	{
		p = 0;
		for (i = 0; i < m; i++)
			if (s[I[i]][J[i]] == 'K' && (I[i]+J[i])%4 == j && deg[i])
				p++;
		if (p != 1)
			continue;
		p = 0;
		for (i = 0; i < m; i++)
			if ((I[i]+J[i])%4 == j && deg[i]%2)
				p++;
		if (p == 1 || p > 2)
			continue;
		a = b = 0;
		if (p == 0)
		{
			for (i = 0; i < m && !(s[I[i]][J[i]] == 'K' && (I[i]+J[i])%4 == j && deg[i]); i++);
			if (i < m)
			{
				st[0][a++] = i;
				euler();
				if (b == o+1)
				{
					print(0);
					return 0;
				}
			}
		}
		else
		{
			for (i = 0; i < m && !(s[I[i]][J[i]] == '+' && (I[i]+J[i])%4 == j && deg[i]); i++);
			if (i < m)
			{
				st[0][a++] = i;
				for (i = 0; i < m && !(s[I[i]][J[i]] == 'K' && (I[i]+J[i])%4 == j && deg[i]); i++);
				if (i < m)
				{
					st[0][a++] = i;
					euler();
					if (o+2 == b)
					{
						print(1);
						return 0;
					}
				}
			}
		}
	}
	printf("impossible\n");
	return 0;
}
