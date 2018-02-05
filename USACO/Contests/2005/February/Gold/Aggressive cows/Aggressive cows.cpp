#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int x[100005];
int sub[100005];
int d[2][100005];
void read()
{
	int i;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", x+i);
}
void build()
{
	int i;
	sort(x+1, x+n+1);
	for (i = 1; i < n; i++)
		sub[i] = x[i+1]-x[i];
	sort(sub+1, sub+n);
}
bool can(int s)
{
	int i, l, j;
	l = 1;
	for (i = 2; i <= m; i++)
	{
		for (j = l+1; j <= n; j++)
			if (x[j]-x[l] >= s)
				break;
		if (j == n+1)
			return 0;
		l = j;
	}
	return 1;
}
int solve()
{
	int i, p, q, k;
	p = x[1];
	q = x[n];
	while (1)
	{
		k = (p+q)>>1;
		if (can(k))
			p = k;
		else
			q = k;
		if (q-p < 2)
			break;
	}
	if (can(q))
		return q;
	return p;
}
int main()
{
	freopen("aggr.in", "r", stdin);
	freopen("aggr.out", "w", stdout);
	read();
	build();
	printf("%d\n", solve());
	return 0;
}
