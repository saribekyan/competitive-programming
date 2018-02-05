#include <stdio.h>
#include <string.h>

int d[100];
int m[5] = {1, 5, 10, 25, 50}, l=5;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, i, j;
	memset(d, 0, sizeof(d));
	d[0] = 1;
	for (i = 0; i < l; i++)
		for (j = 0; j < 100-m[i]; j++)
			d[j+m[i]] += d[j];
	while (scanf("%d", &n) == 1)
		if (d[n] == 1)
			printf("There is only 1 way to produce %d cents change.\n", n);
		else
			printf("There are %d ways to produce %d cents change.\n", d[n], n);
	return 0;
}
