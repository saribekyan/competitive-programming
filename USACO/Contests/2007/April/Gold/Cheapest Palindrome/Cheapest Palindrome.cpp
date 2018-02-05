/*
PROG: cheappal
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))

int c[30];
char s[2010];
int d[2][2010];
int main()
{
	freopen("cheappal.in", "r", stdin);
	freopen("cheappal.out", "w", stdout);
	char ch;
	int n, sw, i, j, k, l;
	scanf("%d%d%s", &l, &n, s);
	for (i = 0; i < l; i++)
	{
		scanf("%c%c%d%d", &ch, &ch, &k, &j);
		c[ch-'a'] = Min(k, j);
	}
	sw = 0;
	for (i = n-1; i >= 0; i--)
	{
		for (j = i+1; j < n; j++)
			if (s[i] == s[j])
				d[sw^1][j] = d[sw][j-1];
			else
				d[sw^1][j] = Min(d[sw][j]+c[s[i]-'a'], d[sw^1][j-1]+c[s[j]-'a']);
		sw ^= 1;
	}
	printf("%d\n", d[sw][n-1]);
	return 0;
}
