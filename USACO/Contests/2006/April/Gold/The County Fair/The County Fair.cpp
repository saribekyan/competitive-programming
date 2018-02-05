/*
PROG: cfair
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define Max(a, b) ((a)>(b)?(a):(b))

struct booth
{
	int p, i;
} p[410];
bool operator < (booth a, booth b)
{
	return a.p < b.p;
}
int d[410];
int t[410][410];
int main()
{
	freopen("cfair.in", "r", stdin);
	freopen("cfair.out", "w", stdout);
	int n, m, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &p[i].p);
		p[i].i = i;
	}
	sort(p, p+n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", t[i]+j);
	m = 0;
	for (i = 0; i < n; i++)
	{
		d[i] = (p[i].p >= t[0][p[i].i]);
		for (j = 0; j < i; j++)
			if (p[j].p+t[p[j].i][p[i].i] <= p[i].p)
				d[i] = Max(d[i], d[j]+1);
		m = Max(m, d[i]);
	}
	printf("%d\n", m);
	return 0;
}
