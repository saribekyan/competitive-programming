#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int d[2010][2010];
int a[2010], s[2010];
int solve(int n)
{
	int ret, i, j;
	for (i = 0; i < n; i++)
		if (a[0] >= s[i])
			d[0][i] = a[0]-s[i];
		else
			d[0][i] = 0;
	for (i = 1; i < n; i++)
	{
		d[i][0] = d[i-1][0]+abs(a[i]-s[0]);
		for (j = 1; j < n; j++)
			d[i][j] = min(d[i][j-1], d[i-1][j]+abs(a[i]-s[j]));
	}
	ret = 1000000000;
	for (i = 0; i < n; i++)
		ret = min(ret, d[n-1][i]);
	return ret;
}
int main()
{
	freopen("grading.in", "r", stdin);
	freopen("grading.out", "w", stdout);
	int n, m, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", a+i);
		s[i] = a[i];
	}
	sort(s, s+n);
	m = solve(n);
	for (i = 0; i < n; i++)
	{
		a[i] = -a[i];
		s[i] = -s[n-i-1];
	}
	m = min(m, solve(n));
	printf("%d\n", m);
	return 0;
}
