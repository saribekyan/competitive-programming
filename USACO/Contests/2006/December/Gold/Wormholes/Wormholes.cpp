#include <stdio.h>
#define inf 1000000000

int d[510];
int e[10010][3];
int main()
{
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	int f, n, m, l, i, j;
	scanf("%d", &f);
	while (f--)
	{
		scanf("%d%d%d", &n, &m, &l);
		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d", e[i], e[i]+1, e[i]+2);
			e[m+i][0] = --e[i][1];
			e[m+i][1] = --e[i][0];
			e[m+i][2] = e[i][2];
		}
		m <<= 1;
		for (i = 0; i < l; i++)
		{
			scanf("%d%d%d", e[m], e[m]+1, e[m]+2);
			e[m][0]--;
			e[m][1]--;
			e[m][2] = -e[m++][2];
		}
		for (i = 0; i < n; i++)
			d[i] = inf;
		for (l = 0; l < n; l++)
			if (d[l] == inf)
			{
				d[l] = 0;
				for (i = 0; i < n; i++)
					for (j = 0; j < m; j++)
						if (d[e[j][1]] > d[e[j][0]]+e[j][2])
							d[e[j][1]] = d[e[j][0]]+e[j][2];
				for (i = 0; i < m; i++)
					if (d[e[i][1]] > d[e[i][0]]+e[i][2])
					{
						printf("YES\n");
						goto there;
				}
			}
there:;
		if (l == n)
			printf("NO\n");
	}
	return 0;
}
