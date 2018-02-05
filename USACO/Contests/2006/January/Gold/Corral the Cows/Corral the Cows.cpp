#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXC 10000

int n;
int s[510];
int cx[510], cy[510];
int check(int l)
{
	int r=0, m, p, q, i, j;
	for (i = 0; i < n; i++)
	{
		m = 0;
		for (j = 0; j < n; j++)
			if (cx[i] <= cx[j] && cx[j]-cx[i] < l)
				s[m++] = cy[j];
		sort(s, s+m);
		for (p = q = 0; q < m; q++)
		{
			while (s[q]-s[p] >= l)
				p++;
			if (r < q-p+1)
				r = q-p+1;
		}
	}
	return r;
}
int main()
{
	freopen("corral.in", "r", stdin);
	freopen("corral.out", "w", stdout);
	int c, p, q, k, i;
	scanf("%d%d", &c, &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", cx+i, cy+i);
	p = 1;
	q = MAXC;
	while (q-p > 1)
	{
		k = (p+q)>>1;
		if (check(k) >= c)
			q = k;
		else
			p = k;
	}
	if (check(p) >= c)
		printf("%d\n", p);
	else
		printf("%d\n", q);
	return 0;
}
