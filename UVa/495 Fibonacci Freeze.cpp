#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 5000
char ans[MAX+1][2000];
void sum(char *a, char*b, char*c)
{
	bool f;
	int i, n, m, k, l;
	n = strlen(a);
	m = strlen(b);
	reverse(a,a+n);
	reverse(b,b+m);
	f = false;
	if (n>m)
	{
		for (i = m; i < n; i++)
			b[i]='0';
		f = true;
		l = m;
	}
	else
	{
		for (i = n; i < m; i++)
			a[i]='0';
		l = n;
		n = m;		
	}
	k = 0;
	for (i = 0; i < n; i++)
	{
		c[i] = ((a[i]-'0')+(b[i]-'0')+k)%10+'0';
		k = ((a[i]-'0')+(b[i]-'0')+k)/10;
	}
	if (k)
		c[n++] = k+'0';
	c[n] = '\0';
	if (f)
		b[l] = '\0';
	else
		a[l] = '\0';
	reverse(a, a+strlen(a));
	reverse(b, b+strlen(b));
	reverse(c, c+n);
}
int main()
{
	int i, n;
	ans[0][0] = '0';
	ans[1][0] = '1';
	ans[0][1]=ans[1][1] = '\0';
	for (i = 2; i <= MAX; i++)
		sum(ans[i-2], ans[i-1], ans[i]);
	while (scanf("%d", &n)==1)
		printf("The Fibonacci number for %d is %s\n", n, ans[n]);
	return 0;
}