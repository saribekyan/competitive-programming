/*
PROG: timecards
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

char s[10];
int d[150], l[150];
int main()
{
	freopen("timecards.in", "r", stdin);
	freopen("timecards.out", "w", stdout);
	int n, m, p, a, b;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		scanf("%d%s%d%d", &p, s, &a, &b);
		if (s[2] == 'A')
			l[p] = a*60+b;
		else
			d[p] += a*60+b-l[p];
	}
	for (a = 1; a <= n; a++)
		printf("%d %d\n", d[a]/60, d[a]%60);
	return 0;
}
