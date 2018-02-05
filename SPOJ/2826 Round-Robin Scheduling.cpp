#include <cstdio>
#include <algorithm>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))

struct P
{
	int i;
	long long t;
} d[50010];
bool operator < (P a, P b)
{
	return a.t < b.t || a.t == b.t && a.i < b.i;
}
long long ans[50010];
long long t[100010][3];
int main()
{
	long long s, m;
	int n, p, l, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{	
		scanf("%lld", &d[i].t);
		d[i].i = i;
	}
	l = 0;
	p = n;
	while (p)
	{
		l++;
		p >>= 1;
	}
	p = (1<<l);
	t[1][0] = (p>>1);
	t[1][1] = n;
	t[1][2] = p;
	for (i = 2; i < p; i++)
	{
		t[i][2] = (t[i>>1][2]>>1);
		if (i&1)
			t[i][1] = t[i>>1][1]-t[i>>1][0];
		else
			t[i][1] = t[i>>1][0];
		t[i][0] = Min((t[i][2]>>1), t[i][1]);
	}
	for (i = p; i < p+n; i++)
	{
		t[i][0] = t[i][1] = -1;
		t[i][2] = d[i-p].t;
	}
	s = m = 0;
	sort(d, d+n);
	for (i = 0; i < n; i++)
	{
		l = 0;
		j = p+d[i].i;
		while (j != 1)
		{
			if (j&1)
				l += t[j>>1][0];
			else
				t[j>>1][0]--;
			t[j>>1][1]--;
			j >>= 1;
		}
		s += (d[i].t-m-1)*(n-i);
		ans[d[i].i] = s+l+1;
		s += (n-i);
		m += d[i].t-m;
	}
	for (i = 0; i < n; i++)
		printf("%lld\n", ans[i]);
	return 0;
}
