//Input:
//	1st line: n - number of vertice in the Graph; m - number of edges in the Graph
//	lines 2..m+1: the edges of the Graph
//Output:
//	All conected componenents of the Graph in seperate lines
#include <cstdio>
#include <stack>
using namespace std;

stack<int> d;
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
	for (i = 0; i < n; i++)
		t[i] = 0;
	while (1)
	{
		for (i = 0; i < n; i++)
			if (t[i] == 0)
				break;
		if (i == n)
			break;
		d.push(i);
		printf("%d ", i+1);
		t[i] = 1;
		while (!d.empty())
		{
			q = d.top();
			d.pop();
			for (i = 0; i < n; i++)
				if (t[i] == 0)
					if (g[q][i])
					{
						d.push(i);
						t[i] = 1;
						printf("%d ", i+1);
					}
		}
		putchar('\n');
	}
	return 0;
}