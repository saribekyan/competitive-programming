#include <stdio.h>
#include <string.h>

bool d[110][110];
int main()
{
	freopen("contest.in", "r", stdin);
	freopen("contest.out", "w", stdout);
	int n, m, i, j, k;
	scanf("%d%d", &n, &m);
	memset(d, 0, sizeof(d));
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &j, &k);
		d[j-1][k-1] = 1;
	}
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				d[i][j] = d[i][j] || d[i][k] && d[k][j];
	for (m = i = 0; i < n; i++)
	{
		d[i][i] = 1;
		for (j = 0; j < n && (d[i][j] || d[j][i]); j++);
		m += (int)(j == n);
	}
	printf("%d\n", m);
	return 0;
}
