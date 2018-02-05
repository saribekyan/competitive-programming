#include <stdio.h>
#include <string.h>

char s[500010];
char d[1500010];
int main()
{
	freopen("prefixes.in", "r", stdin);
	freopen("prefixes.out", "w", stdout);
	int n, p, q, m, i;
	scanf("%s", s);
	n = strlen(s);
	m = 0;
	p = q = n;
	d[p] = s[0];
	for (i = 1; i < n; i++)
	{
		if (d[p] < s[i])
		{
			d[++q] = s[i];
			if (m == 0)
			{
				if (d[q-1] < s[i])
					m = -1;
				if (d[q-1] > s[i])
					m = 1;
			}
			continue;
		}
		if (d[p] > s[i])
		{
			d[--p] = s[i];
			if (s[i] < d[p+1])
				m = -1;
			if (s[i] > d[p+1])
				m = 1;
			continue;
		}
		if (m == 0)
			if (s[i] < d[q])
			{
				d[++q] = s[i];
				if (d[q-1] < s[i])
					m = -1;
				if (d[q-1] > s[i])
					m = 1;
			}
			else
			{
				d[--p] = s[i];
				if (s[i] < d[p+1])
					m = -1;
				if (s[i] > d[p+1])
					m = 1;
				continue;
			}
		if (m > 0)
			d[++q] = s[i];
		if (m < 0)
			d[--p] = s[i];
	}
	for (i = p; i <= q; i++)
		putchar(d[i]);
	putchar('\n');
	return 0;
}
