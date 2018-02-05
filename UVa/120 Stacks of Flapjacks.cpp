#include <stdio.h>

int d[30], n;
char s[1000];
void reverse(int k)
{
	int i, t;
	for (i = 0; i < (k+1)/2; i++)
	{
		t = d[i];
		d[i]=d[k-i];
		d[k-i]=t;
	}
}
void flip(int u)
{
	int i, max;

	if (u == 0) return;

	max = -1;
	for (i = 0; i <= u; i++)
		if (max<d[i])
			max=d[i];

	if (d[u] == max)
	{
		flip(u-1);
		return;
	}

	for (i = 0; i < u; i++)
		if (d[i] == max)
		{
			if (i == 0)
			{
				printf("%d ",n-u);
				reverse(u);
			}
			else
			{
				printf("%d %d ",n-i,n-u);
				reverse(i);
				reverse(u);
			}
			flip(u-1);
			return;
		}
}
int main()
{
	int i;
	while (gets(s)!=NULL)
	{		
		d[0]=i=n=0;
		while (s[i])
		{
			while (s[i]==' ' && s[i]) i++;
			while (s[i]!=' ' && s[i])
			{
				d[n]=d[n]*10+(s[i]-'0');
				i++;
			}
			n++;
			d[n]=0;
		}
		printf("%s\n",s);
		flip(n-1);
		printf("0\n");
	}
	return 0;
}