#include <stdio.h>
#include <string.h>
#define MOD 1000000007

char s[100010];
int d[100010], l[27][100010];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m, n, i, j;
	s[0] = 'Z'+1;
	scanf("%s", s+1);
	n = strlen(s);
	s[n] = 'Z'+1;
	memset(l, -1, sizeof(l));
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < 27; j++)
			l[j][i] = l[j][i-1];
		l[s[i-1]-'A'][i] = i-1;
	}
	d[0] = 1;
	for (i = 1; i < n; i++)
		for (j = 0; j < 27; j++)
			if (l[j][i] != -1)
				d[i] = (d[i]+d[l[j][i]])%MOD;
	m = 0;
	for (i = 0; i < 27; i++)
		if (l[i][n] != -1)
			m = (m+d[l[i][n]])%MOD;
	printf("%d\n", m);
	return 0;
}

