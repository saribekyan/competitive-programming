#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
#define Max(a, b) ((a)>(b)?(a):(b))

bool ok;
int vertice;
short n, m;
bool t[505][505];
short h[505][505];
short di[4] = {-1, 0, 0, 1};
short dj[4] = {0, -1, 1, 0};
short st[2][300005];
void read()
{
	short i, j;
	scanf("%hd%hd", &m, &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%hd", h[i]+j);
}
void dfs(bool sign, short i, short j)
{
	int len;
	short p, q, l;
	st[0][0] = i;
	st[1][0] = j;
	len = 1;
	while (len)
	{
		vertice++;
		i = st[0][len-1];
		j = st[1][len-1];
		len--;
		for (l = 0; l < 4; l++)
		{
			p = i+di[l];
			q = j+dj[l];
			if (p >= 0 && p < n && q >= 0 && q < m)
			{
				if (!t[p][q] && h[i][j] == h[p][q])
				{
					t[p][q] = 1;
					st[0][len] = p;
					st[1][len++] = q;
				}
				if (sign && h[i][j] < h[p][q] || !sign && h[i][j] > h[p][q])
					ok = 0;
			}
		}
	}
}
short number(bool sign)
{
	short s=0, p, q, i, j, l;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (!t[i][j])
			{
				for (l = 0; l < 4; l++)
				{
					p = i+di[l];
					q = j+dj[l];
					if (p >= 0 && p < n && q >= 0 && q < m)
						if (sign && h[i][j] < h[p][q] || !sign && h[i][j] > h[p][q])
							break;
				}
				if (l == 4)
				{
					ok = 1;
					t[i][j] = 1;
					vertice = 0;
					dfs(sign, i, j);
					if (ok && vertice != m*n)
						s++;
				}
				else
				{
					t[i][j] = 1;
					dfs(sign, i, j);
				}
			}
	return s;
}
short solve()
{
	if (n == 1 && m == 1)
		return 0;
	short s1, s2;
	s1 = number(0);
	memset(t, 0, sizeof(t));
	s2 = number(1);
	return Max(s1, s2);
}
int main()
{
	freopen("skiarea.in", "r", stdin);
	freopen("skiarea.out", "w", stdout);
	read();
	printf("%hd\n", solve());
	return 0;
}
