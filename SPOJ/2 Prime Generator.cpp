#include <stdio.h>
#include <string.h>

int p[3000];
bool pr[100010];
int main()
{
	int t, l=0, k, n, m, i, j;
	pr[0] = pr[1] = p[2] = 0;
	for (i = 3; i < 32000; i+=2)
		pr[i] = 1;
	l = 1;
	p[0] = 2;
	for (i = 3; i < 32000; i+=2)
		if (pr[i])
		{
			p[l++] = i;
			for (j = 2*i; j < 32000; j+=i)
				pr[j] = 0;
		}
	scanf("%d", &t);
	while (t)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i <= m-n; i++)
			pr[i] = 1;
		if (n == 1)
			pr[0] = 0;
		for (i = 0; i < l && p[i]*p[i] <= m; i++)
		{
			if (n%p[i] == 0)
				j = 0;
			else
				j = p[i]-n%p[i];
			k = m-n-m%p[i]+1;
			for (; j <= k; j+=p[i])
				if (n+j != p[i])
					pr[j] = 0;
		}
		for (i = 0; i <= m-n; i++)
			if (pr[i])
				printf("%d\n", n+i);
		t--;
		if (t)
			putchar('\n');
	}
	return 0;
}
