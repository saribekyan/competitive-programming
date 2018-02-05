#include <stdio.h>
#include <string.h>
#define MAX 2500
char c[MAX];
int d[83];
bool is_prime(int n)
{
	if (n==2)return 1;
	if (n==1||n%2==0)return 0;
	int i;
	for (i = 3; i*i <= n; i+=2)
		if (n%i==0)return 0;
	return 1;
}
int main()
{
	int t, l, n, i;
	scanf("%d", &t);
	for (l = 0; l < t; l++)
	{
		scanf("%s", c);
		n = strlen(c);
		for (i = 0; i < 83; i++)d[i]=0;
		for (i = 0; i < n; i++)
		{
			if (c[i]>='0'&&c[i]<='9')d[c[i]-'0']++;
			if (c[i]>='A'&&c[i]<='Z')d[c[i]-'A'+10]++;
			if (c[i]>='a'&&c[i]<='z')d[c[i]-'a'+37]++;
		}
		printf("Case %d: ", l+1);
		n = 1;
		for (i = 0; i < 83; i++)
			if (is_prime(d[i]))
			{
				n = 0;
				if (i>=0&&i<=9)printf("%d", i);
				if (i>=10&&i<=36)printf("%c", i-10+'A');
				if (i>=37&&i<=82)printf("%c", i-37+'a');
			}
		if (n)printf("empty");
		putchar('\n');
	}
	return 0;
}