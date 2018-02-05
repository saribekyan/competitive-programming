#include <stdio.h>

int e[6010][3];
int parent[210], rank[210];
int find(int p)
{
	if (p == parent[p])
		return p;
	return parent[p] = find(parent[p]);
}
bool merge(int p, int q)
{
	p = find(p);
	q = find(q);
	if (p == q)
		return 0;
	if (rank[p] < rank[q])
	{
		parent[p] = q;
		rank[q] += rank[p];
	}
	else
	{
		parent[q] = p;
		rank[p] += rank[q];
	}
	return 1;
}
int main()
{
	int n, m, p, q, w, l, i, j;
	scanf("%d%d", &n, &m);
	for (l = 0; l < m; l++)
	{
		scanf("%d%d%d", &p, &q, &w);
		for (i = 0; i < n; i++)
		{
			rank[i] = 1;
			parent[i] = i;
		}
		for (i = 0; i < l && e[i][2] <= w; i++);
		for (j = m-1; j >= i; j--)
		{
			e[j+1][0] = e[j][0];
			e[j+1][1] = e[j][1];
			e[j+1][2] = e[j][2];
		}
		e[i][0] = p-1;
		e[i][1] = q-1;
		e[i][2] = w;
		w = 0;
		for (i = 0; i < l; i++)
			if (merge(e[i][0], e[i][1]))
				w += e[i][2];
		for (i = 0; i < n && rank[i] != n; i++);
		if (i == n)
			printf("-1\n");
		else
			printf("%d\n", w);
	}
	return 0;
}
