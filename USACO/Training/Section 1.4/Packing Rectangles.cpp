/*
PROG: packrec
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

struct rectangle{int a, b;} g[100];
int n;
bool t[4];

bool operator <(rectangle a, rectangle b){return a.a < b.a || a.a==b.a && a.b<b.b;}

void s(rectangle *d)
{
	int a1, b1, h, h1,i;
////1st
	b1 = d[0].b;
	if (b1 < d[1].b)
		b1 = d[1].b;
	if (b1 < d[2].b)
		b1 = d[2].b;
	if (b1 < d[3].b)
		b1 = d[3].b;
	a1 = d[0].a+d[1].a+d[2].a+d[3].a;
	if (a1*b1 == g[0].a*g[0].b)
	{
		for (i = 0; i < n; i++)
			if (g[i].a == a1 || g[i].a == b1)
				break;
		if (i==n)
		{
			g[n].a = a1;
			g[n].b = b1;
			n++;
		}
	}
	if (a1*b1 < g[0].a*g[0].b)
	{
		g[0].a = a1;
		g[0].b = b1;
		n = 1;
	}
////2nd
	if (d[0].a >= d[1].a+d[2].a+d[3].a)
		a1 = d[0].a;
	else
		a1 = d[1].a+d[2].a+d[3].a;
	b1 = d[1].b;
	if (b1 < d[2].b)
		b1 = d[2].b;
	if (b1 < d[3].b)
		b1 = d[3].b;
	b1 += d[0].b;
	if (a1*b1 == g[0].a*g[0].b)
	{
		for (i = 0; i < n; i++)
			if (g[i].a == a1 || g[i].a == b1)
				break;
		if (i==n)
		{
			g[n].a = a1;
			g[n].b = b1;
			n++;
		}
	}
	if (a1*b1 < g[0].a*g[0].b)
	{
		g[0].a = a1;
		g[0].b = b1;
		n = 1;
	}
////3rd
	if (d[0].a+d[1].a < d[3].a)
		a1 = d[3].a;
	else
		a1 = d[0].a+d[1].a;
	a1 += d[2].a;
	if (d[0].b > d[1].b)
		h = d[0].b;
	else
		h = d[1].b;
	h += d[3].b;
	if (h > d[2].b)
		b1 = h;
	else
		b1 = d[2].b;
	if (a1*b1 == g[0].a*g[0].b)
	{
		for (i = 0; i < n; i++)
			if (g[i].a == a1 || g[i].a == b1)
				break;
		if (i==n)
		{
			g[n].a = a1;
			g[n].b = b1;
			n++;
		}
	}
	if (a1*b1 < g[0].a*g[0].b)
	{
		g[0].a = a1;
		g[0].b = b1;
		n = 1;
	}
////4th
	if (d[2].a > d[1].a)
		a1 = d[2].a;
	else
		a1 = d[1].a;
	a1 += d[0].a+d[3].a;
	b1 = d[0].b;
	if (b1 < d[1].b+d[2].b)
		b1 = d[1].b+d[2].b;
	if (b1 < d[3].b)
		b1 = d[3].b;
	if (a1*b1 == g[0].a*g[0].b)
	{
		for (i = 0; i < n; i++)
			if (g[i].a == a1 || g[i].a == b1)
				break;
		if (i==n)
		{
			g[n].a = a1;
			g[n].b = b1;
			n++;
		}
	}
	if (a1*b1 < g[0].a*g[0].b)
	{
		g[0].a = a1;
		g[0].b = b1;
		n = 1;
	}
////5th
	if (d[0].a > d[1].a)
		a1 = d[0].a;
	else
		a1 = d[1].a;
	a1 += d[2].a+d[3].a;
	b1 = d[0].b+d[1].b;
	if (b1 < d[2].b)
		b1 = d[2].b;
	if (b1 < d[3].b)
		b1 = d[3].b;
	if (a1*b1 == g[0].a*g[0].b)
	{
		for (i = 0; i < n; i++)
			if (g[i].a == a1 || g[i].a == b1)
				break;
		if (i==n)
		{
			g[n].a = a1;
			g[n].b = b1;
			n++;
		}
	}
	if (a1*b1 < g[0].a*g[0].b)
	{
		g[0].a = a1;
		g[0].b = b1;
		n = 1;
	}
////6th
	if (d[0].a > d[1].a)
		if (d[3].b <= d[1].b)
			if (d[0].a+d[2].a > d[1].a+d[3].a)
				a1 = d[0].a+d[2].a;
			else
				a1 = d[1].a+d[3].a;
		else
			if (d[2].a > d[3].a)
				a1 = d[2].a + d[0].a;
			else
				a1 = d[3].a + d[0].a;
	else
		if (d[1].b <= d[3].b)
			if (d[0].a+d[2].a > d[1].a+d[3].a)
				a1 = d[0].a+d[2].a;
			else
				a1 = d[1].a+d[3].a;
		else
			if (d[2].a > d[3].a)
				a1 = d[2].a+d[1].a;
			else
				a1 = d[3].a+d[1].a;
	if (d[0].b+d[1].b > d[2].b+d[3].b)
		b1 = d[0].b+d[1].b;
	else
		b1 = d[2].b+d[3].b;
	if (a1*b1 == g[0].a*g[0].b)
	{
		for (i = 0; i < n; i++)
			if (g[i].a == a1 || g[i].a == b1)
				break;
		if (i==n)
		{
			g[n].a = a1;
			g[n].b = b1;
			n++;
		}
	}
	if (a1*b1 < g[0].a*g[0].b)
	{
		g[0].a = a1;
		g[0].b = b1;
		n = 1;
	}
}
bool next()
{
	int i;
	i = 3;
	while (i >= 0 && t[i])
	{
		t[i] = 0;
		i--;
	}
	if (i==-1)return 0;
	t[i] = 1;
	return 1;
}
rectangle d[4], a[4];
FILE* fin = fopen("packrec.in", "r");
FILE* fout = fopen("packrec.out", "w");
int main()
{
	int i, k;
	bool f;
	fscanf(fin, "%d%d%d%d%d%d%d%d", &d[0].a, &d[0].b, &d[1].a, &d[1].b, &d[2].a, &d[2].b, &d[3].a, &d[3].b);
	sort(d, d+4);
	n = 0;
	for (i = 0; i < 100; i++)
		g[i].a = g[i].b = 4096;
	k = 0;
	do
	{
		t[0] = t[1] = t[2] = t[3] = 0;
		do
		{
			for (i = 0; i < 4; i++)
				if (t[i])
				{
					a[i].a = d[i].b;
					a[i].b = d[i].a;
				}
				else
					a[i] = d[i];
			s(a);
		}
		while (next());
		k++;
	}
	while (next_permutation(d, d+4));
	fprintf(fout, "%d\n", g[0].a*g[0].b);
	for (i = 0; i < n; i++)
		if (g[i].a > g[i].b)
		{
			g[i].a ^= g[i].b;
			g[i].b ^= g[i].a;
			g[i].a ^= g[i].b;
		}
	sort(g, g+n);
	for (i = 0; i < n; i++)
		fprintf(fout, "%d %d\n", g[i].a, g[i].b);
	return 0;
}