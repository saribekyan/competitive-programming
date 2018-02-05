#include <stdio.h>
#define MAX 10000
int d[MAX+1];

int main()
{
	int n=0,l,h,r,i,m=0;
	while (scanf("%d%d%d", &l, &h, &r)==3)
	{
		for (i = l; i < r; i++)
			if (d[i]<h)d[i]=h;
		if (r>m)m=r;
	}
	h = 0;
	for (i = 0; i < m; i++)
		if (h!=d[i])
		{
			h=d[i];
			printf("%d %d ", i, h);
		}
	printf("%d 0\n", m);
	return 0;
}