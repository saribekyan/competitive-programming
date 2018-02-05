#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXC 1000000001

int n, m;
int A[50010], B[50010], C[100010];
struct interval
{
	int a, b;
	int next, prev;
} d[300010];
int pos[300010];
void build()
{
	int i;
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", A+i, B+i);
		C[2*i-1] = A[i];
		C[2*i] = B[i];
	}
	n = 0;
	C[2*m+1] = MAXC;
	sort(C+1, C+2*m+1);
	d[n].a = d[n].b = 0;
	d[n].prev = -1;
	d[n++].next = n+1;
	for (i = 1; i <= (m<<1); i++)
	{
		if (C[i] == C[i-1])
			continue;
		if (C[i] != C[i-1]+1)
		{
			d[n].a = C[i-1]+1;
			d[n].b = C[i]-1;
			d[n].prev = n-1;
			d[n++].next = n+1;
		}
		d[n].a = d[n].b = C[i];
		d[n].prev = n-1;
		d[n++].next = n+1;
	}
	d[n].a = C[i-1]+1;
	d[n].b = MAXC;
	d[n].prev = n-1;
	d[n++].next = -1;
}
int find_interval(int val)
{
	int p, q, k;
	p = 0;
	q = n-1;
	while (q-p > 1)
	{
		k = (p+q)>>1;
		if (d[k].a <= val && val <= d[k].b)
			return k;
		if (d[k].b < val)
			p = k;
		else
			q = k;
	}
	if (d[p].a <= val && val <= d[p].b)
		return p;
	return q;
}
void process()
{
	int a, b, ap, an, bp, bn, i;
	for (i = 1; i <= m; i++)
	{
		a = find_interval(A[i]);
		b = find_interval(B[i]);
		if (d[a].next == b)
			continue;
		ap = d[a].prev;
		an = d[a].next;
		bp = d[b].prev;
		bn = d[b].next;
		if (d[b].next == a)
		{
			d[b].next = an;
			d[an].prev = b;
			d[a].next = b;
			d[b].prev = a;
			d[a].prev = bp;
			d[bp].next = a;
		}
		else
		{
			d[ap].next = an;
			d[an].prev = ap;
			d[b].prev = a;
			d[a].next = b;
			d[a].prev = bp;
			d[bp].next = a;
		}
	}
}

int nl, np;
struct query
{
	int x, i;
} L[50010], P[50010];
bool operator < (query a, query b)
{
	return a.x < b.x;
}
void init_query()
{
	int i;
	char ch;
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		ch = 0;
		for (ch = 0; ch != 'L' && ch != 'P'; ch = getchar());
		if (ch == 'L')
		{
			scanf("%d", &L[nl].x);
			L[nl++].i = i;
		}
		else
		{
			scanf("%d", &P[np].x);
			P[np++].i = i;
		}
	}
	sort(L, L+nl);
}
int ans[50010];
void solve()
{
	int c, p, q, i;
	for (c = p = i = 0; i < nl;)
		if (p <= L[i].x && L[i].x <= p+d[c].b-d[c].a)
		{
			ans[L[i].i] = d[c].a+L[i].x-p;
			i++;
		}
		else
		{
			p += d[c].b-d[c].a+1;
			c = d[c].next;
		}
	for (p = c = 0; d[c].b != MAXC; c = d[c].next)
	{
		pos[c] = p;
		p += d[c].b-d[c].a+1;
	}
	pos[c] = p;
	for (i = 0; i < np; i++)
	{
		c = find_interval(P[i].x);
		ans[P[i].i] = pos[c]+P[i].x-d[c].a;
	}
}
void print()
{
	int x, i;
	for (i = 0; i < m; i++)
		printf("%d\n", ans[i]);
}
int main()
{
	build();
	process();
	init_query();
	solve();
	print();
	return 0;
}
/*
2
6 3
9 6
8
L 1
L 2
L 3
L 4
P 1
P 2
P 3
P 4

5
7 2
2 7
9 7
10 1
100005 99995
9
L 1
P 2
L 2
P 7
L 7
P 9
P 10
P 99999
L 100000

*/
