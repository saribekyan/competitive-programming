/*
PROG: treat
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>

int p[100010];
int t[100010];
int d[100010];
int main()
{
	freopen("treat.in", "r", stdin);
	freopen("treat.out", "w", stdout);
	int n, c, s, l, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", p+i);
		p[i]--;
	}
	memset(d, -1, sizeof(d));
	for (i = 0; i < n; i++)
		if (!t[i])
		{
			l = 1;
			c = i;
			while (!t[c])
			{
				if (d[c] != -1)
					break;
				t[c] = l++;
				c = p[c];
			}
			if (d[c] == -1)
			{
				s = p[c];
				d[c] = l-t[c];
				while (s != c)
				{
					d[s] = l-t[c];
					s = p[s];
				}
				l = t[c];
			}
			s = i;
			while (s != c)
			{
				d[s] = l-t[s]+d[c];
				s = p[s];
			}
		}
	for (i = 0; i < n; i++)
		printf("%d\n", d[i]);
	return 0;
}
