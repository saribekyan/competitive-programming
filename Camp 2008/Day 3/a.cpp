#include <stdio.h>
#include <string.h>

int ten[10];
char s[20];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, l, d, i, j;
	s[0] = '.';
	scanf("%s", s+1);
	ten[0] = 1;
	for (i = 1; i < 10; i++)
		ten[i] = ten[i-1]*10;
	l = strlen(s)-1;
	m = 0;
	for (i = 1; i <= l; i++)
		for (j = 1; j <= i; j++)
			for (d = (j==1); d < s[j]-'0'+(j == i); d++)
				m += ten[i-j];
	printf("%d\n", m);
	return 0;
}

