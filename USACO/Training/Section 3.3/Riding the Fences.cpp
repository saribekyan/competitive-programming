/*
PROG: fence
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int d[500][1024], deg[500], ans[1025], l;
void rec(int p)
{
	int i;
	while (deg[p])
	{
		deg[p]--;
		deg[d[p][deg[p]]]--;
		for (i = 0; i <= deg[d[p][deg[p]]]; i++)
			if (d[d[p][deg[p]]][i] == p)
				break;
		while (i < deg[d[p][deg[p]]])
		{
			d[d[p][deg[p]]][i] = d[d[p][deg[p]]][i+1];
			i++;
		}
		rec(d[p][deg[p]]);
	}
	ans[l++] = p+1;
}
bool compare(int a, int b){return a > b;}
FILE* fin = fopen("fence.in", "r");
FILE* fout = fopen("fence.out", "w");
int main()
{
	int n, m, p, q, i;
	fscanf(fin, "%d", &m);
	n = -1;
	for (i = 0; i < 500; i++)
		deg[i] = 0;
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%d%d", &p, &q);
		d[p-1][deg[p-1]++] = q-1;
		d[q-1][deg[q-1]++] = p-1;
		if (n < p)
			n = p;
		if (n < q)
			n = q;
	}
	p = q = -1;
	for (i = 0; i < n; i++)
	{
		sort(d[i], d[i]+deg[i], compare);
		if (deg[i]%2)
			if (p == -1)
				p = i;
			else
				q = i;
	}
	if (p == -1)
		p = 0;
	rec(p);
	reverse(ans, ans+l);
	for (i = 0; i <  l; i++)
		fprintf(fout, "%d\n", ans[i]);
	return 0;
}