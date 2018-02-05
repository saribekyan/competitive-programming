#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

char M[2010][2010];
int t[2010][2010][2];
char e[2010][2010][6];
short di[6] = {-1, -1, 0, 0, 1, 1};
short dj[6] = {-1, 1, -2, 2, -1, 1};
struct position
{
	short i, j;
	char c;
} end, p, q;
queue<position> Q;
int main()
{
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
	int n, m, i, j;
	scanf("%d%d%hd%hd%hd%hd", &m, &n, &p.j, &p.i, &end.j, &end.i);
	p.j = (p.j<<1)+p.i;
	end.j = (end.j<<1)+end.i;
	for (i = 0; i <= (n<<1); i++)
		scanf("%s", M[i]);
	memset(e, 0, sizeof(e));
	for (i = 0; i <= (n<<1); i++)
		if (!(i&1))
		{
			for (j = 0; j < m; j++)
				if (M[i][j] != 'n')
					e[i>>1][(i>>1)+((j+1)<<1)-2][3] = e[i>>1][(i>>1)+((j+1)<<1)][2] = M[i][j];
		}
		else
		{
			for (j = 0; j <= (m<<1); j+=2)
				if (M[i][j] != 'n')
					e[i>>1][(i>>1)+j][5] = e[(i>>1)+1][(i>>1)+j+1][0] = M[i][j];
			for (j = 1; j <= (m<<1); j+=2)
				if (M[i][j] != 'n')
					e[(i>>1)+1][(i>>1)+j][1] = e[i>>1][(i>>1)+j+1][4] = M[i][j];
		}
	q = p;
	p.c = 'w';
	q.c = 'b';
	Q.push(p);
	Q.push(q);
	memset(t, -1, sizeof(t));
	t[p.i][p.j][p.c] = t[q.i][q.j][q.c] = 0;
	while (!Q.empty())
	{
		p = Q.front();
		if (p.i == end.i && p.j == end.j)
		{
			printf("%d\n", t[p.i][p.j][p.c]);
			return 0;
		}
		Q.pop();
		if (p.c == 'w')
			q.c = 'b';
		else
			q.c = 'w';
		for (i = 0; i < 6; i++)
			if (e[p.i][p.j][i] == q.c)
			{
				q.i = p.i+di[i];
				q.j = p.j+dj[i];
				if (t[q.i][q.j][q.c] == -1)
				{
					t[q.i][q.j][q.c] = t[p.i][p.j][p.c]+1;
					Q.push(q);
				}
			}
	}
	printf("-1\n");
	return 0;
}
