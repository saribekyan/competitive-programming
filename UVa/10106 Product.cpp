#include <iostream>
using namespace std;
#define MAX 250
char X[MAX], Y[MAX];
void reverse(char *a, int n)
{
	int i;
	char t;
	for (i = 0; i < n/2; i++)
	{
		t = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] = t;
	}
}
char *multiply(char *a, char *b)
{
	if (a[0]=='0'||b[0]=='0')return "0\0";
	char *c;
	int k, d, n, m, i, j, ch;
	n = strlen(a);
	m = strlen(b);
	reverse(a, n);
	reverse(b, m);
	c = new char [n+m+1];
	for (i = 0; i <= n+m; i++)c[i] = '\0';
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; j < m;  j++)
		{
			d = (a[i]-'0')*(b[j]-'0');
			if (c[i+j]!='\0')
			{
				ch = c[i+j]-'0';
				c[i+j] = (ch+d+k)%10+'0';
				k = (ch+d+k)/10;
			}
			else
			{
				c[i+j] = (d+k)%10+'0';
				k =(d+k)/10;
			}
		}
		if (k)c[i+j++] = k+'0';
	}
	reverse(c, strlen(c));
	return c;
}
int main()
{
	while (cin >> X)
	{		
		cin >> Y;
		cout << multiply(X, Y) << '\n';
	}
	return 0;
}