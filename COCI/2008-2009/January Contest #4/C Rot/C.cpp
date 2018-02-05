#include <stdio.h>
#define Min(a, b) ((a)<(b)?(a):(b))

int n, m;
char s[15][15], d[15][15];
void rot90()
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			d[j][n-i-1] = s[i][j];
	n ^= m;
	m ^= n;
	n ^= m;
	for (i = 0; i < n; i++)
	{
		d[i][m] = 0;
		for (j = 0; j <= m; j++)
			s[i][j] = d[i][j];
	}
}
int main()
{
	int k, l, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);
	scanf("%d", &k);
	for (i = 0; i < k/90; i++)
		rot90();
	if (k%90 == 0)
		for (i = 0; i < n; i++)
			printf("%s\n", s[i]);
	else
	{
		j = 0;
		l = n-1;
		for (k = 0; k+1 < n+m; k++)
		{
			for (i = 0; i < l; i++)
				putchar(' ');
			if (k == n-1)
				j = 1;
			if (j == 0)
				l--;
			else
				l++;
			for (i = Min(n-1, k); i > 0 && k-i+1 < m; i--)
				printf("%c ", s[i][k-i]);
			printf("%c\n", s[i][k-i]);
		}
	}
	return 0;
}
