#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int pos[10010];
int deg[10010];
int s[10010], t[10010];
int main()
{
	freopen("slides.in", "r", stdin);
	freopen("slides.out", "w", stdout);
	long long ans = 0;
	int n, m, p, q, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", pos+i);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &p, &q);
		deg[p-1]++;
		deg[q-1]--;
	}
	p = q = 0;
	for (i = 0; i < n; i++)
	{
		while (deg[i] < 0)
		{
			s[p++] = pos[i];
			deg[i]++;
		}
		while (deg[i] > 0)
		{
			t[q++] = pos[i];
			deg[i]--;
		}
	}
	sort(s, s+p);
	sort(t, t+q);
	for (i = 0; i < p; i++)
		ans += abs(s[i]-t[i]);
	printf("%lld\n", ans);
	return 0;
}
