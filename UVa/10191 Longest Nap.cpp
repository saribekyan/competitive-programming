#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 100
char s[256],c;
struct nap{int s,f;}d[MAX+3];
bool operator <(nap a, nap b){return a.s<b.s;}
int main()
{
	int t=1,n,i,nap,st;
	while (1)
	{
		if (scanf("%d",&n)!=1)return 0;
		d[0].s=d[0].f=0;
		d[n+1].s=d[n+1].f=480;
		c = getchar();
		for (i = 1; i <= n; i++)
		{
			st=(getchar()-'0')*10+(getchar()-'0');
			getchar();
			nap=(getchar()-'0')*10+(getchar()-'0');
			getchar();
			d[i].s = (st-10)*60+nap;
			st=(getchar()-'0')*10+(getchar()-'0');
			getchar();
			nap=(getchar()-'0')*10+(getchar()-'0');
			d[i].f = (st-10)*60+nap;
			gets(s);
		}
		sort(d+1,d+n+1);
		nap=st=0;
		for (i = 1; i <= n+1; i++)
			if (d[i].s-d[i-1].f>nap)
			{
				nap = d[i].s-d[i-1].f;
				st = d[i-1].f;
			}
		printf("Day #%d: the longest nap starts at %d:",t,10+st/60);
		if (st%60<10)putchar('0');
		printf("%d and will last for ",st%60);
		if (nap/60)
			printf("%d hours and %d minutes.\n",nap/60,nap%60);
		else printf("%d minutes.\n",nap%60);
		t++;
	}
}