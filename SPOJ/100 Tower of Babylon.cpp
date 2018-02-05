#include <cstdio>
#include <algorithm>
using namespace std;
#define Max(a, b) ((a)>(b)?(a):(b))

int l[200];
struct cube
{
	int x, y, z;
} d[200];
bool operator < (cube a, cube b)
{
	return a.x*a.z > b.x*b.z;
}
int main()
{
	int n, i, j;
	while (scanf("%d", &n) && n)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d%d%d", &d[i].y, &d[i].x, &d[i].z);
			d[i+n].x = d[i].x;
			d[i+n].y = d[i].z;
			d[i+n].z = d[i].y;
			d[i+2*n].x = d[i].y;
			d[i+2*n].y = d[i].x;
			d[i+2*n].z = d[i].z;
			d[i+3*n].x = d[i].y;
			d[i+3*n].y = d[i].z;
			d[i+3*n].z = d[i].x;
			d[i+4*n].x = d[i].z;
			d[i+4*n].y = d[i].x;
			d[i+4*n].z = d[i].y;
			d[i+5*n].x = d[i].z;
			d[i+5*n].y = d[i].y;
			d[i+5*n].z = d[i].x;
		}
		n *= 6;
		sort(d, d+n);
		for (i = 0; i < n; i++)
		{
			l[i] = d[i].y;
			for (j = 0; j < i; j++)
				if (d[i].x < d[j].x && d[i].z < d[j].z)
					l[i] = Max(l[i], l[j]+d[i].y);
		}
		j = 1;
		for (i = 0; i < n; i++)
			j = Max(j, l[i]);
		printf("%d\n", j);
	}
	return 0;
}
