#include <stdio.h>
#include <string.h>
#define Max(a, b) ((a)>(b)?(a):(b))

char s[1010];
int d[1010][1010];
int main()
{
	int t, n, i, j, k;
	scanf("%d", &t);
	getchar();
	while (t)
	{
		gets(s);
		n = strlen(s);
		memset(d, 0, sizeof(d));
		for (i = 0; i < n; i++)
			d[i][i] = 1;
		for (k = 1; k < n; k++)
			for (i = 0; i < n-k; i++)
			{
				j = i+k;
				if (s[i] == s[j])
					d[i][j] = d[i+1][j-1]+2;
				else
					d[i][j] = Max(d[i][j-1], d[i+1][j]);
			}
		printf("%d\n", d[0][n-1]);
		t--;
	}
	return 0;
}
