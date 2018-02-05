#include <cstdioc>
#include <algorithm>
using namespace std;
#define MAX 100000
#define Sum 0
#define Multiply 0
#define Factorial 0
#define subtract 0
#define Less 0
char E[MAX], D[MAX], ans[MAX];
void reverse(char *a, int n)
{
	int i;
	char c;
	for (i = 0; i < n/2; i++)
	{
		c = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] = c;
	}
}

void sum(char *a, char*b, char*c)
{
	int i, n, m, k;
	n = strlen(a);
	m = strlen(b);
	reverse(a,n);
	reverse(b,m);
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
	reverse(c, n);
}
void multiply(char *a, char *b, char *c)
{
	int i, j, n, m, k, d;
	char l;
	n = strlen(a);
	m = strlen(b);
	reverse(a, n);
	reverse(b, m);
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
	reverse(c, strlen(c));	
}
void subtract(char *a, char *b, char *c)
{
	int n, m, i, k;
	n = strlen(a);
	m = strlen(b);
	reverse(a, n);
	reverse(b, m);
	if (n>m)
		for (i = m; i < n; i++)
			b[i] = '0';
	else
	{
		for (i = n; i < m; i++)
			a[i] = '0';
		n = m;
	}
	for (i = 0; i <= n; i++)
		c[i] = '\0';
	for (i = 0; i < n; i++)
		if (a[i]>=b[i])
			c[i] = ((a[i]-'0')-(b[i]-'0'))+'0';
		else
		{
			k = i+1;
			while (a[k]=='0')
				a[k++] = '9';
			a[k]--;
			c[i] = ((a[i]-'0')+10-(b[i]-'0'))+'0';
		}
	i = 0;
	while (c[i]==0)c[i++]='\0';
	reverse(c, strlen(c));
}
bool less(char *a, char *b)
{
	int i;
	if (strlen(a)>strlen(b))
		return true;
	else
		if (strlen(a)!=strlen(b))
			return false;
		else
			for (i = 0; i < strlen(a); i++)
				if (a[i]>b[i])
					return true;
				else
					if (a[i]<b[i])
						return false;
	return true;
}
int main()
{
#if Sum
	char a[MAX], b[MAX], c[MAX];
	int n, i;
	scanf("%d", &n);
	scanf("%s", a);
	for (i = 0; i < n-1; i++)
	{
		scanf("%s", b);
		sum(a, b, c);
		strcpy(a, c);
	}
	printf("%s\n", c);
#endif
#if Multiply
	char a[MAX], b[MAX], c[MAX];
	int n, i;
	a[0] = '1';
	a[1] = '\0';
	multiply("20", a, c);
	printf("%s\n", c);
#endif
#if Factorial
	int n, i, t, m;
	scanf("%d", &n);
	ans[0] = '1';
	ans[1] = '\0';
	for (i = 2; i <= n;  i++)
	{
		t = i;
		m = 0;
		while (t)
		{
			D[m] = (t%10)+'0';
			m++;
			t/=10;
		}
		D[m] = '\0';
		reverse(D, D+m);
		multiply(ans, D, E);
		strcpy(ans, E);
	}
	printf("%s\n", ans);
#endif
#if subtract
	char a[MAX], b[MAX], c[MAX];
	scanf("%s%s", a, b);
	subtract(a, b, c);
	printf("%s\n", c);
#endif
#if Less
	char a[MAX], b[MAX];
	scanf("%s%s", a, b);
	printf("%d\n", less(a, b));
#endif
	char a[MAX], b[MAX], c[MAX];
	scanf("%s%s", a, b);
	multiply(a, b, c);
	printf("%s\n", c);
	return 0;
}