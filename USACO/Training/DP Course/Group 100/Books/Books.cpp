/*
PROG: books
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))

long long d[210][110];
long long w[210][210];
long long s[210], p[210];
int main()
{
	freopen("books.in", "r", stdin);
	freopen("books.out", "w", stdout);
	long long n, k, i, j, l;
	scanf("%lld%lld", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%lld", p+i);
	for (i = 1; i <= n; i++)
		scanf("%lld", s+i);
	memset(d[0], 0, sizeof(d[0]));
	for (i = 1; i <= n; i++)
		for (j = 0; j <= k; j++)
			d[i][j] = ((1LL)<<(62LL));
	for (i = 1; i <= n; i++)
		for (j = i; j <= n; j++)
		{
			w[i][j] = 0;
			for (l = 1; l <= j-i+1; l++)
				w[i][j] += p[i+l-1]*s[l];
		}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= k; j++)
			for (l = 0; l <= i; l++)
				d[i][j] = Min(d[i][j], d[i-l][j-1]+w[i-l+1][i]);
	printf("%lld\n", d[n][k]);
	return 0;
}
