#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

int main()
{
	char s[20];
	int t=1, n, m, l, i, j;
	while (scanf("%s", s) == 1)
	{
		n = strlen(s);
		l = 2*n;
		m = n;
		for (i = 0; i < n; i++)
		{
			for (j = 1; j <= i && i+j < n && s[i-j] == s[i+j]; j++);
			if (m > n-2*(j-1)-1)
			{
				m = n-2*(j-1)-1;
				l = 0;
			}
			if (m == n-2*(j-1)-1)
				l = Max(l, 2*Max(i+1, n-i)-1);
		}
		for (i = 0; i < n-1; i++)
		{
			for (j = 0; j <= i && i+j < n && s[i-j] == s[i+j+1]; j++);
			if (m > n-2*j)
			{
				m = n-2*j;
				l = 0;
			}
			if (m == n-2*j)
				l = Max(l, 2*Max(i+1, n-i-1));
		}
		printf("Case %d, sequence = %s, cost = %d, length = %d\n", t++, s, m, l);
	}
	return 0;
}
