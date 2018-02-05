/*
PROG: camelot
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <deque>
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))

int d[40][26][40][26], king_dist[40][26];
int myabs(int a)
{
	if (a > 0)return a;
	return -a;
}
struct pos{int i, j;}knight[1040], king, p, q;
std::deque<pos> Q;
int di[8] = {-2, -2, -1, -1,  1, 1,  2, 2};
int dj[8] = {-1,  1, -2,  2, -2, 2, -1, 1};
FILE* fin = fopen("camelot.in", "r");
FILE* fout = fopen("camelot.out", "w");
int main()
{
	char c;
	int n, m, number_of_knights, i, j, k, l, r, w, min_steps, ans;
	fscanf(fin, "%d%d", &n, &m);
	fscanf(fin, "\n%c %d", &c, &king.i);
	king.i--;
	king.j = c-'A';
	number_of_knights = 0;
	while (fscanf(fin, "%c%c %d", &c, &c, &knight[number_of_knights].i) == 3)
	{
		knight[number_of_knights].i--;
		knight[number_of_knights++].j = c-'A';
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			king_dist[i][j] = max(myabs(i-king.i), myabs(j-king.j));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			p.i = i;
			p.j = j;
			Q.push_back(p);
			for (k = 0; k < n; k++)
				for (l = 0; l < m; l++)
					d[i][j][k][l] = 999999;
			d[i][j][i][j] = 0;
			while (!Q.empty())
			{
				p = Q.front();
				Q.pop_front();
				for (k = 0; k < 8; k++)
				{
					q.i = p.i+di[k];
					q.j = p.j+dj[k];
					if (q.i >= 0 && q.i < n && q.j >= 0 && q.j < m)
						if (d[i][j][q.i][q.j] == 999999)
						{
							d[i][j][q.i][q.j] = d[i][j][p.i][p.j]+1;
							Q.push_back(q);
						}
				}
			}
		}
	min_steps = 0;
	for (i = 0; i < number_of_knights; i++)
		min_steps += d[king.i][king.j][knight[i].i][knight[i].j];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			ans = 0;
			for (k = 0; k < number_of_knights; k++)
				ans += d[knight[k].i][knight[k].j][i][j];
			if (ans <= min_steps)
			{
				w = 2147483647;
				for (k = 0; k < n; k++)
					for (l = 0; l < m; l++)
						if (!(ans+king_dist[k][l] >= min_steps))
							for (r = 0; r < number_of_knights; r++)
								w = min(w, d[knight[r].i][knight[r].j][k][l]+king_dist[k][l]+
									d[k][l][i][j]-d[knight[r].i][knight[r].j][i][j]);
				min_steps = min(min_steps, ans+min(w, king_dist[i][j]));
			}
		}
	fprintf(fout, "%d\n", min_steps);
	return 0;
}
