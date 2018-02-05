#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define eps (1e-9)
const double pi = 2.0*acos(0.0);

struct P
{
	int c;
	bool open;
	double angle, x, y, r;
} p1[2010], p[2010];
bool operator < (P a, P b)
{
	if (a.angle+eps < b.angle)
		return 1;
	if (a.angle > b.angle+eps)
		return 0;
	if (a.angle && b.angle)
		return 0;
	return a.angle;
}
double x, y, r, a;
int main()
{
	int n, m, l, i, j;
	while (scanf("%d", &n) && n)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf", &x, &y, &r);
			p1[2*i].c = p1[2*i+1].c = i;
			p1[2*i].x = p1[2*i+1].x = x;
			p1[2*i].y = p1[2*i+1].y = y;
			p1[2*i].r = p1[2*i+1].r = r;
			a = atan(fabs(y)/fabs(x));
			if (x >= 0 && y < 0)
				a = 2*pi-a;
			if (x < 0 && y >= 0)
				a += pi/2;
			if (x < 0 && y < 0)
				a += pi;
			p1[2*i].open = 1;
			p1[2*i+1].open = 0;
			p1[2*i].angle = a-asin(r/sqrt(x*x+y*y));
			p1[2*i+1].angle = a+asin(r/sqrt(x*x+y*y));
		}
		l = 0;
		m = 2*n;
		sort(p1, p1+2*n);
		for (i = 0; i < )
	}
	return 0;
}

/* D
#include <stdio.h>
#include <string.h>

int n;
int p[100];
bool t[100];
char s[100], a[100];
int c[100][100], len[100], l;
int main()
{
	int m, w, i, j;
	while (scanf("%d%d", &n, &m) && n)
	{
		memset(c, 0, sizeof(c));
		memset(len, 0, sizeof(len));
		l = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", p+i);
			p[i]--;
		}
		getchar();
		for (i = 0; i < n; i++)
			s[i] = getchar();
		s[n] = 0;
		l = 0;
		memset(t, 0, sizeof(t));
		for (i = 0; i < n; i++)
			if (!t[i])
			{
				t[i] = 1;
				len[l] = 1;
				c[l][0] = i;
				for (j = p[i]; j != i; j=p[j])
				{
					t[j] = 1;
					c[l][len[l]++] = j;
				}
				l++;
			}
		memset(a, 0, sizeof(a));
		for (i = 0; i < l; i++)
		{
			w = m%len[i];
			for (j = 0; j < len[i]; j++)
				a[c[i][j]] = s[c[i][(j-w+len[i])%len[i]]];
		}
		printf("%s\n", a);
	}
	return 0;
}

/* E
#include <stdio.h>
#include <string.h>

long long a[101];
long long d[101][101];
int main()
{
	long long ans;
	int n, k, i, j, l;
	while (scanf("%d%d", &n, &k) && n)
	{
		for (i = 0; i < n; i++)
			scanf("%lld", a+i);
		memset(d, 0, sizeof(d));
		for (i = 0; i < n; i++)
			d[1][i] = 1;
		for (i = 2; i <= k; i++)
			for (j = i-1; j < n; j++)
				for (l = 0; l < j; l++)
					if (a[l] < a[j])
						d[i][j] += d[i-1][l];
		ans = 0;
		for (i = k-1; i < n; i++)
			ans += d[k][i];
		printf("%lld\n", ans);
	}
	return 0;
}

/* C
#include <stdio.h>

int k;
int p[40];
long long d[40];
void tofib(long long x)
{
	int i;
	for (k = 1; k < 40; k++)
		if (x < d[k])
			break;
	k--;
	for (i = k; i > 0; i--)
		if (d[i] <= x)
		{
			p[i] = 1;
			x -= d[i];
		}
		else
			p[i] = 0;
}
long long number()
{
	int i;
	long long ret = 0;
	for (i = 2; i <= k; i++)
		ret += d[i-1]*p[i];
	return ret;
}
int main()
{
	int t, i;
	long long x;
	scanf("%d", &t);
	d[1] = 1;
	d[2] = 2;
	for (i = 3; i < 40; i++)
		d[i] = d[i-1]+d[i-2];
	while (t--)
	{
		scanf("%lld", &x);
		tofib(x);
		printf("%lld\n", number());
	}
	return 0;
}

/* B
#include <stdio.h>
#include <string.h>

int d[300];
char s[1000010];
int main()
{
	int n, m, p, q, w, l;
	while (scanf("%d", &m) && m)
	{
		getchar();
		gets(s);
		n = strlen(s);
		if (s[n-1] == '\n')
			n--;
		w = 1;
		p = q = 0;
		memset(d, 0, sizeof(d));
		d[s[0]] = l = 1;
		while (1)
		{
			if (q == n-1)
				break;
			if (l < m)
			{
				q++;
				if (d[s[q]] == 0)
					l++;
				d[s[q]]++;
			}
			else
				if (l == m)
					if (d[s[q+1]] == 0)
					{
						d[s[p]]--;
						if (d[s[p]] == 0)
							l--;
						p++;
					}
					else
					{
						q++;
						d[s[q]]++;
					}
			if (w < q-p+1)
				w = q-p+1;
		}
		printf("%d\n", w);
	}
	return 0;
}

/* A
#include <stdio.h>

int main()
{
	int r, a, b, l=1;
	while (scanf("%d", &r) && r)
	{
		scanf("%d%d", &a, &b);
		if (a*a+b*b <= 4*r*r)
			printf("Pizza %d fits on the table.\n", l++);
		else
			printf("Pizza %d does not fit on the table.\n", l++);
	}
	return 0;
}
*/
