#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct P
{
	int x, y, z;
} p[1010], d[1010];
bool operator < (P a, P b)
{
	return a.x < b.x || a.x == b.x && a.y < b.y || a.x == b.x && a.y == b.y && a.z < b.z;
}
int gcd(int a, int b)
{
	while (a)
	{
		b %= a;
		a ^= b;
		b ^= a;
		a ^= b;
	}
	return b;
}
int main()
{
	freopen("points.in", "r", stdin);
	freopen("points.out", "w", stdout);
	double ans = 0.0;
	int n, m, g, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
	for (i = 0; i < n; i++)
	{
		m = 0;
		for (j = 0; j < n; j++)
			if (j != i)
			{
				d[m].x = p[j].x-p[i].x;
				d[m].y = p[j].y-p[i].y;
				d[m].z = p[j].z-p[i].z;
				g = gcd(gcd(abs(d[m].x), abs(d[m].y)), abs(d[m].z));
				if (g == 0)
					d[m].x = d[m].y = d[m].z = 0;
				else
				{
					d[m].x /= g;
					d[m].y /= g;
					d[m].z /= g;
				}
				if (d[m].x < 0 || d[m].x == 0 && d[m].y < 0 || d[m].x == 0 && d[m].y == 0 && d[m].z < 0)
				{
					d[m].x = -d[m].x;
					d[m].y = -d[m].y;
					d[m].z = -d[m].z;
				}
				m++;
			}
		sort(d, d+n-1);
		for (m = j = 1; j < n-1; j++)
			if (d[j].x != d[j-1].x || d[j].y != d[j-1].y || d[j].z != d[j-1].z)
			{
				if (m > 1)
					ans += 1.0/(m+1);
				m = 1;
			}
			else
				m++;
		if (m > 1)
			ans += 1.0/(m+1);
	}
	printf("%d\n", (int)(ans+(1e-5)));
	return 0;
}
