/*
PROG: jpol
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#define Max(a, b) ((a)>(b)?(a):(b))

short a[200];
short d[61][35010];
int main()
{
	freopen("jpol.in", "r", stdin);
	freopen("jpol.out", "w", stdout);
	int n, m, k, i, j;
	scanf("%d", &n);
	for (i = 0; i < 3*n; i++)
		scanf("%hd", a+i);
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; j < 3*n; j++)
			if (a[k] > a[j])
				k = j;
		printf("%d\n", k+1);
		a[k] = 1001;
	}
	memset(d, -1, sizeof(d));
	k = 1;
	m = 0;
	d[0][0] = 0;
	for (i = 0; i < 3*n; i++)
		if (a[i] == 1001)
			a[i] = -1;
	for (i = 0; i < 3*n; i++)
		if (a[i] != -1)
			for (j = m; j >= 0; j--)
				if (j+a[i] <= 500*n+1000)
					for (k = 0; k < n; k++)
						if (d[k][j] != -1 && d[k+1][j+a[i]] == -1)
						{
							d[k+1][j+a[i]] = i;
							m = Max(m, j+a[i]);
						}
	for (i = 500*n+1; d[n][i] == -1; i++);
	for (j = n; j > 0; j--)
	{
		printf("%hd\n", d[j][i]+1);
		k = a[d[j][i]];
		a[d[j][i]] = -1;
		i -= k;
	}
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 1; j < 3*n; j++)
			if (a[k] < a[j])
				k = j;
		printf("%d\n", k+1);
		a[k] = -1;
	}
	return 0;
}
