#include <stdio.h>
#include <math.h>
const float pi = 2.0*acos(0.0);
void main() {
	float r; 
	int n;
	while (scanf("%f%d", &r, &n)==2)
		printf("%.5f\n", n*sin(2.0*pi/(float)n)*r*r/2.0);	
}