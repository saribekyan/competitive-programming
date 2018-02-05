#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 10000

void sum(char *a, char*b, char*c)
{
	int i, n, m, k;
	n = strlen(a);
	m = strlen(b);
	reverse(a,a+n);
	reverse(b,b+m);
	if (n>m)
		for (i = m; i < n; i++)
			b[i]='0';
	else
	{
		for (i = n; i < m; i++)
			a[i]='0';
		n = m;
	}
	k = 0;
	m = 0;
	for (i = 0; i < n; i++)
	{
		c[i] = ((a[i]-'0')+(b[i]-'0')+k)%10+'0';
		k = ((a[i]-'0')+(b[i]-'0')+k)/10;	
	}
	if (k)
		c[n++] = k+'0';
	c[n] = '\0';
	reverse(c, c+n);
}

int main()
{
	char a[MAX], b[MAX], c[MAX];
	int n, i, j;
	scanf("%s", a);
	while (1)
	{
		scanf("%s", b);
		if (b[0]=='0')break;
		sum(a, b, c);
		strcpy(a, c);
	}
	printf("%s\n", c);
	return 0;
}