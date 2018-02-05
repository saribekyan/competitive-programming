#include <stdio.h>

int main()
{
	int n, i, x, y, x0, y0, x1, y1, x2, y2, x3, y3, c, d, k;
	while (scanf("%d", &n) && n)
	{
		scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
		c = -1;
		d = (x1-x2)*(y3-y2)-(x3-x2)*(y1-y2);
		if (d == 0)c=0;
		if (d > 0)c=1;
		x = x1; y = y1;
		x0 = x2; y0 = y2;
		k = 0;
		for (i = 3; i < n; i++)
		{
			x1 = x2; y1 = y2;
			x2 = x3; y2 = y3;
			scanf("%d%d", &x3, &y3);
			d = (x1-x2)*(y3-y2)-(x3-x2)*(y1-y2);
			if (c*d<0)k = 1;
			if (d == 0)c=0;
			if (d > 0)c=1;
		}
		if (k==0 && ( (x2-x3)*(y-y3)-(x-x3)*(y2-y3) )*c>=0 &&
			((x3-x)*(y0-y)-(x0-x)*(y3-y))*c >=0 )
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}