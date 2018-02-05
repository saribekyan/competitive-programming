#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		if (n<0)
			if (n%2==0)printf("Underflow!");
			else printf("Overflow!");
		else
		if (n<8)printf("Underflow!");
		else if (n>13)printf("Overflow!");
		else if (n==8)printf("40320");
		else if (n==9)printf("362880");
		else if (n==10)printf("3628800");
		else if (n==11)printf("39916800");
		else if (n==12)printf("479001600");
		else if (n==13)printf("6227020800");
		putchar('\n');
	}
	return 0;
}