#include <cstdio>
#include <algorithm>
using namespace std;

struct point
{
	int x, y, i;
} d[10010];
bool operator <(point a, point b)
{
	return a.x < b.x || a.x == b.x && a.y < b.y;
}
int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &d[i].x, &d[i].y);
		d[i].i = i+1;
	}
	sort(d, d+n);
	for (i = 0; i < n; i+=2)
		printf("%d %d\n", d[i].i, d[i+1].i);
	return 0;
}
