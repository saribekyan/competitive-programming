#include <stdio.h>
#include <string.h>
#include <math.h>
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

long long r;
struct P
{
	long long x, y;
} p[310], c;
bool g[310][310];
bool intersect(P a, P b)
{
	long long ac = (a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y);
	long long bc = (b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y);
	long long ab = (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	if (ab+bc > ac && ab+ac > bc)
	{
		long long s = a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x;
		return fabs(s) <= r*sqrt(ab*1.0);
	}
	return Min(ac, bc) <= r*r;
}

int d[310][310];
int solve(int s, int t)
{
	int &it = d[s][t];
	if (it != -1)
		return it;
	if (t <= s+1)
		return it = 0;
	int i;
	it = 0;
	for (i = s+1; i < t; i++)
		it = Max(it, solve(s, i)+solve(i, t));
	it = Max(it, solve(s+1, t-1));
	return it += g[s][t];
}
int main()
{
	freopen("roping.in", "r", stdin);
	freopen("roping.out", "w", stdout);
	int n, m, i, j, k;
	scanf("%d%d%lld", &n, &m, &r);
	for (i = 0; i < n; i++)
	{
		scanf("%lld%lld", &p[i].x, &p[i].y);
		p[n+i] = p[i];
	}
	for (i = 0; i < 2*n; i++)
		for (j = 0; j < 2*n; j++)
			if ((i%n) != (j%n) && ((i+1)%n) != (j%n) && ((j+1)%n) != (i%n))
				g[i][j] = 1;
	for (i = 0; i < m; i++)
	{
		scanf("%lld%lld", &c.x, &c.y);
		for (j = 0; j+2 < n; j++)
			for (k = j+2; k < n; k++)
				if (g[j][k] && intersect(p[j], p[k]))
					g[j][k] = g[j][k+n] = g[j+n][k] = g[j+n][k+n] =
						g[k][j] = g[k][j+n] = g[k+n][j] = g[k+n][j+n] = 0;
	}
	m = 0;
	memset(d, -1, sizeof(d));
	for (i = 0; i < n; i++)
		m = Max(m, solve(i, i+n-1));
	printf("%d\n", m);
	return 0;
}
