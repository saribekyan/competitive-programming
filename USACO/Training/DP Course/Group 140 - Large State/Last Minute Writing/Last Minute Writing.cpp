/*
PROG: essay
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#define inf 1000000000

int w[1010][2];
int d[2][5010];
int main()
{
	freopen("essay.in", "r", stdin);
	freopen("essay.out", "w", stdout);
	int n, m, p, sw, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d%d", w[i], w[i]+1);
	p = 0;
	sw = 0;
	d[sw][0] = 0;
	for (i = 1; i <= m; i++)
		d[sw][i] = -inf;
	for (i = 0; i < n; i++, sw^=1)
	{
		d[sw^1][0] = -inf;
		for (j = 0; j <= w[i][1]; j++)
			if (d[sw^1][0] < d[sw][j])
				d[sw^1][0] = d[sw][j];
		if (w[i][0] == 0 && d[sw^1][0] < d[sw][0]+1)
			d[sw^1][0] = d[sw][0]+1;
		if (p < d[sw^1][0])
			p = d[sw^1][0];
		for (j = 1; j <= m; j++)
		{
			d[sw^1][j] = -inf;
			if (j >= w[i][0] && d[sw^1][j] < d[sw][j-w[i][0]]+1)
				d[sw^1][j] = d[sw][j-w[i][0]]+1;
			if (j+w[i][1] <= m && d[sw^1][j] < d[sw][j+w[i][1]])
				d[sw^1][j] = d[sw][j+w[i][1]];
			if (p < d[sw^1][j])
				p = d[sw^1][j];
		}
	}
	printf("%d\n", p);
	return 0;
}
