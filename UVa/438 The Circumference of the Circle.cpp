#include <stdio.h>
#include <math.h>
#define pi 3.141592653589793

int main()
{
	double x1, y1, x2, y2, x3, y3, x, y;
	while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3)==6)
	{
		x = ( (y1-y2)*(y1*y1+x1*x1-y3*y3-x3*x3)-(y1-y3)*(y1*y1+x1*x1-y2*y2-x2*x2) )/
			( 2*( (x2-x1)*(y1-y3)-(x3-x1)*(y1-y2) ) );
		y = ( (x1-x2)*(x1*x1+y1*y1-x3*x3-y3*y3)-(x1-x3)*(x1*x1+y1*y1-x2*x2-y2*y2) )/
			( 2*( (y2-y1)*(x1-x3)-(y3-y1)*(x1-x2) ) );
/*		if (x3!=x1)
			x = ( x3*x3+y3*y3-x1*x1-y1*y1+2*y*y1-2*y*y3 )/( 2*(x3-x1) );
		else
			x = */
		printf("%.2lf\n", 2*pi*sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)));
	}
	return 0;
}