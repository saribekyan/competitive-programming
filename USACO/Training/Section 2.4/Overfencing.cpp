/*
PROG: maze1
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <queue>
using namespace std;
#define min(a, b) ((a)<(b)?(a):(b))

bool t[202][78];
char s[202][78];
int d[202][78], g[202][78];
struct P{int p, q;}q, r;
queue<P> Q;
FILE* fin = fopen("maze1.in", "r");
FILE* fout = fopen("maze1.out", "w");
int main()
{
	P p, w;
	int n, m, i, j, ans;
	fscanf(fin, "%d%d", &m, &n);
	for (i = 0; i < 2*n+1; i++)
	{
		fgetc(fin);
		for (j = 0; j < 2*m+1; j++)
			fscanf(fin, "%c", &s[i][j]);
	}
	q.p = q.q = r.p = r.q = -1;
	for (i = 0; i < 2*n+1; i++)
	{
		if (s[i][0] == ' ')
			if (q.p == -1)
			{
				q.p = i;
				q.q = 1;
			}
			else
				if (r.p == -1)
				{
					r.p = i;
					r.q = 1;
				}
		if (s[i][2*m] == ' ')
			if (q.p == -1)
			{
				q.p = i;
				q.q = 2*m-1;
			}
			else
				if (r.p == -1)
				{
					r.p = i;
					r.q = 2*m-1;
				}
	}
	for (i = 0; i < 2*m+1; i++)
	{
		if (s[0][i] == ' ')
			if (q.p == -1)
			{
				q.p = 1;
				q.q = i;
			}
			else
				if (r.p == -1)
				{
					r.p = 1;
					r.q = i;
				}
		if (s[2*n][i] == ' ')
			if (q.p == -1)
			{
				q.p = 2*n-1;
				q.q = i;
			}
			else
				if (r.p == -1)
				{
					r.p = 2*n-1;
					r.q = i;
				}
	}
	for (i = 0; i < 2*n+1; i++)
		for (j = 0; j < 2*m+1; j++)
		{
			t[i][j] = 0;
			d[i][j] = g[i][j] = 2147483647;
		}
	d[q.p][q.q] = g[r.p][r.q] = 0;
	Q.push(q);
	t[q.p][q.q] = 1;
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		if (p.p > 1 && s[p.p-1][p.q] == ' ' && s[p.p-2][p.q] == ' ')
			if (!t[p.p-2][p.q])
			{
				w = p;
				w.p -= 2;
				t[w.p][w.q] = 1;
				d[w.p][w.q] = d[p.p][p.q]+1;
				Q.push(w);
			}
		if (p.p < 2*n-1 && s[p.p+1][p.q] == ' ' && s[p.p+2][p.q] == ' ')
			if (!t[p.p+2][p.q])
			{
				w = p;
				w.p += 2;
				t[w.p][w.q] = 1;
				d[w.p][w.q] = d[p.p][p.q]+1;
				Q.push(w);
			}
		if (p.q > 1 && s[p.p][p.q-1] == ' ' && s[p.p][p.q-2] == ' ')
			if (!t[p.p][p.q-2])
			{
				w = p;
				w.q -= 2;
				t[w.p][w.q] = 1;
				d[w.p][w.q] = d[p.p][p.q]+1;
				Q.push(w);
			}
		if (p.q < 2*m-1 && s[p.p][p.q+1] == ' ' && s[p.p][p.q+2] == ' ')
			if (!t[p.p][p.q+2])
			{
				w = p;
				w.q += 2;
				t[w.p][w.q] = 1;
				d[w.p][w.q] = d[p.p][p.q]+1;
				Q.push(w);
			}
	}
	for (i = 0; i < 2*n+1; i++)
		for (j = 0; j < 2*m+1; j++)
			t[i][j] = 0;
	t[r.p][r.q] = 1;
	Q.push(r);
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		if (p.p > 1 && s[p.p-1][p.q] == ' ' && s[p.p-2][p.q] == ' ')
			if (!t[p.p-2][p.q])
			{
				w = p;
				w.p -= 2;
				t[w.p][w.q] = 1;
				g[w.p][w.q] = g[p.p][p.q]+1;
				Q.push(w);
			}
		if (p.p < 2*n-1 && s[p.p+1][p.q] == ' ' && s[p.p+2][p.q] == ' ')
			if (!t[p.p+2][p.q])
			{
				w = p;
				w.p += 2;
				t[w.p][w.q] = 1;
				g[w.p][w.q] = g[p.p][p.q]+1;
				Q.push(w);
			}
		if (p.q > 1 && s[p.p][p.q-1] == ' ' && s[p.p][p.q-2] == ' ')
			if (!t[p.p][p.q-2])
			{
				w = p;
				w.q -= 2;
				t[w.p][w.q] = 1;
				g[w.p][w.q] = g[p.p][p.q]+1;
				Q.push(w);
			}
		if (p.q < 2*m-1 && s[p.p][p.q+1] == ' ' && s[p.p][p.q+2] == ' ')
			if (!t[p.p][p.q+2])
			{
				w = p;
				w.q += 2;
				t[w.p][w.q] = 1;
				g[w.p][w.q] = g[p.p][p.q]+1;
				Q.push(w);
			}
	}
	ans = -1;
	for (i = 1; i < 2*n+1; i+=2)
		for (j = 1; j < 2*m+1; j+=2)
			if (s[i][j] == ' ')
				if (ans < min(d[i][j], g[i][j]))
					ans = min(d[i][j], g[i][j]);
	fprintf(fout, "%d\n", ans+1);
	return 0;
}