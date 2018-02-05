/*
PROG: storage
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>

int d[2][260][260];
int st[260], end[260];
int a[260], b[260], h[260];
int main()
{
	freopen("storage.in", "r", stdin);
	freopen("storage.out", "w", stdout);
	int n, m, sw, x, y, i, j, k;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d%d", a+i, b+i);
	for (i = 1; i <= m; i++)
		scanf("%d", h+i);
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
			if (b[j] < b[i])
			{
				a[i] ^= a[j];
				a[j] ^= a[i];
				a[i] ^= a[j];
				b[i] ^= b[j];
				b[j] ^= b[i];
				b[i] ^= b[j];
			}
	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= m && h[j] < b[i]; j++);
		st[i] = j;
		for (j = m; j > 0 && h[j] < b[i]; j--);
		end[i] = j;
		if (j == 0)
			st[i] = end[i] = -1;
	}
	sw = 0;
	memset(d[sw], -1, sizeof(d[sw]));
	d[sw][0][m+1] = 0;
	for (i = 0; i < n; i++)
	{
		if (st[i] == -1)
			continue;
		memset(d[sw^1], -1, sizeof(d[sw^1]));
		for (j = 0; j < m+1; j++)
			for (k = j+1; k <= m+1; k++)
				if (d[sw][j][k] != -1)
				{
					if (d[sw^1][j][k] < d[sw][j][k])
						d[sw^1][j][k] = d[sw][j][k];
					x = st[i];
					if (x < j+1)
						x = j+1;
					if (x+a[i]-1 < k && x+a[i]-1 <= end[i] && d[sw^1][x+a[i]-1][k] < d[sw][j][k]+a[i]*b[i])
						d[sw^1][x+a[i]-1][k] = d[sw][j][k]+a[i]*b[i];
					x = end[i];
					if (x > k-1)
						x = k-1;
					if (x-a[i]+1 > j && x-a[i]+1 >= st[i] && d[sw^1][j][x-a[i]+1] < d[sw][j][k]+a[i]*b[i])
						d[sw^1][j][x-a[i]+1] = d[sw][j][k]+a[i]*b[i];
				}
		sw ^= 1;
	}
	x = 0;
	for (i = 0; i <= m; i++)
		for (j = i+1; j <= m+1; j++)
			if (x < d[sw][i][j])
				x = d[sw][i][j];
	printf("%d\n", x);
	return 0;
}
/*
4 6
4 1
2 1
2 2
1 3
1
2
2
3
2
1

*/
