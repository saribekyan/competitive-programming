#include <stdio.h>
#include <string.h>

int n;
bool f[5010];
char s[5010];
int check(int k)
{
	int c = 0, r = 0, i;
	memset(f, 0, sizeof(f));
	for (i = 0; i+k <= n; i++)
	{
		if (i >= k)
			c -= f[i-k];
		if ((s[i] == 'B')^(c&1))
		{
			f[i] = 1;
			c++;
			r++;
		}
	}
	while (i < n)
	{
		if (i >= k)
			c -= f[i-k];
		if ((s[i++] == 'B')^(c&1))
			return n+1;
	}
	return r;
}
int main()
{
	freopen("cowturn.in", "r", stdin);
	freopen("cowturn.out", "w", stdout);
	int k, m, p, q, i;
	scanf("%d", &n);
	for (p = i = 0; i < n; i++)
	{
		scanf("%s", s+i);
		p += s[i] == 'B';
	}
	q = 1;
	for (k = 2; k <= n; k++)
	{
		m = check(k);
		if (m < p)
		{
			p = m;
			q = k;
		}
	}
	printf("%d %d\n", q, p);
	return 0;
}
