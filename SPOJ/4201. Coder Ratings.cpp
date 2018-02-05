#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXR 100000

int d[MAXR+10];
int ans[300010];
struct coder
{
	int a, b, i;
} c[300010];
bool operator < (coder a, coder b)
{
	return a.a < b.a || a.a == b.a && a.b < b.b;
}
void inc(int p)
{
	while (p <= MAXR)
	{
		d[p]++;
		p += ((p^(p-1))+1)>>1
	}
}
int sum(int p)
{
	int s = 0;
	while (p > 0)
	{
		s += d[p];
		p -= ((p^(p-1))+1)>>1;
	}
	return s;
}
int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &c[i].a, &c[i].b);
		c[i].i = i;
	}
	sort(c, c+n);
	inc(c[0].b);
	for (i = 1; i < n; i++)
	{
		if (c[i].a == c[i-1].a && c[i].b == c[i-1].b)
			ans[c[i].i] = ans[c[i-1].i];
		else
			ans[c[i].i] = sum(c[i].b);
		inc(c[i].b);
	}
	for (i = 0; i < n; i++)
		printf("%d\n", ans[i]);
	return 0;
}
