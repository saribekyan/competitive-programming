#include <stdio.h>

int main()
{
	double x1, y1, x2, y2, x3, y3, x, y;
	while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3)==6)
	{
		x = ( (y3-y1)*(x2*x2+y2*y2-x1*x1-y1*y1) - (y2-y1)*(x3*x3+y3*y3-x1*x1-y1*y1)) /
			( 2*((x1-x3)*(y2-y1)-(x1-x2)*(y3-y1)) );
		y = ( (x3-x1)*(y2*y2+x2*x2-y1*y1-x1*x1) - (x2-x1)*(y3*y3+x3*x3-y1*y1-x1*x1)) /
			( 2*((y1-y3)*(x2-x1)-(y1-y2)*(x3-x1)) );
		printf("%lf %lf\n", x, y);
	}
	return 0;
}