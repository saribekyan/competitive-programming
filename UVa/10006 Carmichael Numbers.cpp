#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d",&n) && n)
		if (n==561 || n==1105 || n==1729 ||	n==2465 ||
			n==2821 || n==6601 || n==8911 || n==10585 ||
			n==15841 ||	n==29341 || n==41041 || n==46657 ||
			n==52633 ||	n==62745 || n==63973)
			printf("The number %d is a Carmichael number.\n", n);
		else printf("%d is normal.\n",n);
	return 0;
}
/*
#include <stdio.h>

int prime(int n)
{
	int i;
	if (n==2)return 1;
	if (n%2==0)return 0;	
	for (i = 3; i*i <= n; i+=2)
		if (n%i==0)return 0;
	return 1;
}

int carmichael(int n)
{
	int m, i;
	if (prime(n))return 0;
	if (n%2==0 || n%4==0)return 0;	
	m=n;
	while (m%2==0)m/=2;
	for (i = 3; i*i <= m; i+=2)
	{
		if (m%i==0)
			if ((n-1)%(i-1) || n%(i*i)==0)
				return 0;
		while (m%i==0)
			m/=i;
	}
	if (m!=1)
		if ((n-1)%(m-1) || n%(m*m)==0)return 0;
	return 1;
}

int main()
{
	int n;
	while (scanf("%d",&n) && n)
		if (carmichael(n))
			printf("The number %d is a Carmichael number.\n", n);
		else printf("%d is normal.\n",n);
	return 0;
}*/
