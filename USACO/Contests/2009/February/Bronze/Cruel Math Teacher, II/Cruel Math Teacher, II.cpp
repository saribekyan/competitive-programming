/*
PROG: cruel2
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <math.h>
#define eps 1e-5
#define inf 1000000.0

int d;
double c[15];
double f(double x)
{
	int i;
	double y=0.0;
	for (i = 0; i <= d; i++)
		y += pow(x, i)*c[i];
	return y;
}
int main()
{
	freopen("cruel2.in", "r", stdin);
	freopen("cruel2.out", "w", stdout);
	int i;
	double p, q, k, v;
	scanf("%d", &d);
	for (i = 0; i <= d; i++)
		scanf("%lf", c+i);
	if (c[d] < 0)
		for (i = 0; i <= d; i++)
			c[i] = -c[i];
	p = -inf;
	q = inf;
	for (i = 0; i < 100000; i++)
	{
		k = (p+q)/2.0;
		if (fabs(f(k)) <= eps)
			break;
		if (f(k) > 0.0)
			q = k;
		else
			p = k;
	}
	printf("%d\n", (int)(k*1000));
	return 0;
}
