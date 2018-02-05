/*
PROG: impster
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int s[110];
int d[1<<16];
void print(int l, int k)
{
	if (k == 0)
		return;
	print(l>>1, k-1);
	putchar((l&1)+'0');
}
int main()
{
	freopen("impster.in", "r", stdin);
	freopen("impster.out", "w", stdout);
	int n, m, df, l, k, p, b, i, j;
	scanf("%d%d", &k, &n);
	m = 1<<k;
	for (i = 0; i < m; i++)
		d[i] = n+1;
	df = k+1;
	for (i = 0; i <= n; i++)
	{
		getchar();
		for (j = 0; j < k; j++)
			s[i] = (s[i]<<1)|(getchar()-'0');
		if (i)
			d[s[i]] = 0;
	}
	for (i = 1; i <= n; i++)
		for (j = 0; j < m; j++)
			if (d[j^s[i]] > d[j]+1)
				d[j^s[i]] = d[j]+1;
	for (i = 0; i < m; i++)
		if (d[i] && d[i] != n+1)
		{
			p = s[0]^i;
			for (b = 0; p; p>>=1)
				b += p&1;
			if (b < df)
			{
				df = b;
				l = i;
			}
		}
	for (i = 1; i <= n; i++)
		if (s[i] == s[0] && (df > 0 || df == 0 && d[l] > 2))
		{
			l = s[i];
			d[l] = 2;
			break;
		}
	printf("%d\n", d[l]);
	print(l, k);
	putchar('\n');
	return 0;
}
