#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	double d, l;
	scanf("%d", &t);
	while (t)
	{
		scanf("%lf%lf", &d, &l);
		printf("%.3lf\n", l*sqrt(l*l-d*d)*acos(0.0)/2);
		t--;
	}
	return 0;
}