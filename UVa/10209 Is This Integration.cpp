#include <stdio.h>
#include <math.h>
#include <limits.h>
const double pi=2.0*acos(0.0);

int main()
{
	double a,s,s1,s2,s3,s4,s5,s6,sq;
	while (scanf("%lf", &a)==1)
	{
		s=a*a;
		sq=sqrt(3.0);
		s1=s*(1-sq/2);
		s2=s*(2*pi-3*sq)/12;
		s3=4*(s1-s2);
		s6=s*(pi-2)/2;
		s4=2*(s-s3-s6);
		s5=s-s3-s4;
		printf("%.3lf %.3lf %.3lf\n",s5,s4,s3);
	}
	return 0;
}