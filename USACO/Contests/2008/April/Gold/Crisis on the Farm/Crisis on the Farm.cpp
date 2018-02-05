#include <stdio.h>
#include <string.h>
#define in(a, b) ((a)>(0)&&(a)<(1001)&&(b)>(0)&&(b)<(1001))

int n;
bool t[1010][1010];
int x[1010], y[1010];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int d[65][65][35], p[65][65][35];
int solve(int DX, int DY, int k)
{
	int &D = d[DX][DY][k], &P = p[DX][DY][k];
	if (D != -1)
		return D;
	int m=0, Dx, Dy, i;
	Dx = DX-31;
	Dy = DY-31;
	for (i = 0; i < n; i++)
		if (in(x[i]+Dx,y[i]+Dy) && t[x[i]+Dx][y[i]+Dy])
			m++;
	D = m;
	if (k == 0)
	{
		P = -1;
		return D;
	}
	int p;
	for (i = 0; i < 4; i++)
	{
		p = solve(DX+dx[i], DY+dy[i], k-1);
		if (p+m > D)
		{
			D = p+m;
			P = i;
		}
	}
	return D;
}
int main()
{
	freopen("crisis.in", "r", stdin);
	freopen("crisis.out", "w", stdout);
	char *s = "ENSW";
	int m, k, a, b, i;
	scanf("%d%d%d", &n, &m, &k);
	for (i = 0; i < n; i++)
		scanf("%d%d", x+i, y+i);
	memset(t, 0, sizeof(t));
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		t[a][b] = 1;
	}
	a = b = 31;
	memset(d, -1, sizeof(d));
	printf("%d\n", solve(a, b, k));
	for (i = 0; i < k; i++)
	{
		printf("%c", s[p[a][b][k-i]]);
		a += dx[p[a][b][k-i]];
		b += dy[p[a][b][k-i]];
	}
	putchar('\n');

	return 0;
}
