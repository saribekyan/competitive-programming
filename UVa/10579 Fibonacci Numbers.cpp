#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 5000
char d[MAX][MAX],a[MAX],b[MAX];
void sum(int f, int s, int p)
{
	int n=strlen(d[f]),m=strlen(d[s]),i,l,k;
	strcpy(a,d[f]);
	strcpy(b,d[s]);
	reverse(a,a+n);
	reverse(b,b+m);
	for (i=m;i<n;i++)b[i]='0';
	k=0;
	for (i = 0; i < n; i++)
	{
		l=(a[i]-'0')+(b[i]-'0');
		d[p][i]=(l+k)%10+'0';
		k=(l+k)/10;
	}
	if (k){d[p][n]=k+'0';n++;}
	reverse(d[p], d[p]+n);
}

int main()
{
	int n, i;
	d[0][0]=d[1][0]='1';
	d[0][1]=d[1][1]='\0';
	for (i = 2; i < MAX; i++)
		sum(i-1,i-2,i);
	while (scanf("%d", &n)==1)printf("%s\n",d[n-1]);
	return 0;
}