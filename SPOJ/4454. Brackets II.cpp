#include <stdio.h>
#include <string.h>

char s[350010];
long long st[200000], h[200000], c[200000], ans[200000];
int main()
{
	int t, n, l, i;
	scanf("%d", &t);
	while (t--)
	{
		s[0] = '(';
		scanf("%s", s+1);
		n = strlen(s);
		s[n++] = ')';
		s[n] = 0;
		l = 0;
		h[l] = 1;
		c[l] = st[l] = 0;
		ans[l++] = 0;
		for (i = 1; i < n; i++)
			if (s[i] == '(')
			{
				st[l] = i;
				c[l] = !c[l-1];
				h[l] = 1;
				ans[l++] = 0;
			}
			else
			{
				if (c[l-1])
					ans[l-1] += (i-st[l-1])*h[l-1];
				ans[l-2] += ans[l-1];
				if (c[l-2])
					ans[l-2] -= (i-st[l-1])*h[l-1];
				if (h[l-2] < h[l-1]+1)
					h[l-2] = h[l-1]+1;
				l--;
			}
		printf("%lld\n", ans[0]);
	}
	return 0;
}
