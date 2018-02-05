#include <stdio.h>
#include <string.h>

int s;
int a[125010];
int t[125010];
int d[125010][26];
bool equal(int i, int j)
{
	int l = 0, k;
	for (k = 0; k < a[i]; k++)
		l += (d[i][k] > 0);
	for (k = 0; k < a[j]; k++)
		l -= (d[j][k]-d[j-i][k] > 0);
	return l == 0 && d[i][a[i]] == d[j][a[j]]-d[j-i][a[j]];
}
int main()
{
	freopen("cpattern.in", "r", stdin);
	freopen("cpattern.out", "w", stdout);
	int n, m, p, i, j;
	scanf("%d%d%d", &n, &m, &s);
	for (i = 1; i <= n; i++)
		scanf("%d", a+m+1+i);
	for (i = 1; i <= m; i++)
		scanf("%d", a+i);
	for (i = 1; i <= n+m+1; i++)
	{
		for (j = 0; j <= s; j++)
			d[i][j] = d[i-1][j];
		d[i][a[i]]++;
	}
	p = 0;
	t[0] = -1;
	t[1] = 0;
	for (i = 2; i <= n+m+1; i++)
	{
		for (j = i-1; j > 0; j = t[j])
			if (equal(t[j]+1, i))
				break;
		t[i] = t[j]+1;
		if (i > 2*m && t[i] == m)
			p++;
	}
	printf("%d\n", p);
	for (i = 2*m+1; i <= n+m+1; i++)
		if (t[i] == m)
			printf("%d\n", i-2*m);
	return 0;
}
