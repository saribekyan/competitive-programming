#include <stdio.h>
#include <string.h>
#define MAX 1000
char a[MAX], b[MAX], d[370][MAX], h[4], t;
int ans[10];
void reverse(char *f, int n)
{
	int i;
	for (i = 0; i < n/2; i++)
	{
		t = f[i];
		f[i]=f[n-i-1];
		f[n-i-1]=t;
	}
}
void multiply_f(char *f, char *s, int p)
{
	int i, j, k, v, l, q, n=strlen(f), m=strlen(s);
	strcpy(a,f);
	strcpy(b,s);
	reverse(a,n);
	for (i = 0; i <= n+m+1; i++)d[p][i]='\0';
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; j < m; j++)
		{
			q = i+j;
			if (d[p][q]=='\0')d[p][q]='0';
			v = (a[i]-'0')*(b[j]-'0');
			l = d[p][q]-'0';
			d[p][q]=(v+l+k)%10+'0';
			k=(v+l+k)/10;
		}
		if (k)d[p][q+1]=k+'0';
	}
	reverse(d[p], strlen(d[p]));
}
int main()
{
	int n, l, k, i;
	d[0][0]='1';
	d[0][1]='\0';
	for (i = 1; i < 370; i++)
	{
		l = i;
		k = 0;
		while (l)
		{
			h[k]=l%10+'0';
			l/=10;
			k++;
		}
		multiply_f(d[i-1], h, i);
	}
	while (scanf("%d", &n)&&n)
	{
		printf("%d! --\n", n);
		k = strlen(d[n]);
		for (i = 0; i < 10; i++)
			ans[i]=0;
		for (i = 0; i < k; i++)
			ans[d[n][i]-'0']++;
		for (i = 0; i < 5; i++)
			printf("   (%d)%3d", i, ans[i]);
		putchar('\n');
		for (i = 5; i < 10; i++)
			printf("   (%d)%3d", i, ans[i]);
		putchar('\n');
	}
	return 0;
}