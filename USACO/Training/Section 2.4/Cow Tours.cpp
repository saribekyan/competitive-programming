/*
PROG: cowtour
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <cmath>

int n, c;
int color[150];
bool g[150][150], t[150];
double s[150][150], x[150], y[150], d[150];
void rec(int p)
{
	int i;
	for (i = 0; i < n; i++)
		if (!t[i])
			if (g[p][i])
			{
				t[i] = 1;
				color[i] = c;
				rec(i);
			}
}
FILE* fin = fopen("cowtour.in", "r");
FILE* fout = fopen("cowtour.out", "w");
int main()
{
	char ch;
	int i, j, k;
	double w1, w2, w, ans;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%lf%lf", x+i, y+i);
	for (i = 0; i < n; i++)
	{
		fgetc(fin);
		for (j = 0; j < n; j++)
		{
			fscanf(fin, "%c", &ch);
			if (ch == '0')
				g[i][j] = 0;
			else
				g[i][j] = 1;
		}
	}
	for (i = 0; i < n; i++)
	{
		t[i] = 0;
		color[i] = 0;
	}
	c = 0;
	while (1)
	{
		for (i = 0; i < n; i++)
			if (!t[i])
				break;
		if (i == n)break;
		c++;
		t[i] = 1;
		color[i] = c;
		rec(i);
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (g[i][j])
				s[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			else
				s[i][j] = 1000000000.0;
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (s[i][j] > s[i][k]+s[k][j])
					s[i][j] = s[i][k]+s[k][j];
	for (i = 0; i < n; i++)
		s[i][i] = 0.0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (color[i] == color[j])
				if (d[color[i]-1] < s[i][j])
					d[color[i]-1] = s[i][j];
	ans = 1000000000.0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (color[i] != color[j])
			{
				w1 = w2 = 0.0;
				for (k = 0; k < n; k++)
				{
					if (color[i] == color[k] && i != k)
						if (s[i][k] > w1)
							w1 = s[i][k];
					if (color[j] == color[k] && j != k)
						if (s[j][k] > w2)
							w2 = s[j][k];
				}
				w = w1+w2+sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				if (w < d[color[i]-1])
					w = d[color[i]-1];
				if (w < d[color[j]-1])
					w = d[color[j]-1];
				if (ans > w)
					ans = w;
			}
	fprintf(fout, "%.6lf\n", ans);
	return 0;
}