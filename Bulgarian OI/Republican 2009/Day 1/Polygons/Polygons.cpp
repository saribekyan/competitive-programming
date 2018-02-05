#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps (1e-9)
#define inf 1000000000

int n, s;
struct P
{
	int x, y;
} p[60];
bool prod(P a, P c, P b)
{
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x) > 0;
}
int area(P a, P b, P c)
{
	return abs(a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x);
}
int d[60][60][20];
int solve(int a, int b, int m)
{
	int &it = d[a][b][m];
	if (it != -1)
		return it;
	int r = area(p[s], p[a], p[b]);
	if (m == 3)
		return it = r;
	int i;
	it = inf;
	for (i = 0; i < n; i++)
		if (i != s && i != a && i != b &&
			!prod(p[s], p[b], p[i]) && !prod(p[a], p[b], p[i]) &&
			!prod(p[s], p[a], p[i]) && p[i].y >= p[s].y && it > solve(b, i, m-1)+r)
			it = d[b][i][m-1]+r;
	return it;
}
int main()
{
	int ans = inf, m, i, j;
	scanf("%d%d", &n, &m);
	if (m <= 2 || n <= 2 || m > n)
	{
		printf("0\n");
		return 0;
	}
	for (i = 0; i < n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	for (s = 0; s < n; s++)
	{
		memset(d, -1, sizeof(d));
		for (i = 0; i < n; i++)
			if (i != s && p[i].y >= p[s].y)
				for (j = 0; j < n; j++)
					if (j != s && j != i && p[j].y >= p[s].y && !prod(p[s], p[i], p[j]) && ans > solve(i, j, m))
						ans = d[i][j][m];
	}
	if (ans >= inf)
		ans = 0;
	printf("%d\n", ans/2);
	return 0;
}
