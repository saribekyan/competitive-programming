//		Prim's Algorithm
//Input: file input.txt
//	1st line: n - number of vertices in the Graph, m - number of edges in the Graph;
//	lines 2..m+1: three integers p, q, w - representing that the pair of vertices (p, q)
//	is connedted with edge, which weight is w;
//Output: file output.txt
//	1st line: W - the weight of the minimum spanning tree
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_INT 2147483647

bool t[100];
int end[100];
struct vertex{int p, w;}g[100][100];
bool operator <(vertex a, vertex b){return a.w > b.w;}
FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
int main()
{
	int n, m, p, q, w, i, k;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		t[i] = 0;
		end[i] = 0;
	}
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%d%d%d", &p, &q, &w);
		g[p-1][end[p-1]].p = q-1;
		g[p-1][end[p-1]].w = w;
		end[p-1]++;
	}
	for (i = 0; i < n; i++)
		sort(g[i], g[i]+end[i]);
	t[0] = 1;
	m = 1;
	w = 0;
	while (m != n)
	{
		q = MAX_INT;
		for (i = 0; i < n; i++)
			if (t[i] && end[i])
				if (q > g[i][end[i]-1].w)
				{
					p = i;
					k = g[i][end[i]-1].p;
					q = g[i][end[i]-1].w;
				}
		if (q == MAX_INT)break;
		w += q;
		t[k] = 1;
		end[p]--;
		m++;
	}
	if (m == n)
		fprintf(fout, "%d\n", w);
	else
		fprintf(fout, "-1\n");
	return 0;
}
