#include <stdio.h>
#include <string.h>
#define MAXL 100
#define MAX 200
char s1[MAX+1][MAXL],s2[MAX+1][MAXL];

int main()
{
	int t, n, i, j, k;
	scanf("%d",&t);
	while (t)
	{
		scanf("%d",&n);
		gets(s1[0]);
		for (i = n-1; i >= 0; i--)
			gets(s1[i]);
		for (i = n-1; i >= 0; i--)
			gets(s2[i]);
		k = 0;
		for (i = 0; i < n, k < n; i++)
			while (k < n && strcmp(s1[k],s2[i]))
				k++;
		i--;
		while (i < n)
			printf("%s\n",s2[i++]);
		putchar('\n');
		t--;
	}
	return 0;
}