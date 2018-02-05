/*
PROG: ditch
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int number, n;
bool t[200], found;
int g[200][200], d[200];
void dfs(int p)
{
	if (p == n-1)
	{
		found = 1;
		return;
	}
	int i;
	for (i = 1; i < n; i++)
		if (!t[i] && g[p][i])
		{
			t[i] = 1;
			d[number++] = i;
			dfs(i);
			if (found)
				return;
			number--;
		}
}
FILE* fin = fopen("ditch.in", "r");
FILE* fout = fopen("ditch.out", "w");
int main()
{
	long long ans;
	int m, p, q, w, i, j;
	fscanf(fin, "%d%d", &m, &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			g[i][j] = 0;
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%d%d%d", &p, &q, &w);
		g[p-1][q-1] += w;
	}
	ans = 0;
	d[0] = 0;
	while (1)
	{
		t[0] = 1;
		for (i = 1; i < n; i++)
			t[i] = 0;
		found = 0;
		number = 1;
		dfs(0);
		if (!found)
			break;
		w = 2147483647;
		for (i = 0; i < number-1; i++)
			if (w > g[d[i]][d[i+1]])
				w = g[d[i]][d[i+1]];
		ans += w;
		for (i = 0; i < number-1; i++)
		{
			g[d[i]][d[i+1]] -= w;
			g[d[i+1]][d[i]] += w;
		}
	}
	fprintf(fout, "%lld\n", ans);
	return 0;
}