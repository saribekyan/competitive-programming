#include <stdio.h>
#include <math.h>
const double p = sqrt(3.0)/2.0;

int main()
{
	int n;
	double a, b;
	while (scanf("%lf%lf", &a, &b) == 2)
	{
		n = ((int)((a+p-1)/p))*((int)(b))-((int)((a+p-1)/p))/2;
		if (n < ((int)((b+p-1)/p))*((int)(a))-((int)((b+p-1)/p))/2)
			n = ((int)((b+p-1)/p))*((int)(a))-((int)((b+p-1)/p))/2;
		if (n < ((int)((a-0.5)))*((int)((b+p-1)/p)))
			n = ((int)((a-0.5)))*((int)((b+p-1)/p));
		if (n < ((int)((b-0.5)))*((int)((a+p-1)/p)))
			n = ((int)((b-0.5)))*((int)((a+p-1)/p));
		if (n <= ((int)(a))*((int)(b)))
			printf("%d grid\n", ((int)(a))*((int)(b)));
		else
			printf("%d skew\n", n);
	}
	return 0;
}