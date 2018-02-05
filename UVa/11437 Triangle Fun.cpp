#include <stdio.h>
#include <math.h>

double D(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	int t;
	double x1, y1, x2, y2, x3, y3, a, b, c, l1, l2, l3;
	scanf("%d", &t);
	while (t)
	{
		scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
		a = D(x1, y1, x2, y2);
		b = D(x1, y1, x3, y3);
		c = D(x2, y2, x3, y3);
		l1 = sqrt(6*b*b-2*c*c+3*a*a)/7.0;
		l2 = sqrt(6*c*c-2*a*a+3*b*b)/7.0;
		l3 = sqrt(6*a*a-2*b*b+3*c*c)/7.0;
		a = (l1+l2+l3)/2.0;
		printf("%d\n", (int)(sqrt(a*(a-l1)*(a-l2)*(a-l3))+0.5+(1e-9)));
		t--;
	}
	return 0;
}
