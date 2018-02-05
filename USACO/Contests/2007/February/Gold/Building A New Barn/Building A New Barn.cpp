#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX 10010

int x[2*MAX], y[2*MAX];
pair<int,int> barn[4];
pair<int,int> points[MAX];
int bx[2*MAX], barny[2*MAX];
int D(pair<int,int> a, pair<int,int> b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}
int main()
{
	freopen("newbarn.in", "r", stdin);
	freopen("newbarn.out", "w", stdout);
	int n, m, lx, ly, l, w, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &points[i].first, &points[i].second);
		points[i].first += 10000;
		points[i].second += 10000;
	}
	m = 0;
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	for (i = 0; i < n; i++)
	{
		x[points[i].first]++;
		y[points[i].second]++;
	}
	m = 0;
	lx = ly = 0;
	for (i = 0; i <= 2*MAX; i++)
	{
		m += x[i];
		if (m >= (n+1)/2)
			break;
	}
	if (n%2 == 0)
		while (m <= (n+1)/2)
		{
			bx[lx++] = i;
			m += x[++i];
		}
	bx[lx++] = i;
	m = 0;
	for (i = 0; i <= 2*MAX; i++)
	{
		m += y[i];
		if (m >= (n+1)/2)
			break;
	}
	if (n%2 == 0)
		while (m <= (n+1)/2)
		{
			barny[ly++] = i;
			m += y[++i];
		}
	barny[ly++] = i;
	m = lx*ly;
	for (i = 0; i < n; i++)
		if (binary_search(bx, bx+lx, points[i].first) && binary_search(barny, barny+ly, points[i].second))
			m--;
	l = 0;
	if (m)
		for (i = 0; i < n; i++)
			l += abs(points[i].first-bx[0])+abs(points[i].second-barny[0]);
	else
	{
		l = 123456;
		barn[0] = make_pair(bx[0], barny[0]+1);
		barn[1] = make_pair(bx[0], barny[0]-1);
		barn[2] = make_pair(bx[0]+1, barny[0]);
		barn[3] = make_pair(bx[0]-1, barny[0]);
		for (i = 0; i < 4; i++)
		{
			w = 0;
			for (j = 0; j < n; j++)
				w += D(barn[i], points[j]);
			if (w < l)
			{
				l = w;
				m = 0;
			}
			if (l == w)
				m++;
		}
	}
	printf("%d %d\n", l, m);
	return 0;
}
