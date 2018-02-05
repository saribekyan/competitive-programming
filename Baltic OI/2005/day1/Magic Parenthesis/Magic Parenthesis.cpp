#include <stdio.h>
#include <string.h>

char s[80];
int main()
{
	freopen("lisp.in", "r", stdin);
	freopen("lisp.out", "w", stdout);
	int n, m, p, c, i, j;
	scanf("%d%d", &n, &m);
	for (c = i = 0; i < n; i+=72)
	{
		scanf("%s", s);
		p = strlen(s);
		for (j = 0; j < p; j++)
		{
			if (s[j] == '(')
				c++;
			if (s[j] == ')')
				c--;
			if (s[j] == ']')
				c--;
			if (c < 0)
			{
				printf("0\n");
				return 0;
			}
		}
	}
	for (i = 0; i < m; i++)
		printf("1\n");
	printf("%d\n", c+1);
	return 0;
}
