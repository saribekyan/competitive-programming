/*
PROG: fence3
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <cmath>

/*
1 |
0 _
*/
bool t[150];
double x1[150], y11[150], x2[150], y2[150];
FILE* fin = fopen("fence3.in", "r");
FILE* fout = fopen("fence3.out", "w");
int main()
{
	int n, i;
	double minx, miny, maxx, maxy, mx, my, d, md, x, y;
	fscanf(fin, "%d", &n);
	maxx = maxy = -1;
	minx = miny = 101.0;
	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%lf%lf%lf%lf", x1+i, y11+i, x2+i, y2+i);
		if (x1[i] > maxx)
			maxx = x1[i];
		if (x2[i] > maxx)
			maxx = x2[i];
		if (x1[i] < minx)
			minx = x1[i];
		if (x2[i] < minx)
			minx = x2[i];
		if (y11[i] > maxy)
			maxy = y11[i];
		if (y2[i] > maxy)
			maxy = y2[i];
		if (y11[i] < miny)
			miny = y11[i];
		if (y2[i] < miny)
			miny = y2[i];
		if (x1[i] == x2[i])
		{
			t[i] = 1;
			if (y11[i] > y2[i])
			{
				y = y11[i];
				y11[i] = y2[i];
				y2[i] = y;
			}
		}
		else
		{
			t[i] = 0;
			if (x1[i] > x2[i])
			{
				x = x1[i];
				x1[i] = x2[i];
				x2[i] = x;
			}
		}
	}
	md = 987654321.0;
	for (x = minx; x <= maxx; x += 5.0)
		for (y = miny; y <= maxy; y += 5.0)
		{
			for (i = 0, d = 0.0; i < n; i++)
				if (t[i])
					if (y >= y11[i] && y <= y2[i])
						d += fabs(x-x1[i]);
					else
						if (y < y11[i])
							d += sqrt((x-x1[i])*(x-x1[i])+(y-y11[i])*(y-y11[i]));
						else
							d += sqrt((x-x1[i])*(x-x1[i])+(y-y2[i])*(y-y2[i]));
				else
					if (x >= x1[i] && x <= x2[i])
						d += fabs(y-y11[i]);
					else
						if (x < x1[i])
							d += sqrt((x-x1[i])*(x-x1[i])+(y-y11[i])*(y-y11[i]));
						else
							d += sqrt((x-x2[i])*(x-x2[i])+(y-y11[i])*(y-y11[i]));
			if (d <= md)
			{
				md = d;
				mx = x;
				my = y;
			}
		}
	minx = mx-10.0;
	maxx = mx+10.0;
	miny = my-10.0;
	maxy = my+10.0;
	md = 987654321.0;
	for (x = minx; x <= maxx; x += 0.1)
		for (y = miny; y <= maxy; y += 0.1)
		{
			for (i = 0, d = 0.0; i < n; i++)
				if (t[i])
					if (y >= y11[i] && y <= y2[i])
						d += fabs(x-x1[i]);
					else
						if (y < y11[i])
							d += sqrt((x-x1[i])*(x-x1[i])+(y-y11[i])*(y-y11[i]));
						else
							d += sqrt((x-x1[i])*(x-x1[i])+(y-y2[i])*(y-y2[i]));
				else
					if (x >= x1[i] && x <= x2[i])
						d += fabs(y-y11[i]);
					else
						if (x < x1[i])
							d += sqrt((x-x1[i])*(x-x1[i])+(y-y11[i])*(y-y11[i]));
						else
							d += sqrt((x-x2[i])*(x-x2[i])+(y-y11[i])*(y-y11[i]));
			if (d < md)
			{
				md = d;
				mx = x;
				my = y;
			}
		}
	fprintf(fout, "%.1lf %.1lf %.1lf\n", mx, my, md);
	return 0;
}