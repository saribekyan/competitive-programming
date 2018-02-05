#include <stdio.h>
#include <string.h>

int n;
int two[1030];
int d[1030][1030];
void add(int p, int q, int a)
{
	int i, j;
	for (i = p; i <= n; i+=two[i])
		for (j = q; j <= n; j+=two[j])
			d[i][j] += a;
}
int sum(int p, int q)
{
	int s=0, i, j;
	for (i = p; i > 0; i-=two[i])
		for (j = q; j > 0; j-=two[j])
			s += d[i][j];
	return s;
}
int main()
{
	char s[5];
	int t, i, j, p, q;
	scanf("%d", &t);
	while (t)
	{
		scanf("%d", &n);
		memset(d, 0, sizeof(d));
		for (i = 1; i <= n; i++)
			for (two[i] = 1; (i|two[i]) != i; two[i] <<= 1);
		while (1)
		{
			scanf("%s", s);
			if (s[1] == 'N')
				break;
			scanf("%d%d%d", &i, &j, &p);
			if (s[1] == 'E')
				add(i+1, j+1, p-sum(i+1,j+1)+sum(i,j+1)+sum(i+1,j)-sum(i,j));
			else
			{
				scanf("%d", &q);
				printf("%d\n", sum(p+1, q+1)-sum(p+1, j)-sum(i, q+1)+sum(i, j));
			}
		}
		t--;
		if (t)
			putchar('\n');
	}
	return 0;
}
