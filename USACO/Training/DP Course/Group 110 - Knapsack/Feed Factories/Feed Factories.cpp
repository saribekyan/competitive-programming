/*
PROG: cowfact
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#define Max(a, b) ((a)>(b)?(a):(b))

int d[100010];
int main()
{
	freopen("cowfact.in", "r", stdin);
	freopen("cowfact.out", "w", stdout);
	int n, k, m, r, c, p, i, j;
	scanf("%d%d%d%d", &n, &k, &m, &r);
	memset(d, -1, sizeof(d));
	d[0] = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &c, &p);
		for (j = r-c; j >= 0; j--)
			if (d[j] != -1)
				d[j+c] = Max(d[j+c], d[j]+p);
	}
	j = -1;
	for (i = 1; i <= r; i++)
		if (d[i] >= k && (j == -1 || i*d[j] < j*d[i]))
			j = i;
	if (j == -1)
		printf("-1\n");
	else
		printf("%d\n", (int)(1000*(m-j*1.0/d[j])));
	return 0;
}
