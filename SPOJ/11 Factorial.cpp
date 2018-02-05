#include <stdio.h>

int d[13];
int main()
{
	int t, n, m, i;
	scanf("%d", &t);
	d[0] = 5;
	for (i = 1; i <= 12; i++)
		d[i] = d[i-1]*5;
	while (t)
	{
		scanf("%d", &n);
		for (m = i = 0; d[i] <= n; i++)
			m += n/d[i];
		printf("%d\n", m);
		t--;
	}
	return 0;
}
