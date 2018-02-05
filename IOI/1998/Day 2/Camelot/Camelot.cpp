#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

int x[65], y[65];
int d[8][8][8][8];
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
queue<int> X, Y;
void bfs(int i, int j)
{
	int u, v, p, q, k;
	memset(d[i][j], -1, sizeof(d[i][j]));
	d[i][j][i][j] = 0;
	while (!X.empty())
	{
		X.pop();
		Y.pop();
	}
	X.push(i);
	Y.push(j);
	while (!X.empty())
	{
		p = X.front();
		q = Y.front();
		X.pop();
		Y.pop();
		for (k = 0; k < 8; k++)
		{
			u = p+dx[k];
			v = q+dy[k];
			if (u >= 0 && u < 8 && v >= 0 && v < 8 && d[i][j][u][v] == -1)
			{
				d[i][j][u][v] = d[i][j][p][q]+1;
				X.push(u);
				Y.push(v);
			}
		}
	}
}
int main()
{
	freopen("camelot.in", "r", stdin);
	freopen("camelot.out", "w", stdout);
	char ch;
	int n=0, m, w, i, j, k, l, r;
	while (1)
	{
		ch = getchar();
		if (ch == '\n')
			break;
		x[n] = ch-'A';
		y[n++] = getchar()-'0'-1;
	}
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			bfs(i, j);
	m = 10000000;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
		{
			w = 0;
			for (k = 1; k < n; k++)
				w += d[x[k]][y[k]][i][j];
			for (k = 0; k < 8; k++)
				for (l = 0; l < 8; l++)
					for (r = 1; r < n; r++)
						m = Min(m, w-d[x[r]][y[r]][i][j]+d[x[r]][y[r]][k][l]+d[k][l][i][j]+Max(abs(k-x[0]), abs(l-y[0])));
		}
	printf("%d\n", m);
	return 0;
}
