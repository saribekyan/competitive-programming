#include <stdio.h>
#define inf 1000000

int n;
int a[30010];
int d[30010][3];
int solve()
{
	int i, j, k;
	for (i = 0; i < 3; i++)
		d[0][i] = (i != a[0]);
	for (i = 1; i < n; i++)
		for (j = 0; j < 3; j++)
		{
			d[i][j] = inf;
			for (k = 0; k <= j; k++)
				if (d[i][j] > d[i-1][k]+(a[i] != j))
					d[i][j] = d[i-1][k]+(a[i] != j);
		}
	k = d[n-1][0];
	for (i = 1; i < 3; i++)
		if (k > d[n-1][i])
			k = d[n-1][i];
	return k;
}
int main()
{
	freopen("egroup.in", "r", stdin);
	freopen("egroup.out", "w", stdout);
	int p, q, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", a+i);
		a[i]--;
	}
	p = solve();
	for (i = 0; i < n; i++)
		a[i] = 2-a[i];
	q = solve();
	if (p > q)
		p = q;
	printf("%d\n", p);
	return 0;
}
