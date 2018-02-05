#include <stdio.h>
#include <string.h>
#define Max(a, b) ((a)>(b)?(a):(b))

int t[13000];
int w[3500], d[3500];
int main()
{
	freopen("charm.in", "r", stdin);
	freopen("charm.out", "w", stdout);
	int n, m, p, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d%d", w+i, d+i);
	memset(t, -1, sizeof(t));
	t[0] = 0;
	for (i = 0; i < n; i++)
		for (j = m; j >= 0; j--)
			if (t[j] != -1 && j+w[i] <= m)
				t[j+w[i]] = Max(t[j+w[i]], t[j]+d[i]);
	p = -1;
	for (i = 1; i <= m; i++)
		p = Max(p, t[i]);
	printf("%d\n", p);
	return 0;
}
