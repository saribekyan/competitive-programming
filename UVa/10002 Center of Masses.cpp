#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX 100

struct P{long long x, y;} d[MAX];

bool operator <(P p, P q){return p.x*q.y-p.y*q.x>0;}

int main()
{
	int n, i;
	long long x, y;
	double s, mx, my, w;

	while (scanf("%d", &n) && n>=3)
	{		
		scanf("%lld%lld", &x, &y);
		d[0].x=d[0].y=0;
		for (i = 1; i < n; i++)
		{
			scanf("%lld%lld", &d[i].x, &d[i].y);
			d[i].x-=x;
			d[i].y-=y;
		}
		sort(d+1, d+n);
		mx = my = s = 0.0;
		for (i = 2; i < n; i++)
		{
			w = fabs((d[i-1].x*d[i].y-d[i].x*d[i-1].y)/2.0);
			s += w;
			mx += w*(d[i-1].x+d[i].x)/3.0;
			my += w*(d[i-1].y+d[i].y)/3.0;
		}
		printf("%.3lf %.3lf\n", mx/s+x, my/s+y);
	}
	return 0;
}