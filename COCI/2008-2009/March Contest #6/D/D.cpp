#include <stdio.h>

int ans[10010], l;
int d[3][10010], m[3];
int main()
{
	int n, a, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		d[a%3][m[a%3]++] = a;
	}
	if (m[0] > (n+1)/2 || m[0] == 0 && m[1] > 0 && m[2] > 0)
	{
		printf("impossible\n");
		return 0;
	}
	if (m[0] == 0)
		for (i = 1; i <= 2; i++)
			while (m[i])
				ans[l++] = d[i][--m[i]];
	else
	{
		while (m[0] > 1)
		{
			ans[l++] = d[0][--m[0]];
			if (m[1])
				ans[l++] = d[1][--m[1]];
			else
				ans[l++] = d[2][--m[2]];
		}
		if (m[1] == 0 || m[2] == 0)
			ans[l++] = d[0][--m[0]];
		if (m[1] == 0)
			while (m[2])
				ans[l++] = d[2][--m[2]];
		else
			if (m[2] == 0)
				while (m[1])
					ans[l++] = d[1][--m[1]];
			else
			{
				if (l == 0)
				{
					while (m[1])
						ans[l++] = d[1][--m[1]];
					ans[l++] = d[0][--m[0]];
					while (m[2])
						ans[l++] = d[2][--m[2]];
				}
				else
					if (ans[l-1]%3 == 1)
					{
						while (m[1])
							ans[l++] = d[1][--m[1]];
						ans[l++] = d[0][--m[0]];
						while (m[2])
							ans[l++] = d[2][--m[2]];
					}
					else
					{
						while (m[2])
							ans[l++] = d[2][--m[2]];
						ans[l++] = d[0][--m[0]];
						while (m[1])
							ans[l++] = d[1][--m[1]];
					}
			}
	}
	printf("%d", ans[0]);
	for (i = 1; i < l; i++)
		printf(" %d", ans[i]);
	putchar('\n');
	return 0;
}
