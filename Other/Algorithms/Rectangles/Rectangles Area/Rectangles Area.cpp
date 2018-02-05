#include <stdio.h>
#include <algorithm>
using namespace std ;
#define MAX 25

struct P {int r, i; bool f;};

P x[2*MAX], y[2*MAX];
bool d[MAX];

bool operator < (P p, P q){return p.r < q.r;}

int main()
{
    int s, n, i, count, cy, k, j;
	scanf("%d", &n);
	for (i=0; i<2*n; i++)
	{
		scanf("%d%d", &x[i].r, &y[i].r);
		x[i].i = y[i].i = i/2;
		x[i].f = 1;
		y[i].f = 0;
		i++;
		scanf("%d%d", &x[i].r, &y[i].r);
		x[i].i = y[i].i = i/2;
		x[i].f = 0;
		y[i].f = 1;
	}
	sort(x, x+n*2);
	sort(y, y+n*2);
	s = 0;
    for (i = 0; i < n; i++)
		d[i] = 0;
    for (i = 1; i < 2*n; i++) 
	{
		d[x[i-1].i] = x[i-1].f;
		count = 0;
		for (j = 0; j < 2*n; j++)
		{
			if (count==0)
				cy = y[j].r;
			if (d[y[j].i])
				if (y[j].f)
					count++;
				else
					count--;
			if (count==0)
				s += (x[i].r-x[i-1].r)*(y[j].r-cy);
		}
	}
	printf("%d\n", s);
}
/*
test:
4 number of rectangles
0 0 10.1 5.2 coordinates of rectangles
-3 3 5.36 7
1 6 9 15
8 3 20 8
*/