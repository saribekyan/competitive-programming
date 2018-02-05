#include <stdio.h>

int d[100010];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, n, m, i, j;
	scanf("%d%d", &a, &b);
	n = b-a+1;
	for (i = 0; i < n; i++)
		scanf("%d", d+i);
	m = 0;
	for (i = 0; i < n; i++)
	{
		j = i+1;
		if (d[i] > d[j])
			while (j < n && d[j] < d[j-1])
				j++;
		else
			if (d[i] < d[j])
				while (j < n && d[j] > d[j-1])
					j++;
		i = j-1;
		m++;
	}
	printf("%d\n", m);
	return 0;
}
