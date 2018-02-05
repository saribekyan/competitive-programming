#include <cstdio>
#include <vector>
using namespace std;
#define L 20
#define B 100000000

vector<int> g[1010];

struct number
{
	long long a[L];
} one;

pair<int, number> d[1010][2];

number sum(number a, number b)
{
	int i;
	number c;
	long long d, k = 0;
	for (i = L-1; i >= 0; i--)
	{
		d = a.a[i]+b.a[i];
		c.a[i] = (d+k)%B;
		k = (d+k)/B;
	}
	return c;
}
number mul(number a, number b)
{
	number c;
	int i, j, n, m;
	long long p, l, k;
	for (i = 0; i < L; i++)
		c.a[i] = 0;
	for (n = 0; a.a[n] == 0; n++);
	for (m = 0; b.a[m] == 0; m++);
	for (i = L-1; i >= n; i--)
		for (j = L-1; j >= m; j--)
		{
			p = a.a[i]*b.a[j];
			for (k = i+j-L+1; p; k--)
			{
				l = c.a[k];
				c.a[k] = (l+p)%B;
				p = (l+p)/B;
			}
		}
	return c;
}
pair<int, number> solve(int p, int t)
{
	pair<int, number> &it = d[p][t];
	if (it.first != -1)
		return it;
	int i;
	pair<int, number> a, b;
	it = make_pair(0, one);
	if (t == 0)
	{
		for (i = g[p].size()-1; i >= 0; i--)
		{
			a = solve(g[p][i], 0);
			b = solve(g[p][i], 1);
			if (a.first == b.first)
			{
				if (a.first)
					a.second = sum(a.second, b.second);
			}
			else
				if (a.first < b.first)
					a = b;
			it.first += a.first;
			it.second = mul(it.second, a.second);
		}
		return it;
	}
	int j;
	pair<int, number> c;
	for (i = g[p].size()-1; i >= 0; i--)
	{
		c = solve(g[p][i], 0);
		for (j = g[p].size()-1; j >= 0; j--)
			if (j != i)
			{
				a = solve(g[p][j], 0);
				b = solve(g[p][j], 1);
				if (a.first == b.first)
				{
					if (a.first)
						a.second = sum(a.second, b.second);
				}
				else
					if (a.first < b.first)
						a = b;
				c.first += a.first;
				c.second = mul(c.second, a.second);
			}
		if (it.first < c.first+1)
			it = make_pair(c.first+1, c.second);
		else
			if (it.first == c.first+1)
				it.second = sum(it.second, c.second);
	}
	return it;
}
void print(number a)
{
	int i;
	for (i = 0; a.a[i] == 0; i++);
	printf("%lld", a.a[i]);
	while (++i < L)
		printf("%08lld", a.a[i]);
	putchar('\n');
}
int main()
{
	int n, m, p, q, i;
	pair<int, number> a, b;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("0\n1\n");
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &p);
		for (scanf("%d", &m); m > 0; m--)
		{
			scanf("%d", &q);
			g[p-1].push_back(q-1);
		}
	}
	memset(d, -1, sizeof(d));
	for (i = 0; i+1 < L; i++)
		one.a[i] = 0;
	one.a[i] = 1;
	a = solve(0, 0);
	b = solve(0, 1);
	if (a.first == b.first)
		a.second = sum(a.second, b.second);
	else
		if (a.first < b.first)
			a = b;
	printf("%d\n", a.first);
	print(a.second);
	return 0;
}
