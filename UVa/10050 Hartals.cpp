#include <stdio.h>
#define MAX 3700
bool d[MAX];

int main()
{
	int t,n,p,h,ans,i,j;
	scanf("%d",&t);
	while (t)
	{
		scanf("%d%d", &n,&p);
		ans = 0;
		for (i = 0; i < n; i++)d[i]=0;
		for (i = 0; i < p; i++)
		{
			scanf("%d",&h);
			for (j = h-1; j < n; j+=h)
				if (d[j]==0 && j%7!=5 && j%7!=6)
				{
					d[j]=1;
					ans++;
				}
		}
		printf("%d\n",ans);
		t--;
	}
	return 0;
}