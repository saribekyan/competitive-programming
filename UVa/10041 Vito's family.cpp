#include <stdio.h>
#include <math.h>
#include <limits.h>
#define MAX 500
int d[MAX+1];

int main()
{
	int t,r,m,min,i,j;
	scanf("%d",&t);
	while (t)
	{
		scanf("%d",&r);
		for (i = 0; i < r; i++)
			scanf("%d",&d[i]);
		min = INT_MAX;
		for (i = 0; i < r; i++)
		{
			m = 0;
			for (j = 0; j < r; j++)
				m+=abs(d[i]-d[j]);
			if (m<min)min=m;
		}
		printf("%d\n",min);
		t--;
	}
	return 0;
}