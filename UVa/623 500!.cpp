#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1000
char ans[MAX+1][2750];
void multiply(char *a, char *b, char *c)
{
	int i, j, n, m, k, d;
	char l;
	n = strlen(a);
	m = strlen(b);
	reverse(b, b+m);
	for (i = 0; i < m+n+1; i++)
		c[i] = '\0';
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; j < m; j++)
		{
			d = (a[i]-'0')*(b[j]-'0');
			if (c[i+j]!='\0')
			{
				l = c[i+j];
				c[i+j] = (((c[i+j]-'0')+(d%10)+k)%10)+'0';
				k = ((l-'0')+d+k)/10;
			}
			else
			{
				c[i+j] = (((d%10)+k)%10)+'0';			
				k = (d+k)/10;
			}			
		}
		if (k)
			c[i+j] = k+'0';
	}		
	reverse(c, c+strlen(c));
	reverse(b, b+strlen(b));
}

int main()
{
	int n, i, t, m;
	char a[MAX];
	ans[0][0] = '1';
	ans[0][1] = '\0';
	for (i = 1; i <=1000; i++)
	{
		t =i;
		m = 0;
		while (t)
		{
			a[m] = (t%10)+'0';
			m++;
			t/=10;
		}
		a[m] = '\0';
		multiply(a, ans[i-1], ans[i]);
	}
	while (scanf("%d", &n)==1)
		printf("%d!\n%s\n", n, ans[n]);
	return 0;
}
