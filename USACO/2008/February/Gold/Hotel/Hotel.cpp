#include <stdio.h>

int n;
int d[200010], x[200010], y[200010];
void build(int p, int u, int v)
{
	if (u > n)
		return;
	if (u == v)
	{
		d[p] = x[p] = y[p] = 1;
		return;
	}
	int m = (u+v)>>1, l = p<<1, r = l|1;
	build(l, u, m);
	build(r, m+1, v);
	d[p] = d[l];
	if (d[p] < d[r])
		d[p] = d[r];
	if (d[p] < y[l]+x[r])
		d[p] = y[l]+x[r];
	x[p] = x[l];
	if (x[p] == m-u+1)
		x[p] += x[r];
	y[p] = y[r];
	if (y[p] == v-m)
		y[p] += y[l];
}
int find(int p, int u, int v, int s)
{
	if (x[p] >= s)
		return u;
	int m = (u+v)>>1, l = p<<1, r = l|1;
	if (d[l] >= s)
		return find(l, u, m, s);
	if (y[l]+x[r] >= s)
		return m-y[l]+1;
	return find(r, m+1, v, s);
}
void set_val(int p, int u, int v, int a, int b, int val)
{
	if (u == a && v == b)
	{
		if (val)
			d[p] = x[p] = y[p] = 0;
		else
			d[p] = x[p] = y[p] = v-u+1;
		return; 
	}
	int m = (u+v)>>1, l = p<<1, r = l|1;
	if (d[p] == v-u+1)
		d[l] = d[r] = x[l] = y[l] = x[r] = y[r] = m-u+1;
	if (d[p] == 0)
		d[l] = d[r] = x[l] = y[l] = x[r] = y[r] = 0;
	if (b <= m)
		set_val(l, u, m, a, b, val);
	if (a > m)
		set_val(r, m+1, v, a, b, val);
	if (a <= m && b > m)
	{
		set_val(l, u, m, a, m, val);
		set_val(r, m+1, v, m+1, b, val);
	}
	d[p] = d[l];
	if (d[p] < d[r])
		d[p] = d[r];
	if (d[p] < y[l]+x[r])
		d[p] = y[l]+x[r];
	x[p] = x[l];
	if (x[p] == m-u+1)
		x[p] += x[r];
	y[p] = y[r];
	if (y[p] == v-m)
		y[p] += y[l];
}
int main()
{
	freopen("hotel.in", "r", stdin);
	freopen("hotel.out", "w", stdout);
	int m, l, p, s;
	scanf("%d%d", &n, &m);
	for (l = 1; l < n; l<<=1);
	build(1, 1, l);
	while (m--)
	{
		scanf("%d", &p);
		if (p == 1)
		{
			scanf("%d", &s);
			if (d[1] < s)
				printf("0\n");
			else
			{
				p = find(1, 1, l, s);
				printf("%d\n", p);
				set_val(1, 1, l, p, p+s-1, 1);
			}
		}
		else
		{
			scanf("%d%d", &p, &s);
			set_val(1, 1, l, p, p+s-1, 0);
		}
	}
	return 0;
}
