#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

short n;
short len[5];
short d[2005];
char s[5][2005];
short g[5][2005];
void read()
{
	short i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);
}
void build()
{
	short l, p, q, i, j;
	for (i = 0; i < n; i++)
		len[i] = strlen(s[i]);
	for (l = 0; l < n; l++)
	{
		memset(d, 0, sizeof(d));
		for (i = 0; i < len[l]; i++)
		{
			for (p = q = j = 0; j < len[0]; j++)
			{
				q = d[j+1];
				if (s[l][i] == s[0][j])
					d[j+1] = p+1;
				else
					d[j+1] = 0;
				p = q;
			}
			for (j = 1; j <= len[0]; j++)
				g[l][j] = Max(g[l][j], d[j]);
		}
	}
}
short solve()
{
	short ans, p, i, j;
	ans = 0;
	for (i = 1; i <= len[0]; i++)
	{
		p = 2005;
		for (j = 0; j < n; j++)
			p = Min(p, g[j][i]);
		ans = Max(ans, p);
	}
	return ans;
}
int main()
{
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);
	read();
	build();
	printf("%hd\n", solve());
	return 0;
}
