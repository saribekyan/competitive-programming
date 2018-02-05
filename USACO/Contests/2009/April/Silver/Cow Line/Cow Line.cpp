/*
PROG: cline
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int d[300010];
int main()
{
	freopen("cline.in", "r", stdin);
	freopen("cline.out", "w", stdout);
	int n, p, q, k, i = 1;
	scanf("%d", &n);
	p = q = n;
	while (n--)
	{
		getchar();
		if (getchar() == 'A')
		{
			getchar();
			if (getchar() == 'L')
				d[--p] = i++;
			else
				d[q++] = i++;
		}
		else
		{
			getchar();
			if (getchar() == 'L')
			{
				scanf("%d", &k);
				p += k;
			}
			else
			{
				scanf("%d", &k);
				q -= k;
			}
		}
	}
	for (i = p; i < q; i++)
		printf("%d\n", d[i]);
	return 0;
}
