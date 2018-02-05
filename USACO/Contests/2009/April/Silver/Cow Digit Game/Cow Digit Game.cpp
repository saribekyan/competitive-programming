/*
PROG: cdgame
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

bool d[1000010];
int main()
{
	freopen("cdgame.in", "r", stdin);
	freopen("cdgame.out", "w", stdout);
	int n, t, p, q;
	for (n = 1; n <= 1000000; n++)
	{
		t = n;
		p = 10;
		q = -1;
		while (t)
		{
			if (p > t%10 && t%10)
				p = t%10;
			if (q < t%10)
				q = t%10;
			t /= 10;
		}
		d[n] = 0;
		if (p != 10)
			d[n] |= !d[n-p];
		if (q != -1)
			d[n] |= !d[n-q];
	}
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		if (d[n])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
