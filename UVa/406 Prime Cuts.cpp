#include <stdio.h>
#define MAX 200
int d[MAX], n;
int erat()
{
	int i, j, c;
	n=0;
	d[n++]=1;
	d[n++]=2;
	for (i = 3; i < 1200; i+=2)
	{
		c = 1;
		for (j = 1; j < n; j++)
			if (i%d[j]==0){c=0;break;}
		if (c)d[n++]=i;
	}
	return 0;
}
int main()
{
	int N, c, k, i;
	erat();
	while (scanf("%d%d", &N, &c)==2)
	{
		for (k = 0; d[k] <= N; k++);
		printf("%d %d:", N, c);
		if (c*2>=k)
			for (i = 0; i < k; i++)printf(" %d", d[i]);
		else
			for (i = (k+1)/2-c; i < k/2+c; i++)
				printf(" %d", d[i]);
		printf("\n\n");
	}
	return 0;
}