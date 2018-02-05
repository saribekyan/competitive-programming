#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int d[10010];
struct interval
{
	int start, length;
} p[10010];
int solve(int e)
{
	int &it = d[e];
	if (it != -1)
		return it;
	int i;
	it = 0;
	for (i = 0; i < n; i++)
		if (i != e && p[i].start+p[i].length-1 < p[e].start)
			it = max(it, solve(i));
	it++;
	return it;
}
int main()
{
	freopen("events.in", "r", stdin);
	freopen("events.out", "w", stdout);
	int m, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &p[i].start, &p[i].length);
	memset(d, -1, sizeof(d));
	m = 0;
	for (i = 0; i < n; i++)
		m = max(m, solve(i));
	printf("%d\n", m);
	return 0;
}
