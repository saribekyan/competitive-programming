#include <stdio.h>

int s[1<<19], e[1<<19], d[1<<19], w[1<<19];
void build(int n)
{
	int i;
	for (i = 0; n > (1<<i); i++);
	n = (1<<i);
	s[1] = 1;
	e[1] = n;
	d[1] = 0;
	for (i = 1; i < n; i++)
	{
		s[i<<1] = s[i];
		e[i<<1] = ((s[i]+e[i])>>1);
		s[(i<<1)|1] = e[i<<1]+1;
		e[(i<<1)|1] = e[i];
		d[i<<1] = d[(i<<1)|1] = 0;
	}
}
int ch(int n, int l)
{
	if (l)
		return e[n]-s[n]+1-w[n];
	return w[n];
}
void sw(int a, int b, int p)
{
	if (a == s[p] && b == e[p])
	{
		d[p<<1] ^= 1;
		d[(p<<1)|1] ^= 1;
		w[p] = b-a+1-w[p];
		return;
	}
	if (b <= e[p<<1])
		sw(a, b, p<<1);
	else
		if (a >= s[(p<<1)|1])
			sw(a, b, (p<<1)|1);
		else
		{
			sw(a, e[p<<1], p<<1);
			sw(s[(p<<1)|1], b, (p<<1)|1);
		}
	w[p] = ch(p<<1, d[p<<1])+ch((p<<1)|1, d[(p<<1)|1]);
}
int sum(int a, int b, int p, int l)
{
	l ^= d[p];
	if (a == s[p] && b == e[p])
		return ch(p, l);
	if (w[p] == 0)
		if (l)
			return b-a+1;
		else
			return 0;
	if (w[p] == e[p]-s[p]+1)
		if (l)
			return 0;
		else
			return b-a+1;
	if (b <= e[p<<1])
		return sum(a, b, p<<1, l);
	if (a >= s[(p<<1)|1])
		return sum(a, b, (p<<1)|1, l);
	return sum(a, e[p<<1], p<<1, l)+sum(s[(p<<1)|1], b, (p<<1)|1, l);
}
int main()
{
	freopen("lites.in", "r", stdin);
	freopen("lites.out", "w", stdout);
	int n, m, v, p, q, i;
	scanf("%d%d", &n, &m);
	build(n);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &v, &p, &q);
		if (v == 0)
			sw(p, q, 1);
		else
			printf("%d\n", sum(p, q, 1, 0));
	}
	return 0;
}
