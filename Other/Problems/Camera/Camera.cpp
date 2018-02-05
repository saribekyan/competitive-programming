#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 100010

struct interval
{
	int c;
	bool open;
} d[2*MAX];
bool operator <(interval a, interval b)
{
	if (a.c == b.c && a.open == b.open)
		return 0;
	return a.c < b.c || a.c == b.c && a.open;
}
int x[MAX], y[MAX];
double pointc(int m)
{
	int c, i;
	sort(d, d+m);
	for (c = i = 0; i < m; i++)
	{
		if (d[i].open)
			c++;
		else
			c--;
		if (c == m/2)
			return (d[i].c+d[i+1].c)/2.0;
	}
	return -10000000000.0;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, i;
	double X, Y;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", x+i, y+i);
	for (i = 0; i < 3; i++)
	{
		x[n+i] = x[i];
		y[n+i] = y[i];
	}
	for (m = i = 0; i < n; i++)
		if (x[i+1] == x[i+2] &&	(x[i] < x[i+1] && x[i+3] < x[i+2] && y[i+2] > y[i+1] || x[i] > x[i+1] && x[i+3] > x[i+2] && y[i+2] < y[i+1]))
		{
			d[m].c = y[i+1];
			d[m++].open = (y[i+1] < y[i+2]);
			d[m].c = y[i+2];
			d[m++].open = (y[i+1] > y[i+2]);
		}
	Y = pointc(m);
	for (m = i = 0; i < n; i++)
		if (y[i+1] == y[i+2] &&	(y[i] < y[i+1] && y[i+3] < y[i+2] && x[i+2] < x[i+1] || y[i] > y[i+1] && y[i+3] > y[i+2] && x[i+2] > x[i+1]))
		{
			d[m].c = x[i+1];
			d[m++].open = (x[i+1] < x[i+2]);
			d[m].c = x[i+2];
			d[m++].open = (x[i+1] > x[i+2]);
		}
	X = pointc(m);
	if (X < -5000000000.0 || Y < -5000000000.0)
		printf("NO\n");
	else
		printf("YES\n%.3lf %.3lf\n", X, Y);
	return 0;
}
