#include <cstdio>
#include <algorithm>
using namespace std;
#define Max(a, b) ((a)>(b)?(a):(b))

int m, r;
struct P
{
	int a, b;
} p[1000010];
bool operator < (P a, P b)
{
	return a.a < b.a || a.a == b.a && a.b > b.b;
}
int t[200010];
int d[200010];
void build(int m)
{
	int i;
	for (i = 1; i <= m; i++)
		t[i] = ((i^(i-1))+1)>>1;
}
void update(int s, int a)
{
	while (s <= m)
	{
		d[s] = (d[s]+a)%r;
		s += t[s];
	}
}
int sum(int s)
{
	int ret=0;
	while (s)
	{
		ret = (ret+d[s])%r;
		s -= t[s];
	}
	return ret;
}
int main()
{
	int n, k, i;
	scanf("%d%d%d%d", &m, &n, &k, &r);
	for (i = 1; i <= k; i++)
		scanf("%d%d", &p[i].b, &p[i].a);
	sort(p+1, p+k+1);
	build(m);
	for (i = 1; i <= k; i++)
		update(p[i].b, (sum(p[i].b-1)+1)%r);
	printf("%d\n", (sum(m)+1)%r);
	return 0;
}
