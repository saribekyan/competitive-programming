#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))

char s[6110];
short d[2][6110];
int main()
{
	short t, sw, n, i, j;
	scanf("%hd", &t);
	while (t)
	{
		scanf("%s", s);
		n = strlen(s);
		sw = 0;
		for (i = n-1; i >= 0; i--)
		{
			d[sw][i] = 0;
			if (i)
				d[sw][i-1] = 0;
			for (j = i+1; j < n; j++)
				if (s[i] == s[j])
					d[sw][j] = d[1-sw][j-1];
				else
					d[sw][j] = Min(d[1-sw][j], d[sw][j-1])+1;
			sw = 1-sw;
		}
		printf("%d\n", d[1-sw][n-1]);
		t--;
	}
	return 0;
}
