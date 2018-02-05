#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define Max(a, b) ((a)>(b)?(a):(b))

char s[1010][1010];
long long x[1010][1010], y[1010][1010], a1993, b1993;
struct node
{
	long long h;
	int i, j;
} d[1000010];
bool operator ==(node a, node b)
{
	return a.h == b.h;
}
bool operator < (node a, node b)
{
	if (a.h < b.h)
		return 1;
	if (a.h > b.h)
		return 0;
	if (a.i < b.i)
		return 1;
	if (a.i > b.i)
		return 0;
	return a.j < b.j;
}
int main()
{
	freopen("cipher.in", "r", stdin);
	freopen("cipher.out", "w", stdout);
	int n, m, a, b, l, k, p, r, i, j;
	scanf("%d%d", &n, &m);
	getchar();
	for (i = 1; i <= n; i++)
	{
		gets(s[i]+1);
		s[i][m+1] = 0;
	}
	scanf("%d%d", &a, &b);
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	for (j = 1; j <= m; j++)
	{
		x[a][j] = s[1][j]*1993;
		for (i = 2; i <= a; i++)
			x[a][j] = (x[a][j]+s[i][j])*1993;
	}
	a1993 = 1;
	for (i = 0; i < a; i++)
		a1993 *= 1993;
	for (i = a+1; i <= n; i++)
		for (j = 1; j <= m; j++)
			x[i][j] = (x[i-1][j]-s[i-a][j]*a1993+s[i][j])*1993;
	for (i = a; i <= n; i++)
	{
		y[i][b] = x[i][1]*a1993;
		for (j = 2; j <= b; j++)
			y[i][b] = (y[i][b]+x[i][j])*a1993;
	}
	b1993 = 1;
	for (i = 0; i < b; i++)
		b1993 *= a1993;
	for (i = a; i <= n; i++)
		for (j = b+1; j <= m; j++)
			y[i][j] = (y[i][j-1]-x[i][j-b]*b1993+x[i][j])*a1993;
	l = 0;
	for (i = a; i <= n; i++)
		for (j = b; j <= m; j++)
		{
			d[l].h = y[i][j];
			d[l].i = i;
			d[l++].j = j;
		}
	sort(d, d+l);
	r = 0;
	k = p = 1;
	for (i = 1; i < l; i++)
		if (!(d[i] == d[i-1]))
		{
			if (k < p)
			{
				k = p;
				r = i-p;
			}
			p = 1;
		}
		else
			p++;
	if (k < p)
	{
		k = p;
		r = i-p;
	}
	printf("%d %d\n", a, b);
	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= b; j++)
			printf("%c", s[d[r].i-a+i][d[r].j-b+j]);
		putchar('\n');
	}
	printf("%d\n", k);
	for (i = 0; i < k; i++)
		printf("%d %d\n", d[r+i].i-a+1, d[r+i].j-b+1);
	return 0;
}
