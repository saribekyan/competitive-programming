#include <stdio.h>
#include <math.h>

typedef double DB;
DB go(DB x, DB y, DB l, int n)
{
	if (n == 0)
		return sqrt(x*x+y*y);
	int i=1;
	DB p, q, u, v, d, r=l/3.0;
	u = v = 0.0;
	d = sqrt(x*x+y*y);
	for (p = -r; p < 1.5*r; p+=r)
		for (q = r; q > -1.5*r; q-=r)
		{
			if ((i&1) && d > sqrt((p-x)*(p-x)+(q-y)*(q-y)))
			{
				u = p;
				v = q;
				d = sqrt((p-x)*(p-x)+(q-y)*(q-y));
			}
			i++;
		}
	return go(x-u, y-v, r, n-1);
}
int main()
{
	int n;
	DB x, y, l;
	scanf("%lf%lf%lf%d", &x, &y, &l, &n);
	printf("%lf\n", go(x, y, l, n));
	return 0;
}
