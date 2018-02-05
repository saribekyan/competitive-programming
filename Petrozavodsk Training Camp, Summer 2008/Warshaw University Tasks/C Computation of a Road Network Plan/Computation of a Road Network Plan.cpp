#include <stdio.h>

int main()
{
	int n, d, i;
	scanf("%d%d", &n, &d);
	if (d == 0 || d == 1 && n > 2)
	{
		printf("NONE\n");
		return 0;
	}
	if (n == 2)
	{
		printf("1 2\n");
		return 0;
	}
	for (i = 1; i <= d; i++)
		printf("%d %d\n", i, i+1);
	i++;
	while (i <= n)
		printf("2 %d\n", i++);
	return 0;
}
