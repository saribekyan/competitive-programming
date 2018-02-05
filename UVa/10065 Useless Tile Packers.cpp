#include <stdio.h>
#include <math.h>
#define MAX 100

int x[MAX+1], y[MAX+1], d[MAX+1];

int main()
{
	int t, n, m, p, k, i, j;
	double area1, area2;
	t = 1;
	while (scanf("%d", &n) && n)
	{
		p = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", x+i, y+i);
			if (x[p]>x[i] || (x[p]==x[i] && y[p]>y[i]))
				p = i;
		}
		x[n] = x[0];
		y[n] = y[0];
		d[0] = i = p;
		k = 1;
		while (1)
		{
			m = 0;
			if (m==i)m=1;
			for (j = 1; j < n; j++)
				if (j!=i)
					if ((x[j]-x[i])*(y[m]-y[i]) > (y[j]-y[i])*(x[m]-x[i]) ||
						((x[j]-x[i])*(y[m]-y[i]) == (y[j]-y[i])*(x[m]-x[i]) && 
						(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]) >
						(x[m]-x[i])*(x[m]-x[i])+(y[m]-y[i])*(y[m]-y[i])))
						m = j;
			d[k] = i = m;
			if (m==p)break;
			k++;
		}
		area1 = area2 = 0;
		for (i = 0; i < n; i++)
			area1 += x[i]*y[i+1]-x[i+1]*y[i];
		area1 = abs(area1)/2.0;
		for (i = 0; i < k; i++)
			area2 += x[d[i]]*y[d[i+1]]-x[d[i+1]]*y[d[i]];
		area2 = abs(area2)/2.0;
		printf("Tile #%d\nWasted Space = %.2lf %\n\n", t++, (area2-area1)*100.0/area2);
	}
	return 0;
}