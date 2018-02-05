#include <stdio.h>
#define eps (1e-9)
#define Min(a, b) ((a)<(b)?(a):(b))

int n;
double d[100010], l;
bool can(double t)
{
	int i;
	double x=t;
	for (i = 1; i < n; i++)
		if (d[i]-x > l+t)
			return 0;
		else
			if (x+l >  d[i])
				x = Min(x+l, d[i]+t);
			else
				x += l;
	return 1;
}
int main()
{
	int t, i;
	double p, q, k;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lf%d", &l, &n);
		for (i = 0; i < n; i++)
			scanf("%lf", d+i);
		p = 0.0;
		q = d[n-1];
		while (q-p > eps)
		{
			k = (p+q)/2.0;
			if (can(k))
				q = k;
			else
				p = k;
		}
		printf("%lf\n", k);
	}
	return 0;
}
