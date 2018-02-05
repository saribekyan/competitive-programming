#include <stdio.h>
#include <string.h>

int n;
int t[100010];
int s[100010];
_int64 d[12][100010];
void build()
{
	int p, i;
	for (i = 1; i <= n; i++)
	{
		t[i] = 1;
		while ((i&t[i])==0)
			t[i] <<= 1;
	}
}
void add(int l, int p, _int64 a)
{
	while (p <= n)
	{
		d[l][p] += a;
		p += t[p];
	}
}
_int64 sum(int l, int p)
{
	_int64 ret=0;
	while (p > 0)
	{
		ret += d[l][p];
		p -= t[p];
	}
	return ret;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int k, l, i;
	scanf("%d%d", &n, &k);
	k++;
	for (i = 1; i <= n; i++)
		scanf("%d", s+i);
	memset(d, 0, sizeof(d));
	build();
	for (i = 1; i <= n; i++)
	{
		add(1, s[i], 1);
		for (l = 2; l <= k && l <= i; l++)
			add(l, s[i], sum(l-1, s[i]-1));
	}
	printf("%I64d\n", sum(k, n));
	return 0;
}

