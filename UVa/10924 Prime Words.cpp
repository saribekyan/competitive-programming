#include <stdio.h>
#include <string.h>
#define MAX 20

bool is_prime(int n)
{
	int i;
	if (n==2)
		return true;
	if (n%2==0)
		return false;
	for (i = 3; i*i<=n; i+=2)
		if (n%i==0)
			return false;
	return true;
}

char c[MAX];

int main()
{
	int i, s;
	for (i = 0; i < MAX; i++)
		c[i] = '\0';
	while (scanf("%s", c)==1)
	{
		s = 0;
		for (i = 0; i < strlen(c); i++)
			if (c[i]>='a'&&c[i]<='z')
				s += c[i]-'a'+1;
			else
				s += c[i]-'A'+27;
		if (is_prime(s))
			printf("It is a prime word.\n");
		else
			printf("It is not a prime word.\n");
		for (i = 0; i < MAX; i++)
			c[i] = '\0';
	}
	return 0;
}