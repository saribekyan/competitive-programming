#include <stdio.h>
#define inf 1000000000

int n;
int d[200010], l[200010], r[200010], s[200010];
void change(int p, int v)
{
	int x, y;
	p += n-1;
	d[p] = l[p] = r[p] = s[p] = v;
	for (p >>= 1; p; p >>= 1)
	{
		d[p] = d[p<<1]+d[(p<<1)|1];
		x = l[p<<1];
		y = d[p<<1]+l[(p<<1)|1];
		if (x > y)
			l[p] = x;
		else
			l[p] = y;
		x = r[(p<<1)|1];
		y = d[(p<<1)|1]+r[p<<1];
		if (x > y)
			r[p] = x;
		else
			r[p] = y;
		x = s[p<<1];
		y = s[(p<<1)|1];
		if (x > y)
			s[p] = x;
		else
			s[p] = y;
		x = r[p<<1]+l[(p<<1)|1];
		if (s[p] < x)
			s[p] = x;
	}
}
int L(int p, int u, int v, int a)
{
	if (a == v)
		return l[p];
	int m = (u+v)>>1;
	if (a <= m)
		return L(p<<1, u, m, a);
	int x = l[p<<1];
	int y = d[p<<1]+L((p<<1)|1, m+1, v, a);
	if (x < y)
		x = y;
	return x;
}
int R(int p, int u, int v, int a)
{
	if (a == u)
		return r[p];
	int m = (u+v)>>1;
	if (a > m)
		return R((p<<1)|1, m+1, v, a);
	int x = r[(p<<1)|1];
	int y = d[(p<<1)|1]+R(p<<1, u, m, a);
	if (x < y)
		x = y;
	return x;
}
int max_val(int p, int u, int v, int a, int b)
{
	if (a == u && b == v)
		return s[p];
	int m = (u+v)>>1;
	if (b <= m)
		return max_val(p<<1, u, m, a, b);
	if (a > m)
		return max_val((p<<1)|1, m+1, v, a, b);
	int x = max_val(p<<1, u, m, a, m);
	int y = max_val((p<<1)|1, m+1, v, m+1, b);
	if (x < y)
		x = y;
	y = R(p<<1, u, m, a)+L((p<<1)|1, m+1, v, b);
	if (x < y)
		x = y;
	return x;
}
int main()
{
	int m, t, p, q, i;
	scanf("%d", &n);
	m = n;
	while (n&(n-1))
		n++;
	for (i = 1; i <= n; i++)
		d[i] = l[i] = r[i] = s[i] = -inf;
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &p);
		change(i, p);
	}
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d%d%d", &t, &p, &q);
		if (t)
			printf("%d\n", max_val(1, 1, n, p, q));
		else
			change(p, q);
	}
	return 0;
}
