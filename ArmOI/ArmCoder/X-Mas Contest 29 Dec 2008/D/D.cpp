#include <stdio.h>
#define Min(a, b) ((a)<(b)?(a):(b))

int d[100010][2];
int a[100010][2];
int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", a[i], a[i]+1);
	d[0][0] = 0;
	d[0][1] = 1;
	for (i = 1; i < n; i++)
		for (j = 0; j < 2; j++)
		{
			d[i][j] = n+1;
			if (a[i][j] < a[i-1][j] && a[i][j^1] < a[i-1][j^1])
				d[i][j] = d[i-1][j]+j;
			if (a[i][j] < a[i-1][j^1] && a[i][j^1] < a[i-1][j])
				d[i][j] = Min(d[i][j], d[i-1][j^1]+j);
		}
	if (Min(d[n-1][0], d[n-1][1]) >= n+1)
		printf("-1\n");
	else
		printf("%d\n", Min(d[n-1][0], d[n-1][1]));
	return 0;
}
