/*
PROG: sandcas
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

long long a[25010], b[25010];
int main()
{
	freopen("sandcas.in", "r", stdin);
	freopen("sandcas.out", "w", stdout);
	long long n, x, y, p, i;
	scanf("%lld%lld%lld", &n, &x, &y);
	for (i = 0; i < n; i++)
		scanf("%lld%lld", a+i, b+i);
	sort(a, a+n);
	sort(b, b+n);
	p = 0;
	for (i = 0; i < n; i++)
		if (a[i] < b[i])
			p += (b[i]-a[i])*x;
		else
			p += (a[i]-b[i])*y;
	printf("%lld\n", p);
	return 0;
}
