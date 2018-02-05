#include <cstdio>
#include <algorithm>
using namespace std;
#define P 1993
#define MAXN 1000000

int s[MAXN+10];
char s_ch[MAXN+10];
struct official
{
	int num, d;
} d[MAXN+10];
bool operator < (official a, official b)
{
	return a.d < b.d || a.d == b.d && a.num < b.num;
}
int main()
{
	int n, p, q, l, i;
	n = l = 0;
	do
	{
		if (getchar() == '(')
		{
			s[l] = n;
			s_ch[l++] = '(';
			d[n].d = 1;
			d[n++].num = 3;
		}
		else
		{
			p = s[--l];
			d[p].num += P;
			if (l)
			{
				q = s[l-1];
				d[q].num *= d[p].num;
				if (d[q].d < d[p].d+1)
					d[q].d = d[p].d+1;
			}
		}
	}
	while (l);
	sort(d, d+n);
	for (p = i = 1; i < n; i++)
		if (d[i].d == d[i-1].d)
			p += (d[i].num != d[i-1].num);
		else
		{
			printf("%d\n", p);
			p = 1;
		}
	printf("%d\n", p);
	return 0;
}
