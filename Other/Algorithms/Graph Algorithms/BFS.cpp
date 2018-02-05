//Input:
//	1st line: n - number of vertice in the Graph; m - number of edges in the Graph
//	lines 2..m+1: the edges of the Graph
//	line m+2: A vertex p, from which the program must calculate the shortest paths
//Output:
//	n integers: the i_th integer shows the shortest path from p to i
#include <cstdio>
#include <queue>
using namespace std;
#define MAX_INT 2147483647

int w[100];
queue<int> d;
bool g[100][100], t[100];

int main()
{
	int n, m, i, j, p, q;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			g[i][j] = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &p, &q);
		g[p-1][q-1] = 1;
	}
	scanf("%d", &p);
	for (i = 0; i < n; i++)
	{
		t[i] = 0;
		w[i] = MAX_INT;
	}
	t[p-1] = 1;
	w[p-1] = 0;
	d.push(p-1);
	while (!d.empty())
	{
		for (i = 0; i < n; i++)
			if (t[i] == 0)
				if (g[d.front()][i] == 1)
				{
					w[i] = w[d.front()]+1;
					t[i] = 1;
					d.push(i);
				}
		d.pop();
	}
	for (i = 0; i < n-1; i++)
		printf("%d ", w[i]);
	printf("%d\n", w[n-1]);
	return 0;
}