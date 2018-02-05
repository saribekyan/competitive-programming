/*
PROG: twofour
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>

int n;
char d[31][21][16][31];
char solve(char a, char b, char c, char s)
{
	if (a == n)
	{
		if (s > n-s)
			return '1';
		if (s < n-s)
			return '2';
		return '0';
	}
	char &it = d[a][b][c][s];
	if (it)
		return it;
	char r;
	it = '2';
//	2 -> 0
	if (a && a+2*b+3*c-n)
	{
		if (s)
		{
			r = solve(a-1, b, c, a-s);
			if (r == '2')
				return it = '1';
			if (r == '0')
				it = '0';
		}
		if (a-s)
		{
			r = solve(a-1, b, c, a-s-1);
			if (r == '2')
				return it = '1';
			if (r == '0')
				it = '0';
		}
	}
//	3 -> 0
	if (b && a+2*b+3*c-n)
	{
		r = solve(a+1, b-1, c, a-s);
		if (r == '2')
			return it = '1';
		if (r == '0')
			it = '0';
	}
//	3 -> 1
	if (b && 2*n-2*a-3*b-4*c)
	{
		r = solve(a+2, b-1, c, a-s);
		if (r == '2')
			return it = '1';
		if (r == '0')
			it = '0';
	}
//	4 -> 0
	if (c && a+2*b+3*c-n)
	{
		r = solve(a, b+1, c-1, a-s);
		if (r == '2')
			return it = '1';
		if (r == '0')
			it = '0';
	}
//	4 -> 1
	if (c && 2*n-2*a-3*b-4*c)
	{
		r = solve(a+1, b+1, c-1, a-s);
		if (r == '2')
			return it = '1';
		if (r == '0')
			it = '0';
	}
//	4 -> 2
	if (c && a)
	{
		if (s)
		{
			r = solve(a-1, b+2, c-1, a-s);
			if (r == '2')
				return it = '1';
			if (r == '0')
				it = '0';
		}
		if (a-s)
		{
			r = solve(a-1, b+2, c-1, a-s-1);
			if (r == '2')
				return it = '1';
			if (r == '0')
				it = '0';
		}
	}
	return it;
}
int main()
{
	freopen("twofour.in", "r", stdin);
	freopen("twofour.out", "w", stdout);
	int t, x, i;
	char a, b, c;
	scanf("%d%d", &n, &t);
	while (t--)
	{
		a = b = c = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &x);
			a += (x == 2);
			b += (x == 3);
			c += (x == 4);
		}
		printf("%c\n", solve(a, b, c, a>>1));
	}
	return 0;
}
