#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1000
struct shoe{int a,b,i;}d[MAX];
bool operator <(shoe a, shoe b){return (a.a*b.b<a.b*b.a)||(a.a*b.b<a.b*b.a&&a.i<b.i);}

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while (t)
	{
		scanf("%d",&n);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d",&d[i].a,&d[i].b);
			d[i].i=i+1;
		}
		sort(d,d+n);
		for (i = 0; i < n-1; i++)
			printf("%d ",d[i].i);
		printf("%d\n",d[n-1].i);
		t--;
		if (t)putchar('\n');
	}
	return 0;
}