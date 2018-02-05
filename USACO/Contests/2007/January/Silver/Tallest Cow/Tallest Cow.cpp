#include <stdio.h>
const int MAX = 10010;
int d[MAX],a[MAX],b[MAX];

FILE* fin = fopen("tallest.in", "r");
FILE* fout = fopen("tallest.out", "w");
int main()
{
	int n,r,h,p,i,j,u,v,max,in;
	fscanf(fin, "%d%d%d%d",&n,&p,&h,&r);
	for (i = 0; i < r; i++)
		fscanf(fin, "%d%d",&a[i],&b[i]);
	for (i = 0; i < n; i++)
		d[i]=h;
	for (i = 0; i < r; i++)
	{
		if (d[a[i]-1]>d[b[i]-1])
			d[a[i]-1]=d[b[i]-1];
		if (a[i]<b[i])
		{
			u = a[i];
			v = b[i];
		}
		else
		{
			u = b[i];
			v = a[i];
		}
		max = -1;
		for (j = u; j < v-1; j++)
			if (max < d[j])
				max = d[j];
		in = max-d[a[i]-1]+1;
		for (j = u; j < v-1; j++)
			d[j]-=in;
	}
	for (i = 0; i < n; i++)
		fprintf(fout,"%d\n",d[i]);
	return 0;
}