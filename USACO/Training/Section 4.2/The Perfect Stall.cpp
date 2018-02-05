/*
PROG: stall4
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

bool found;
bool t[402];
int n, m, l;
int d[402][402] = {0}, way[402];
void rec(int p)
{
	if (p == n+m+1)
	{
		found = 1;
		return;
	}
	int i;
	for (i = 0; i <= n+m+1; i++)
		if (d[p][i] && !t[i])
		{
			t[i] = 1;
			way[l++] = i;
			rec(i);
			if (found)
				return;
			l--;
		}
}
FILE* fin = fopen("stall4.in", "r");
FILE* fout = fopen("stall4.out", "w");
int main()
{
	int p, flow, i, j;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%d", &l);
		for (j = 0; j < l; j++)
		{
			fscanf(fin, "%d", &p);
			d[i+1][n+p] = 1;
		}
	}
	for (i = 1; i <= n; i++)
		d[0][i] = 1;
	for (i = n+1; i <= n+m; i++)
		d[i][n+m+1] = 1;
	flow = 0;
	while (1)
	{
		l = 1;
		t[0] = 1;
		found = 0;
		way[0] = 0;
		for (i = 1; i <= n+m+1; i++)
			t[i] = 0;
		rec(0);
		if (!found)
			break;
		p = 987654321;
		for (i = 0; i < l-1; i++)
			if (p > d[way[i]][way[i+1]])
				 p = d[way[i]][way[i+1]];
		for (i = 0; i < l-1; i++)
		{
			d[way[i]][way[i+1]] -= p;
			d[way[i+1]][way[i]] += p;
		}
		flow += p;
	}
	fprintf(fout, "%d\n", flow);
	return 0;
}