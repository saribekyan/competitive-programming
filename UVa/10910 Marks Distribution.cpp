#include <stdio.h>

int d[71][71];

int main()
{
	int t, n, m, p, i, j, k;
	for (i = 0; i <= 70; i++)
	{
		d[0][i] = 0;
		d[i][0] = 1;
	}
	for (i = 1; i <= 70; i++)
		for (j = 1; j <= 70; j++)
		{
			d[i][j] = 0;
			for (k = 0; k <= j; k++)
				d[i][j] += d[i-1][j-k];
		}
	scanf("%d", &t);
	while (t)
	{
		scanf("%d%d%d", &n, &m, &p);
		printf("%d\n", d[n][m-n*p]);
		t--;
	}
	return 0;
}