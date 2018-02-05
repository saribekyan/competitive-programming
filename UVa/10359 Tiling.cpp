#include <stdio.h>
#include <string.h>
const int N = 260;
char a[N], b[N], ans[N+1][N], c;
void reverse(char *f, int n)
{
	int i;
	for (i = 0; i < n/2; i++)
	{
		c = f[i];
		f[i]=f[n-i-1];
		f[n-i-1]=c;
	}
}
void sum(char *f, char *s, int p)
{
	int n, m, i, k, d;
	strcpy(a, f);
	strcpy(b, s);
	n = strlen(a);
	m = strlen(b);
	reverse(a, n);
	reverse(b, m);
	if (n>m)for (i = m; i < n; i++)b[i]='0';
	else {for (i = n; i < m; i++)a[i]='0'; n=m;}
	a[n]=b[n]='\0';
	k = 0;
	for (i = 0; i < n; i++)
	{
		d = (a[i]-'0')+(b[i]-'0');
		ans[p][i]=(d+k)%10+'0';
		k = (d+k)/10;
	}
	if (k)ans[p][n++]=k+'0';
	ans[p][n]='\0';
	reverse(ans[p], n);
}

int main()
{
	int i, n;
	ans[0][0]='1';
	ans[1][0]='1';
	ans[0][1]=ans[1][1]='\0';
	for (i = 2; i <= N; i++)
	{
		sum(ans[i-1], ans[i-2], i);
		sum(ans[i], ans[i-2], i);
	}
	while (scanf("%d", &n)==1)printf("%s\n", ans[n]);
	return 0;
}