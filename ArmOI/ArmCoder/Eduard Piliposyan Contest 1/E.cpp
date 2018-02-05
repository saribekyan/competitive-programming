#include <stdio.h>

int main()
{
	int n, t;
	double a, m = 0.0;
	scanf("%d%d", &n, &t);
	while (n--)
	{
		scanf("%lf", &a);
		m += a/t;
	}
	printf("%.3lf\n", m);
	return 0;
}
