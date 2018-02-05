/*
PROG: tower
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int d[100010], w[100010], s[100010];
int main()
{
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &j);
		s[i] = s[i-1]+j;
	}
	d[n+1] = w[n+1] = 0;
	for (i = n; i > 0; i--)
	{
		for (j = i; j <= n && (s[j]-s[i-1] < w[j+1] || d[i] >= d[j+1]+1); j++);
		d[i] = d[j+1]+1;
		w[i] = s[j]-s[i-1];
	}
	printf("%d\n", d[1]);
	return 0;
}
