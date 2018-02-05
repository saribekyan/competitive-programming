#include <stdio.h>

int a[5];
int main()
{
	int i, j;
	for (i = 0; i < 5; i++)
		scanf("%d", a+i);
	i = 0;
	while (1)
	{
		for (j = 0; j < 4; j++)
			if (a[j] > a[j+1])
				break;
		if (j == 4)
			break;
		if (i == 4)
			i = 0;
		if (a[i] > a[i+1])
		{
			a[i] ^= a[i+1];
			a[i+1] ^= a[i];
			a[i] ^= a[i+1];
			for (j = 0; j < 4; j++)
				printf("%d ", a[j]);
			printf("%d\n", a[j]);
		}
		i++;
	}
	return 0;
}
