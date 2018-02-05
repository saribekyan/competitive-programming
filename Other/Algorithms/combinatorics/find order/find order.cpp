#include <stdio.h>
#define MAX 10
int d[MAX], ans[MAX];
int A(int n, int m)
{
	int r, i;
	r = 1;
	for (i = n-m+1; i <= n; i++)
		r*=i;
	return r;
}
int main()
{
	int n, m, l, i, k, p, j;
	scanf("%d%d%d", &n, &m, &l);
	for (i = 0; i < n; i++)d[i] = i+1;
	for (i = 0; i < m; i++)
	{
		k = A(--n, m-i-1);
		p = l/k;
		l %= k;
		for (j = 0; p>=0; j++)if (d[j])p--;
		j--;
		ans[i] = d[j];
		d[j] = 0;
	}
	for (i = 0; i < m; i++)printf("%d", ans[i]);
	putchar('\n');
	return 0;
}