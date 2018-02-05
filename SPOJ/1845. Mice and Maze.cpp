#include <stdio.h>
#define inf 1000000000

int d[110][110];
int main()
{
	int n, e, t, m, p, q, i;
	scanf("%d%d%d%d", &n, &e, &t, &m);
	for (p = 0; p < n; p++)
		for (q = 0; q < n; q++)
			if (p != q)
				d[p][q] = inf;
	while (m--)
	{
		scanf("%d%d%d", &p, &q, &i);
		if (d[p-1][q-1] > i)
			d[p-1][q-1] = i;
	}
	for (i = 0; i < n; i++)
		for (p = 0; p < n; p++)
			for (q = 0; q < n; q++)
				if (d[p][q] > d[p][i]+d[i][q])
					d[p][q] = d[p][i]+d[i][q];
	for (m = i = 0; i < n; i++)
		m += d[i][e-1] <= t;
	printf("%d\n", m);
	return 0;
}
