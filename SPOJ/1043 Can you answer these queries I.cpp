#include <stdio.h>
#define Max(a, b) ((a)>(b)?(a):(b))
#define X -1000000000

int d[200010][5];
int w[200010], s[200010], mn[200010];
int r_val(int p)
{
	if (d[p][3] != X)
		return d[p][3];
	if (mn[d[p][1]] == mn[d[p][0]-1])
		return d[p][3] = s[d[p][1]]-s[d[p][0]-1];
	int x, y;
	x = r_val((p<<1)|1);
	y = s[d[p][1]]-s[d[(p<<1)|1][0]-1]+r_val(p<<1);
	return d[p][3] = Max(x, y);
}
int l_val(int p)
{
	if (d[p][4] != X)
		return d[p][4];
	if (mn[d[p][1]] == mn[d[p][0]-1])
		return d[p][4] = s[d[p][1]]-s[d[p][0]-1];
	int x, y;
	x = l_val(p<<1);
	y = s[d[p<<1][1]]-s[d[p][0]-1]+l_val((p<<1)|1);
	return d[p][4] = Max(x, y);
}
int get_val(int p)
{
	if (d[p][2] != X)
		return d[p][2];
	if (mn[d[p][1]] == mn[d[p][0]-1])
		return d[p][2] = s[d[p][1]]-s[d[p][0]-1];
	int x, y, z;
	x = get_val(p<<1);
	y = get_val((p<<1)|1);
	z = r_val(p<<1)+l_val((p<<1)|1);
	return d[p][2] = Max(x, Max(y, z));
}

int R(int p, int a)
{
	if (a == d[p][0])
		return r_val(p);
	if (mn[d[p][1]] == mn[a-1])
		return s[d[p][1]]-s[a-1];
	if (a >= d[(p<<1)|1][0])
		return R(((p<<1)|1), a);
	int x, y;
	x = s[d[p][1]]-s[d[(p<<1)|1][0]-1]+R((p<<1), a);
	y = r_val((p<<1)|1);
	return Max(x, y);
}
int L(int p, int b)
{
	if (b == d[p][1])
		return l_val(p);
	if (mn[b] == mn[d[p][0]-1])
		return s[b]-s[d[p][0]-1];
	if (b <= d[p<<1][1])
		return L((p<<1), b);
	int x, y;
	x = s[d[p<<1][1]]-s[d[p][0]-1]+L(((p<<1)|1), b);
	y = l_val(p<<1);
	return Max(x, y);
}
int max_sum(int p, int a, int b)
{
	if (mn[b] == mn[a-1])
		return s[b]-s[a-1];
	if (d[p][0] == a && d[p][1] == b)
		return get_val(p);
	if (b <= d[p<<1][1])
		return max_sum((p<<1), a, b);
	if (a >= d[(p<<1)|1][0])
		return max_sum(((p<<1)|1), a, b);
	int x, y, z;
	x = max_sum((p<<1), a, d[p<<1][1]);
	y = max_sum(((p<<1)|1), d[(p<<1)|1][0], b);
	z = R((p<<1), a)+L(((p<<1)|1), b);
	z = Max(z, w[d[p<<1][1]]);
	z = Max(z, w[d[(p<<1)|1][0]]);
	return Max(x, Max(y, z));
}
int main()
{
	int n, m, p, q, i;
	scanf("%d", &n);
	s[0] = mn[0] = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", w+i);
		s[i] = s[i-1]+w[i];
		mn[i] = mn[i-1];
		if (w[i] < 0)
			mn[i]++;
	}
	p = n;
	q = 0;
	while (p)
	{
		q++;
		p >>= 1;
	}
	p = (1<<q);
	d[1][0] = 1;
	d[1][1] = p;
	d[1][2] = d[1][3] = d[1][4] = -1;
	for (i = 2; i < (p<<1); i++)
	{
		d[i][2] = d[i][3] = d[i][4] = X;
		if (i&1)
		{
			d[i][0] = d[i-1][1]+1;
			d[i][1] = d[i>>1][1];
		}
		else
		{
			d[i][0] = d[i>>1][0];
			d[i][1] = ((d[i>>1][0]+d[i>>1][1])>>1);
		}
		if (d[i][0] == d[i][1])
			if (d[i][0] <= n)
				d[i][2] = d[i][3] = d[i][4] = w[d[i][0]];
			else
				d[i][2] = d[i][3] = d[i][4] = -100000000;
	}
	scanf("%d", &m);
	while (m)
	{
		scanf("%d%d", &p, &q);
		printf("%d\n", max_sum(1, p, q));
		m--;
	}
	return 0;
}
