#include <stdio.h>
#include <math.h>
#define eps (1e-9)
#define inf 10000000.0
const double pi = 2*acos(0.0);

int n;
int a[1010];
double angle(double r)
{
	int i;
	double ret = 0.0;
	for (i = 0; i < n; i++)
		if (a[i]-eps > 2*r)
			return 2*pi;
	for (i = 0; i < n; i++)
		if (a[i] < 2*r+eps && 2*r < a[i]+eps)
			ret += pi/2;
		else
			ret += asin(0.5*a[i]/r);
	return ret;
}
void thin(int mr)
{
	int i, j;
	double p = mr/2.0, q = inf, phi, r;
	for (i = 0; i < 100; i++)
	{
		r = (p+q)/2.0;
		phi = asin(0.5*mr/r);
		for (j = 0; j < n; j++)
			if (a[j] != mr)
				phi -= asin(0.5*a[j]/r);
		if (-eps < phi && phi < eps)
			break;
		if (phi > 0)
			p = r;
		else
			q = r;
	}
	phi = 0.0;
	for (i = 0; i < n && a[i] != mr; i++);
	for (i = (i+1)%n; a[i] != mr; i = (i+1)%n)
	{
		printf("%.9lf %.9lf\n", r*cos(phi), r*sin(phi));
		phi += 2*asin(0.5*a[i]/r);
	}
	printf("%.9lf %.9lf\n", r*cos(phi), r*sin(phi));
}
void round(int mr)
{
	int i, j;
	double p = mr/2.0, q = inf, phi, r;
	for (i = 0; i < 100; i++)
	{
		phi = 0.0;
		r = (p+q)/2.0;
		for (j = 0; j < n; j++)
			phi += asin(0.5*a[j]/r);
		if (phi+eps > pi && pi+eps > phi)
			break;
		if (phi > pi)
			p = r;
		else
			q = r;
	}
	phi = 0.0;
	for (i = 0; i < n; i++)
	{
		printf("%.9lf %.9lf\n", r*cos(phi), r*sin(phi));
		phi += 2*asin(0.5*a[i]/r);
	}
}
int main()
{
	freopen("poly.in", "r", stdin);
	freopen("poly.out", "w", stdout);
	int s, m, i;
	double p, q, r;
	scanf("%d", &n);
	for (m = s = i = 0; i < n; i++)
	{
		scanf("%d", a+i);
		s += a[i];
		if (m < a[i])
			m = a[i];
	}
	if (m >= s-m)
	{
		printf("NO SOLUTION\n");
		return 0;
	}
	p = angle(m/2.0);
	if (p < pi)
		thin(m);
	else
		round(m);
	return 0;
}
