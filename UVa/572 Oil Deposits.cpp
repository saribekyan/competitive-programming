#include <iostream>
using namespace std;
#define MAX 100
char c[MAX+2][MAX+2];
int k;
int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

void rec(int x, int y)
{
	int i;
	for (i = 0; i < 8; i++)
		if (c[x+dx[i]][y+dy[i]]=='@')
		{
			c[x][y] = '*';
			c[x+dx[i]][y+dy[i]] = '*';
			rec(x+dx[i], y+dy[i]);
		}
}

int main()
{
	int n, m, i, j;
	while (cin >> n >> m && m)
	{
		for (i = 0; i <= n+1; i++)
			for (j = 0; j <= m+1; j++)
				c[i][j] = '*';
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				cin >> c[i][j];
		k = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				if (c[i][j]=='@')
				{
					rec(i, j);
					k++;
				}
		cout << k << '\n';
	}
	return 0;
}