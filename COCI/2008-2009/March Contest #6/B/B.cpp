#include <stdio.h>
#include <math.h>
#define eps (1e-9)

int main()
{
	int i;
	double x, y, p, q, cx, cy, s1, s2;
	scanf("%lf%lf", &x, &y);
	if (x <= eps && y <= eps)
	{
		printf("125.00 125.00\n");
		return 0;
	}
	if (x <= eps)
	{
		if (fabs(y-125.0) <= eps)
		{
			printf("250.00 0.00\n");
			return 0;
		}
		if (y < 125.0)
		{
			p = 0.0;
			q = 250.0;
			for (i = 0; i < 100000; i++)
			{
				cx = (p+q)/2.0;
				cy = 250.0-cx;
				s1 = fabs(cx*y-250*cx);
				s2 = 250.0*250.0-s1;
				if (s1 < s2)
					p = cx;
				else
					q = cx;
			}
			printf("%.2lf %.2lf\n", cx, cy);
		}
		else
		{
			p = 0.0;
			q = 250.0;
			for (i = 0; i < 100000; i++)
			{
				cx = (p+q)/2.0;
				cy = 0.0;
				s1 = y*cx;
				s2 = 250.0*250.0-s1;
				if (s1 < s2)
					p = cx;
				else
					q = cx;
			}
			printf("%.2lf %.2lf\n", cx, cy);
		}
		return 0;
	}



	if (y <= eps)
	{
		if (fabs(x-125.0) <= eps)
		{
			printf("0.00 250.00\n");
			return 0;
		}
		p = x;
		x = y;
		y = p;
		if (y < 125.0)
		{
			p = 0.0;
			q = 250.0;
			for (i = 0; i < 100000; i++)
			{
				cx = (p+q)/2.0;
				cy = 250.0-cx;
				s1 = fabs(cx*y-250*cx);
				s2 = 250.0*250.0-s1;
				if (s1 < s2)
					p = cx;
				else
					q = cx;
			}
			printf("%.2lf %.2lf\n", cy, cx);
		}
		else
		{
			p = 0.0;
			q = 250.0;
			for (i = 0; i < 100000; i++)
			{
				cx = (p+q)/2.0;
				cy = 0.0;
				s1 = y*cx;
				s2 = 250.0*250.0-s1;
				if (s1 < s2)
					p = cx;
				else
					q = cx;
			}
			printf("%.2lf %.2lf\n", cy, cx);
		}
		return 0;
	}

	if (fabs(x-125.00) <= eps && fabs(y-125.00) <= eps)
	{
		printf("0.00 0.00\n");
		return 0;
	}
	if (x < 125.00)
	{
		p = 0;
		q = 250.0;
		for (i = 0; i < 100000; i++)
		{
			cx = (p+q)/2.0;
			cy = 0.0;
			s1 = (250.0-cx)*y;
			s2 = 250.0*250.0-s1;
			if (s1 < s2)
				q = cx;
			else
				p = cx;
		}
		printf("%.2lf %.2lf\n", cx, cy);
	}
	else
	{
		p = 0;
		q = 250.0;
		for (i = 0; i < 100000; i++)
		{
			cx = 0.0;
			cy = (p+q)/2.0;
			s1 = (250.0-cy)*x;
			s2 = 250.0*250.0-s1;
			if (s1 < s2)
				q = cy;
			else
				p = cy;
		}
		printf("%.2lf %.2lf\n", cx, cy);
	}
	return 0;
}
