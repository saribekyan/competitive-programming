#include <stdio.h>

int d[1000010];
int a[1000010], b[1000010];
int main()
{
	freopen("sound.in", "r", stdin);
	freopen("sound.out", "w", stdout);
	bool f = 0;
	int n, m, c, p, q, u, v, i;
	scanf("%d%d%d", &n, &m, &c);
	p = q = u = v = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", d+i);
		while (p < q && d[i] > a[q-1])
			q--;
		a[q++] = d[i];
		while (u < v && d[i] < b[v-1])
			v--;
		b[v++] = d[i];
		if (i >= m)
		{
			if (d[i-m] == a[p])
				p++;
			if (d[i-m] == b[u])
				u++;
		}
		if (i >= m-1 && a[p]-b[u] <= c)
		{
			f = 1;
			printf("%d\n", i-m+2);
		}
	}
	if (!f)
		printf("NONE\n");
	return 0;
}
