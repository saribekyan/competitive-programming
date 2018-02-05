#include <stdio.h>
#define inf 1000000000

int ds[1010];
int e[25010][3];
int main()
{
	freopen("layout.in", "r", stdin);
	freopen("layout.out", "w", stdout);
	int n, m, ml, md, p, q, d, i, j;
	scanf("%d%d%d", &n, &ml, &md);
	for (m = i = 0; i < n-1; i++)
	{
		e[m][0] = i+1;
		e[m][1] = i;
		e[m++][2] = 0;
	}
	for (i = 0; i < ml; i++)
	{
		scanf("%d%d%d", &p, &q, &d);
		if (p > q)
		{
			p ^= q;
			q ^= p;
			p ^= q;
		}
		e[m][0] = p-1;
		e[m][1] = q-1;
		e[m++][2] = d;
	}
	for (i = 0; i < md; i++)
	{
		scanf("%d%d%d", &p, &q, &d);
		if (p > q)
		{
			p ^= q;
			q ^= p;
			p ^= q;
		}
		e[m][0] = q-1;
		e[m][1] = p-1;
		e[m++][2] = -d;
	}
	ds[0] = 0;
	for (i = 1; i < n; i++)
		ds[i] = inf;
	for (i = 1; i < n; i++)
		for (j = 0; j < m; j++)
			if (ds[e[j][1]] > ds[e[j][0]]+e[j][2])
				ds[e[j][1]] = ds[e[j][0]]+e[j][2];
	for (i = 0; i < m; i++)
		if (ds[e[i][1]] > ds[e[i][0]]+e[i][2])
		{
			printf("-1\n");
			return 0;
		}
	if (ds[n-1] >= inf)
		printf("-2\n");
	else
		printf("%d\n", ds[n-1]);
	return 0;
}
