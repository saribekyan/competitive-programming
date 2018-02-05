#include <stdio.h>
#include <math.h>
const double a = 1.0/sqrt(3.0);

int main()
{
	int n, m, p, q;
	double  x1, y1, x2, y2;
	while (scanf("%d%d", &n, &m)==2)
	{
		if (n>m)
		{
			n ^= m;
			m ^= n;
			n ^= m;
		}
		p = int(sqrt((double)n));
		q = int(sqrt((double)m));
		y1 = 1.5*p*a;
		if ((n-p*p)%2==0)
			y1 += a;
		else
			y1 += a/2.0;
		y2 = 1.5*q*a;
		if ((m-q*q)%2==0)
			y2 += a;
		else
			y2 += a/2.0;
		x2 = (m-q*q+1)/2;
		if ((m-q*q)%2==0)
			x2 += 0.5;
		x1 = (q-p)/2.0+(int)((n-p*p+1)/2);
		if ((n-p*p)%2==0)
			x1 += 0.5;
		printf("%.3lf\n",sqrt((y1-y2)*(y1-y2)+(x1-x2)*(x1-x2)));
	}
	return 0;
}