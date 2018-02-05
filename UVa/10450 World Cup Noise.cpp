#include <stdio.h>3
double d[55];

int main()
{
	int i, t, n;
	d[0]=1;
	d[1]=2;
	for (i = 2; i < 55; i++)d[i]=d[i-2]+d[i-1];
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		printf("Scenario #%d:\n%.0lf\n\n", i+1, d[n]);
	}
	return 0;
}