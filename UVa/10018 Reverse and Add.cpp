#include <stdio.h>

long long reverse(long long n)
{
	long long m=0;
	while (n)
	{
		m=m*10+n%10;
		n/=10;
	}
	return m;
}

int main()
{
	int t,ans;
	long long n,m;
	scanf("%d",&t);
	while (1)
	{
		scanf("%lld",&n);
		ans = 0;
		while (1)
		{
			m = reverse(n);
			if (m!=n)n+=reverse(n);
			else break;
			ans++;
		}
		printf("%d %lld\n",ans, n);
		t--;
		if (t==0)return 0;
	}
}
