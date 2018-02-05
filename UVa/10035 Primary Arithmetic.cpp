#include <stdio.h>

int main()
{
	long long n,m,k,ans;
	while (scanf("%lld%lld",&n,&m))
	{
		if(n==0&&m==0)return 0;
		ans = k = 0;
		while (n||m)
		{
			if (n%10+m%10+k>9)
			{
				ans++;
				k = 1;
			}
			else k = 0;
			n /= 10;
			m /= 10;
		}
		if (ans)
			if (ans==1)printf("%lld carry operation.\n",ans);
			else printf("%lld carry operations.\n",ans);
		else printf("No carry operation.\n");
	}
}