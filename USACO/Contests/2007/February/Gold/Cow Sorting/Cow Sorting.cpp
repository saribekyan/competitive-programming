#include <cstdio>
#include <algorithm>
using namespace std;

bool f[10010];
int s[10010], e[10010], t[10010];
int main()
{
	freopen("csort.in", "r", stdin);
	freopen("csort.out", "w", stdout);
	int ans=0;
	int n, m, l, p, k, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", s+i);
	memcpy(e, s, sizeof(s));
	sort(e, e+n);
	for (i = 0; i < n; i++)
		t[i] = lower_bound(e, e+n, s[i])-e;
	m = e[0];
	for (i = 0; i < n; i++)
		if (!f[i])
		{
			k = 1;
			f[i] = 1;
			p = l = s[i];
			for (j = t[i]; j != i; j=t[j])
			{
				f[j] = 1;
				if (l > s[j])
					l = s[j];
				p += s[j];
				k++;
			}
			ans += p;
			if ((k-2)*l < (k+1)*m+l)
				ans += (k-2)*l;
			else
				ans += (k+1)*m+l;
		}
	printf("%d\n", ans);
	return 0;
}
