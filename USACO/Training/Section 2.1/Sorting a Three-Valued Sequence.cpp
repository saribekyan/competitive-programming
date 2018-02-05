/*
PROG: sort3
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <cmath>
#define MAX 1000
#define min(a, b) ((a) < (b) ? (a) : (b))

int d[MAX], g[3][3];

FILE* fin = fopen("sort3.in", "r");
FILE* fout = fopen("sort3.out", "w");

int main()
{
	int n, a, b, c, i;
	fscanf(fin, "%d", &n);
	a = b = c = 0;
	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%d", d+i);
		if (d[i]==1)a++;
		if (d[i]==2)b++;
		if (d[i]==3)c++;
	}
	g[0][0] = g[0][1] = g[0][2] = g[1][0] = g[1][1] = g[1][2] = g[2][0] = g[2][1] = g[2][2] = 0;
	for (i = 0; i < n; i++)
	{
		if (d[i]==1)
		{
			if (i < a)
				g[0][0]++;
			if (i >= a && i < a+b)
				g[0][1]++;
			if (i >= a+b)
				g[0][2]++;
		}
		if (d[i]==2)
		{
			if (i >= a && i < a+b)
				g[1][1]++;
			if (i < a)
				g[1][0]++;
			if (i >= a+b)
				g[1][2]++;
		}
		if (d[i]==3)
		{
			if (i >= a+b)
				g[2][2]++;
			if (i >= a && i < a+b)
				g[2][1]++;
			if (i < a)
				g[2][0]++;
		}
	}
	fprintf(fout, "%d\n",
		min(g[0][1], g[1][0])+
		min(g[1][2], g[2][1])+
		min(g[0][2], g[2][0])+
		2*abs(g[0][1]-g[1][0]));
	return 0;
}