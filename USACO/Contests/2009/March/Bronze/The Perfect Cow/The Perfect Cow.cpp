/*
PROG: perfect
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100], b[100];
int main()
{
	freopen("perfect.in", "r", stdin);
	freopen("perfect.out", "w", stdout);
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", a+j);
		sort(a, a+n);
		b[i] = a[n/2];
	}
	sort(b, b+n);
	printf("%d\n", b[n/2]);
	return 0;
}
