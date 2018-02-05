#include <stdio.h>
#define Max(a, b) ((a)>(b)?(a):(b))

int d[2010];
int main()
{
	freopen("arithprg.in", "r", stdin);
	freopen("arithprg.out", "w", stdout);
	int n, m, i, j, k, l, p;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", d+i);
	m = 1;
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
		{
			l = d[j];
			p = d[j]-d[i];
			for (k = j+1; k < n; k++)
				if (d[k] == l+p)
					l = d[k];
			m = Max(m, (l-d[i])/p+1);
		}
	printf("%d\n", m);
	return 0;
}
