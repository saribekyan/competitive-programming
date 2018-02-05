#include <cstdio>
#include <algorithm>
using namespace std;

int d[20];
struct bale{int a, b;}g[20];
bool operator <(bale a, bale b){return a.a < b.a;}

FILE* fin = fopen("btwr.in", "r");
FILE* fout = fopen("btwr.out", "w");

int main()
{
	int n, i, j;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%d%d", &g[i].a, &g[i].b);
	sort(g, g+n);
	for (i = 0; i < n; i++)
		d[i] = 1;
	for (i = 0; i < n-1; i++)
		for (j = i+1; j < n; j++)
			if (g[j].a > g[i].a && g[j].b > g[i].b)
				if (d[j] < d[i]+1)
					d[j] = d[i]+1;
	j = -1;
	for (i = 0; i < n; i++)
		if (j < d[i])
			j = d[i];
	fprintf(fout, "%d\n", j);
	return 0;
}