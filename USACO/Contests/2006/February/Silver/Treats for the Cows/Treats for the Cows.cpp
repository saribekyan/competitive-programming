#include <stdio.h>

int n;
int v[2001];
int d[2001][2001];
void read()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", v+i);
}
void build()
{
	int i;
	for (i = 0; i < n; i++)
		d[i][i] = v[i]*n;
}
int solve()
{
	int i, k, l, j;
	for (i = 1; i < n; i++)
		for (k = 0, l = i; l < n; k++, l++)
			if (d[k+1][l]+v[k]*(n-l+k) > d[k][l-1]+v[l]*(n-l+k))
				d[k][l] = d[k+1][l]+v[k]*(n-l+k);
			else
				d[k][l] = d[k][l-1]+v[l]*(n-l+k);
	return d[0][n-1];
}
int main()
{
	freopen("trt.in", "r", stdin);
	freopen("trt.out", "w", stdout);
	read();
	build();
	printf("%d\n", solve());
	return 0;
}
