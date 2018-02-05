#include <cstdio>
#include <algorithm>
using namespace std;

int s[50010], f[100010];
struct cow
{
	int x, t;
} d[50010];
bool operator < (cow a, cow b)
{
	return a.x < b.x;
}
int main()
{
	freopen("balance.in", "r", stdin);
	freopen("balance.out", "w", stdout);
	int n, m, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d%d", &d[i].t, &d[i].x);
	s[0] = 0;
	sort(d+1, d+n+1);
	for (i = 1; i <= n; i++)
	{
		if (d[i].t)
			s[i] = s[i-1]+1;
		else
			s[i] = s[i-1]-1;
		if (f[s[i]+n] == 0)
			f[s[i]+n] = i;
	}
	m = 0;
	for (i = 1; i <= n; i++)
		if (f[s[i]+n] != i && m < d[i].x-d[f[s[i]+n]+1].x)
			m = d[i].x-d[f[s[i]+n]+1].x;
	printf("%d\n", m);
	return 0;
}
