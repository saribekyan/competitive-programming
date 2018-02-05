#include <stdio.h>
#include <string.h>
#define MAX 1000
char H[MAX+1][2750], b[2750];
void reverse(char *a, int n)
{
	int i;
	char ch;
	for (i = 0; i < n/2; i++)
	{
		ch = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] = ch;
	}
}
void multiply(char *a, char *s, char *c)
{
	int i, j, n, m, k, d;
	char l;
	strcpy(b, s);
	n = strlen(a);
	m = strlen(b);
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

int main()
{
	int n, i, t, m, ans;
	char a[MAX];
	H[0][0] = '1';
	H[0][1] = '\0';
	for (i = 1; i <=MAX; i++)
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
		multiply(a, H[i-1], H[i]);
	}
	while (scanf("%d", &n) == 1)
	{
		ans = 0;
		for (i = 0; i < strlen(H[n]); i++)
			ans += (H[n][i]-'0');
		printf("%d\n", ans);
	}
	return 0;
}