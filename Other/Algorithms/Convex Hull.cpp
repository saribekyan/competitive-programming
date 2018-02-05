#include <stdio.h>
#define MAX 100

int x[MAX], y[MAX], d[MAX];
int main()
{
	int n, m, i, q, k;
	scanf("%d", &n);
	q = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", x+i, y+i);
		if (y[q]>y[i] || y[q]==y[i]&&x[q]>x[i])
			q = i;
	}
	d[0] = q;
	m = 1;
	while (1)
	{
		k = 0;
		if (k==q)k=1;
		for (i = 0; i < n; i++)
		{
			if ( (x[i]-x[q])*(y[k]-y[q])-(x[k]-x[q])*(y[i]-y[q]) > 0 )
				k = i;
			else
				if ((x[i]-x[q])*(y[k]-y[q])-(x[k]-x[q])*(y[i]-y[q]) == 0 && 
					(x[i]-x[q])*(x[i]-x[q])+(y[i]-y[q])*(y[i]-y[q])>
					(x[k]-x[q])*(x[k]-x[q])+(y[k]-y[q])*(y[k]-y[q]))
					k = i;
		}
		d[m] = k;
		m++;
		if (d[0]==k)break;
		q = k;
	}
	printf("%d\n", m);
	for (i = 0; i < m; i++)
		printf("%d %d\n", x[d[i]], y[d[i]]);	
	return 0;
}