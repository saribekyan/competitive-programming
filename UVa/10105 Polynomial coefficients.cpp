#include <stdio.h>
const int N = 13;
int d[N];
unsigned long long C(int n, int k)
{
	int i;
	unsigned long long f1, f2, f3;
	f1=f2=f3=1;
	for (i = 1; i <= n; i++)f1*=i;
	for (i = 1; i <= k; i++)f2*=i;
	for (i = 1; i <= n-k; i++)f3*=i;
	return f1/f2/f3;
}
int main()
{
	int n, k, i, j, c, a, b;
	while (scanf("%d%d", &n, &k)==2)
	{
		for (i = 0; i < k; i++)scanf("%d", &d[i]);
		c = 1;
		a = n;
		b = n-d[k-1];
		for (i = k-1; i >= 0; i--)
		{
			c*=C(a, b);
			a-=d[i];
			b-=d[i-1];
		}
		printf("%d\n", c);
	}
	return 0;
}