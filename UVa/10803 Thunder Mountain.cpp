#include <cstdio>
#include <cmath>

double d[100][100], x[100], y[100], p;
int main()
{
	int t, n, i, j, k, l;
	scanf("%d", &t);
	for (l = 1; l <= t; l++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%lf%lf", x+i, y+i);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])) <= 10.0)
					d[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				else
					d[i][j] = 1000000000.0;
		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if (d[i][j] > d[i][k]+d[k][j])
						d[i][j] = d[i][k]+d[k][j];
		p = -1;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (p < d[i][j])
					p = d[i][j];
		printf("Case #%d:\n", l);
		if (p == 1000000000.0)
			printf("Send Kurdy\n");
		else
			printf("%.4lf\n", p);
		putchar('\n');
	}
	return 0;
}