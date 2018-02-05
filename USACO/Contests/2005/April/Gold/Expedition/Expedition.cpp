#include <cstdio>
#include <algorithm>
using namespace std;

bool t[10010];
struct P
{
	int d, f;
} a[10010];
bool operator < (P a, P b)
{
	return a.d < b.d;
}
int main()
{
	freopen("exp.in", "r", stdin);
	freopen("exp.out", "w", stdout);
	int n, l, p, k, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &a[i].d, &a[i].f);
	scanf("%d%d", &l, &p);
	l -= p;
	p = 0;
	while (l > 0)
	{
		k = -1;
		for (i = 0; i < n; i++)
			if (!t[i] && a[i].d >= l && (k == -1 || a[k].f < a[i].f))
				k = i;
		if (k == -1)
		{
			printf("-1\n");
			return 0;
		}
		l -= a[k].f;
		t[k] = 1;
		p++;
	}
	printf("%d\n", p);
	return 0;
}
