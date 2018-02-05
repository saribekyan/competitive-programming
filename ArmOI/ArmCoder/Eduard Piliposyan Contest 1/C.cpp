/*
PROG: job
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
struct job
{
	int d;
	long long p;
} j[100010];
bool operator < (job a, job b)
{
	return a.p > b.p || a.p == b.p && a.d > b.d;
}
int d[200010];
int sum(int p, int q)
{
	int s = 0;
	for (p--; p > 0; p-=((p^(p-1))+1)>>1)
		s -= d[p];
	while (q > 0)
	{
		s += d[q];
		q -= ((q^(q-1))+1)>>1;
	}
	return s;
}
void add(int p)
{
	while (p <= 2*n)
	{
		d[p]++;
		p += ((p^(p-1))+1)>>1;
	}
}
int main()
{
	int p, q, k, i;
	long long ans = 0, x = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%lld", &j[i].d, &j[i].p);
		x += j[i].p;
	}
	sort(j, j+n);
	for (i = 0; i < n; i++)
		if (j[i].d > 2*n)
			ans += j[i].p;
		else
		{
			if (sum(1, j[i].d) == j[i].d)
				continue;
			p = 1;
			q = j[i].d;
			while (q-p > 1)
			{
				k = (p+q)>>1;
				if (sum(k, j[i].d) == j[i].d-k+1)
					q = k;
				else
					p = k;
			}
			if (sum(q, q) == 0)
				p = q;
			add(p);
			ans += j[i].p;
		}
	printf("%lld\n", x-ans);
	return 0;
}
