#include <stdio.h>
#define MAX 3600
int n;
int d[MAX];
void erat()
{
	int i, j, c;
	n = 0;
	d[n++]=2;
	for (i = 3; i<20000; i+=2)
	{
		c = 1;
		for (j = 0; j < n; j++)
			if (i%d[j]==0){c--;break;}
		if (c)d[n++]=i;
	}
}
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
	int num=0, i, ans;
	erat();
	while (scanf("%d", &num)&&num)
	{
		ans = 0;
		for (i = 0; d[i]<=num/2; i++)
			if (is_prime(num-d[i]))ans++;
		printf("%d\n", ans);
	}
	return 0;
}