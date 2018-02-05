#include <stdio.h>
#include <string.h>

char s[110], o[2];
int main()
{
	int n, m;
	scanf("%s", s);
	n = strlen(s);
	scanf("%s%s", o, s);
	m = strlen(s);
	if (n > m)
	{
		n ^= m;
		m ^= n;
		n ^= m;
	}
	if (o[0] == '+')
	{
		if (m == n)
		{
			putchar('2');
			while (--n)
				putchar('0');
		}
		else
		{
			putchar('1');
			while (--m != n)
				putchar('0');
			putchar('1');
			while (--n)
				putchar('0');
		}
	}
	else
	{
		putchar('1');
		while (--n+m-1)
			putchar('0');
	}
	putchar('\n');
	return 0;
}
