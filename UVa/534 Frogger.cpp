#include <stdio.h>
#include <math.h>
#define min(a, b) ((a)<(b)?(a):(b))
#define max(a, b) ((a)>(b)?(a):(b))

int x[200], y[200];
double d[200][200];
int main()
{
	int n, i, j, k, l;
	l = 1;
	while (scanf("%d", &n) && n)
	{
		for (i = 0; i < n; i++)
			scanf("%d%d", x+i, y+i);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				d[i][j] = sqrt((double)((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", l++, d[0][1]);
	}
	return 0;
}