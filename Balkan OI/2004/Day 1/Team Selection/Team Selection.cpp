#include <stdio.h>
#define inf 987654321
#define Min(a, b) ((a)<(b)?(a):(b))

int n;
int d[1050000];
void build()
{
	int i;
	for (i = 0; (1<<i) < n; i++);
	n = (1<<i);
	for (i = 1; i <= (n<<1); i++)
		d[i] = inf;
}
int min_val(int pos, int p, int q, int a, int b)
{
	if (a == p && b == q)
		return d[pos];
	int l = (p+q)>>1;
	if (b <= l)
		return min_val(pos<<1, p, l, a, b);
	if (a > l)
		return min_val((p<<1)|1, l+1, q, a, b);
	int u=min_val(pos<<1, p, l, a, l);
	int v=min_val((pos<<1)|1, l+1, q, l+1, b);
	return Min(u, v);
}
void update(int pos, int p, int q, int a, int v)
{
	if (p == q)
	{
		d[pos] = v;
		return;
	}
	int l = (p+q)>>1;
	if (a <= l)
		update(pos<<1, p, l, a, v);
	else
		update((pos<<1)|1, l+1, q, a, v);
	d[pos] = Min(d[pos<<1], d[(pos<<1)|1]);
}

int a[500010], b[500010];
int main()
{
	int m, s, p, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &p);
		a[p] = i;
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &p);
		b[p] = i;
	}
	m = n;
	build();
	s = 0;
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &p);
		s += (min_val(1, 1, n, 1, a[p]) > b[p]);
		update(1, 1, n, a[p], b[p]);
	}
	printf("%d\n", s);
	return 0;
}
