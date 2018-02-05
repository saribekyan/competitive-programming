/*
PROG: concom
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int d[101][101], g[101];
struct P{int x, y;}ans[10000];
bool operator <(P a, P b){return a.x < b.x || (a.x == b.x && a.y < b.y);}
FILE* fin = fopen("concom.in", "r");
FILE* fout = fopen("concom.out", "w");
int main()
{
	int n, m, i, j, k, p, q, w;
	fscanf(fin, "%d", &n);
	m = 0;
	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			d[i][j] = 0;
	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%d%d%d", &p, &q, &w);
		for (j = 0; j < m; j++)
			if (g[j] == p)
				break;
		if (j == m)
			g[m++] = p;
		for (k = 0; k < m; k++)
			if (g[k] == q)
				break;
		if (k == m)
			g[m++] = q;
		d[j][k] = w;
	}
	for (k = 0; k < m; k++)
		for (i = 0; i < m; i++)
			for (j = 0; j < m; j++)
				if (i != j)
				{
					if (d[i][k] > 50)
						d[i][j] += d[k][j];
				}
	n = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			if (d[i][j] > 50 && i != j)
			{
				ans[n].x = g[i];
				ans[n++].y = g[j];
			}
	sort(ans, ans+n);
	for (i = 0;  i < n; i++)
		fprintf(fout, "%d %d\n", ans[i].x, ans[i].y);
	return 0;
}