#include <cstdio>

bool t[101][101], c;
int g[101][101], d[101][101], min[101], max[101], n, m;
void rec(int p, int q)
{
	if (q >= 1)
		if (t[p][q-1])
		{
			t[p][q-1] = 0;
			g[p][q-1] = g[p][q];			
			rec(p, q-1);
		}
	if (q < m-1)
		if (t[p][q+1])
		{
			t[p][q+1] = 0;
			g[p][q+1] = g[p][q];
			rec(p, q+1);
		}
	if (p >= 1)
		if (t[p-1][q])
		{
			t[p-1][q] = 0;
			g[p-1][q] = g[p][q];
			rec(p-1, q);
		}
	if (p < n-1)
		if (t[p+1][q])
		{
			t[p+1][q] = 0;
			g[p+1][q] = g[p][q];
			rec(p+1, q);
		}
}
FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
int main()
{
	int i, j, p;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			fscanf(fin, "%d", &d[i][j]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			t[i][j] = 0;
			g[i][j] = -1;
			if (j >= 1)
				if (d[i][j-1] < d[i][j])
					t[i][j] = 1;
			if (j < m-1)
				if (d[i][j+1] < d[i][j])
					t[i][j] = 1;
			if (i >= 1)
				if (d[i-1][j] < d[i][j])
					t[i][j] = 1;
			if (i < n-1)
				if (d[i+1][j] < d[i][j])
					t[i][j] = 1;
		}
	p = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			c = 0;
			if (t[i][j] == 1)
			{
				if (j >= 1)
					if (t[i][j-1])
						c = 1;
				if (j < m-1)
					if (t[i][j+1])
						c = 1;
				if (i >= 1)
					if (t[i-1][j])
						c = 1;
				if (i < n-1)
					if (t[i+1][j])
						c = 1;
			}
			if (c)
			{
				t[i][j] = 0;
				g[i][j] = p;
				rec(i, j);
				p++;
			}
		}
	for (i = 0; i < p; i++)
	{
		min[i] = 100001;
		max[i] = -1;
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (g[i][j] != -1)
			{
				if (min[g[i][j]] > d[i][j])
					min[g[i][j]] = d[i][j];
				if (max[g[i][j]] < d[i][j])
					max[g[i][j]] = d[i][j];
			}
	n = -1;
	for (i = 0; i < p; i++)
		if (n < max[i]-min[i])
			n = max[i]-min[i];
	fprintf(fout, "%d\n", n);
	return 0;
}