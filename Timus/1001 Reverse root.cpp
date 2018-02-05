#include <stdio.h>
#include <math.h>

long double ans[1000000];
int main()
{
	int m = 0;
	long double n;
	while (scanf("%lf", &n) == 1)
		ans[m++] = sqrt(n);
	while (m)
		printf("%.4lf\n", ans[--m]);
	return 0;
}
