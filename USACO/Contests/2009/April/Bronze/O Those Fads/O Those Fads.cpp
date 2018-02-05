/*
PROG: fads
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int d[100010];
int main()
{
	freopen("fads.in", "r", stdin);
	freopen("fads.out", "w", stdout);
	int n, m, l, k, i;
	scanf("%d%d%d", &n, &l, &k);
	for (i = 0; i < n; i++)
		scanf("%d", d+i);
	sort(d, d+n);
	for (m = i = 0; i < n && l >= d[i]; i++)
	{
		l += k;
		m++;
	}
	printf("%d\n", m);
	return 0;
}
