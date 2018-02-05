#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))

char s[40000];
char d[40000];
int main()
{
	freopen("bcl.in", "r", stdin);
	freopen("bcl.out", "w", stdout);
	int n, m, p, q, l, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("\n%c", s+i);
	q = n-1;
	m = p = 0;
	while (p <= q)
	{
		l = ((p+q)>>1);
		for (i = p; i <= l; i++)
		{
			if (s[i] < s[q-i+p])
			{
				d[m++] = s[p++];
				break;
			}
			if (s[i] > s[q-i+p])
			{
				d[m++] = s[q--];
				break;
			}
		}
		if (i == l+1)
			d[m++] = s[p++];
	}
	for (i = 0; i < n;)
	{
		for (l = 0; i < n && l < 80; i++, l++)
			putchar(d[i]);
		putchar('\n');
	}
	return 0;
}
