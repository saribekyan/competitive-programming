#include <cstdio>
#include <algorithm>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))

int l, h, v;
bool found;
bool t[1000];
int way[1000];
char s[600][600];
int d[1100][1100];
int H[600][600], V[600][600];
void dfs(int p)
{
	if (p == h+v+1)
	{
		found = 1;
		return;
	}
	int i;
	for (i = 0; i <= h+v+1; i++)
		if (!t[i] && d[p][i])
		{
			t[i] = 1;
			way[l++] = i;
			dfs(i);
			if (found)
				return;
			l--;
		}
}
int main()
{
	freopen("muddy.in", "r", stdin);
	freopen("muddy.out", "w", stdout);
	int T, n, m, i, j, k;
	scanf("%d", &T);
	while (T)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
			scanf("%s", s[i]);
		h = v = 0;
		memset(d, 0, sizeof(d));
		memset(H, 0, sizeof(H));
		memset(V, 0, sizeof(V));
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (s[i][j] == '*')
				{
					if (H[i][j] == 0)
					{
						h++;
						for (k = j; k < m && s[i][k] == '*'; k++)
							H[i][k] = h;
					}
					if (V[i][j] == 0)
					{
						v++;
						for (k = i; k < n && s[k][j] == '*'; k++)
							V[k][j] = v;
					}
				}
		for (i = 1; i <= h; i++)
			d[0][i] = 1;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (H[i][j] && V[i][j])
					d[H[i][j]][h+V[i][j]] = 1;
		for (i = h+1; i <= h+v; i++)
			d[i][h+v+1] = 1;
		m = 0;
		way[0] = 0;
		while (1)
		{
			l = 1;
			found = 0;
			memset(t, 0, sizeof(t));
			t[0] = 1;
			dfs(0);
			if (!found)
				break;
			k = 123456789;
			for (i = 0; i < l-1; i++)
				k = Min(k, d[way[i]][way[i+1]]);
			for (i = 0; i < l-1; i++)
			{
				d[way[i]][way[i+1]] -= k;
				d[way[i+1]][way[i]] += k;
			}
			m += k;
		}
		printf("%d\n", m);
		T--;
	}
	return 0;
}
