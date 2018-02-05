/*
PROG: milk3
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int d1[50], d2[50], ans[24], A, B, C, n, m;

void rec(int a, int b, int c)
{
	int i;
	for (i = 0; i < m; i++)
		if (d1[i]==a && d2[i]==b)
			return ;
	d1[m] = a;
	d2[m] = b;
	m++;
	if (a==0)
	{
		for (i = 0; i < n; i++)
			if (ans[i]==c)
				return ;
		ans[n++] = c;
	}
	int a1, b1, c1;
	a1 = a;
	b1 = b;
	c1 = c;
	if (a)
	{
		if (a+b<=B)
		{
			a1 = 0;
			b1 = a+b;
		}
		else
		{
			a1 = a-B+b;
			b1 = B;
		}
		rec(a1, b1, c);
		if (a+c<=C)
		{
			a1 = 0;
			c1 = a+c;
		}
		else
		{
			a1 = a-C+c;
			c1 = C;
		}
		rec(a1, b, c1);
	}
	if (b)
	{
		if (a+b<=A)
		{
			b1 = 0;
			a1 = a+b;
		}
		else
		{
			b1 = b-A+a;
			a1 = A;
		}
		rec(a1, b1, c);
		if (b+c<=C)
		{
			b1 = 0;
			c1 = b+c;
		}
		else
		{
			b1 = b-C+c;
			c1 = C;
		}
		rec(a, b1, c1);
	}
	if (c)
	{
		if (a+c<=A)
		{
			c1 = 0;
			a1 = a+c;
		}
		else
		{
			c1 = c-A+a;
			a1 = A;
		}
		rec(a1, b, c1);
		if (b+c<=B)
		{
			c1 = 0;
			b1 = b+c;
		}
		else
		{
			c1 = c-B+b;
			b1 = B;
		}
		rec(a, b1, c1);
	}
}
FILE* fin = fopen("milk3.in", "r");
FILE* fout = fopen("milk3.out", "w");
int main()
{
	int i;
	fscanf(fin, "%d%d%d", &A, &B, &C);
	n = m = 0;
	rec(0, 0, C);
	sort(ans, ans+n);
	for (i = 0; i < n-1; i++)
		fprintf(fout, "%d ", ans[i]);
	fprintf(fout, "%d\n", ans[n-1], m);
	return 0;
}