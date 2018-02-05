#include <cstdio>
#include <cmath>
#include <queue>
#include <string.h>
using namespace std;

short R[2];
short n[2], m[2];
struct robot
{
	short i, j;
	short way;
	short dir;
} rob[2][10];
char ans[10005];
struct P
{
	short i[2], j[2];
	short passed;
} p, q;
struct prev
{
	short p;
	short i, j, k, l;
} pred[22][22][22][22][12], W;
queue<P> Q;
bool t[22][22][22][22][12];
char M[2][25][25];
short I[2][10][12], J[2][10][12];
short di[4] = {-1, +0, +1, -0};
short dj[4] = {+0, +1, -0, -1};
char side[] = "NESW\0";
void init_M(short l)
{
	short i, j;
	for (i = 0; i <= n[l]+1; i++)
		for (j = 0; j <= m[l]+1; j++)
			M[l][i][j] = '*';
}
void read_M(int l)
{
	char ch;
	short i, j;
	for (i = 1; i <= n[l]; i++)
	{
		scanf("\n");
		for (j = 1; j <= m[l]; j++)
			scanf("%c", &M[l][i][j]);
	}
	scanf("%hd", R+l);
	for (i = 0; i < R[l]; i++)
	{
		scanf("%hd%hd%hd %ch\n", &rob[l][i].i, &rob[l][i].j, &rob[l][i].way, &ch);
		if (ch == 'N')
			rob[l][i].dir = 0;
		if (ch == 'E')
			rob[l][i].dir = 1;
		if (ch == 'S')
			rob[l][i].dir = 2;
		if (ch == 'W')
			rob[l][i].dir = 3;
	}
}
void place(short l)
{
	short i, j;
	for (i = 1; i <= n[l]; i++)
		for (j = 1; j <= m[l]; j++)
			if (M[l][i][j] == 'X')
			{
				p.i[l] = i;
				p.j[l] = j;
				return;
			}
}
void read()
{
	bool b;
	short l, i, j;
	p.passed = 0;
	for (l = 0; l < 2; l++)
	{
		scanf("%hd%hd", n+l, m+l);
		init_M(l);
		read_M(l);
		for (i = 0; i < R[l]; i++)
		{
			I[l][i][0] = rob[l][i].i;
			J[l][i][0] = rob[l][i].j;
		}
		for (i = 0; i < R[l]; i++)
			for (b = 1, j = 1; j < 12; j++)
			{
				if (abs(I[l][i][j-1]-rob[l][i].i)+abs(J[l][i][j-1]-rob[l][i].j)+1 == rob[l][i].way ||
					abs(I[l][i][j-1]-rob[l][i].i)+abs(J[l][i][j-1]-rob[l][i].j) == 0)
					b = !b;
				if (b)
				{
					I[l][i][j] = I[l][i][j-1]-di[rob[l][i].dir];
					J[l][i][j] = J[l][i][j-1]-dj[rob[l][i].dir];
				}
				else
				{
					I[l][i][j] = I[l][i][j-1]+di[rob[l][i].dir];
					J[l][i][j] = J[l][i][j-1]+dj[rob[l][i].dir];
				}
			}
		place(l);
	}
}
void bfs()
{
	short i, j, k, l, mod, modp;
	Q.push(p);
	t[p.i[0]][p.j[0]][p.i[1]][p.j[1]][0] = 1;
	while (!Q.empty())
	{
		p = Q.front();
		if (M[0][p.i[0]][p.j[0]] == '*' && M[1][p.i[1]][p.j[1]] == '*')
		{
			printf("%d\n", p.passed);
			l = p.passed;
			mod = l%12;
			l--;
			W = pred[p.i[0]][p.j[0]][p.i[1]][p.j[1]][mod];
			while (l != -1)
			{
				ans[l--] = side[W.p];			
				mod = (mod+11)%12;
				W = pred[W.i][W.j][W.k][W.l][mod];
			}
			for (i = 0; i < p.passed; i++)
				printf("%c\n", ans[i]);
			return;
		}
		Q.pop();
		q.passed = p.passed+1;
		mod = q.passed%12;
		modp = p.passed%12;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 2; j++)
			{
				q.i[j] = p.i[j]+di[i];
				q.j[j] = p.j[j]+dj[i];
			}
			for (j = 0; j < 2; j++)
				if (M[j][q.i[j]][q.j[j]] == '#' || M[j][p.i[j]][p.j[j]] == '*')
				{
					q.i[j] -= di[i];
					q.j[j] -= dj[i];
				}
			if (!t[q.i[0]][q.j[0]][q.i[1]][q.j[1]][mod])
			{
				for (j = 0; j < 2; j++)
				{
					for (k = 0; k < R[j]; k++)
						if (I[j][k][mod] == q.i[j] && J[j][k][mod] == q.j[j] ||
							I[j][k][modp] == q.i[j] && J[j][k][modp] == q.j[j] &&
							I[j][k][mod] == p.i[j] && J[j][k][mod] == p.j[j])
							goto there;
				}
				t[q.i[0]][q.j[0]][q.i[1]][q.j[1]][mod] = 1;
				prev &item = pred[q.i[0]][q.j[0]][q.i[1]][q.j[1]][mod];
				item.i = p.i[0];
				item.j = p.j[0];
				item.k = p.i[1];
				item.l = p.j[1];
				item.p = i;
				Q.push(q);
			}
there:;
		}
	}
	printf("-1\n");
}
int main()
{
	freopen("robots.in", "r", stdin);
	freopen("robots.out", "w", stdout);
	read();
	bfs();
	return 0;
}
