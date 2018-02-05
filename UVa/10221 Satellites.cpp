#include <stdio.h>
#include <math.h>
const double pi = 2.0*acos(0.0);

int main()
{
	char s[4];
	double r, angle;
	while (scanf("%lf%lf%s", &r, &angle, s) == 3)
	{
		if (s[0] == 'm')
			angle /= 60;
		while (angle > 360.0)
			angle = angle-360;
		if (angle > 180.0)
			angle = 360-angle;
		r += 6440;
		printf("%lf %lf\n", r*pi*angle/180, r*sqrt(2-2*cos(pi*angle/180)));
	}
	return 0;
}