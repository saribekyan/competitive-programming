#include <stdio.h>
#include <string.h>
char a[100][31], b[100][31], s[5000];
int d[101][101], p[101][101], pr[101];
int main()
{
	int n, m, i, j, k;
	while (1)
	{
		n = m = 0;
		while (gets(s) && s[0] != '#' && !feof(stdin))
		{
			i = 0;
			while (1)
			{
				j = 0;
				while (s[i++] == ' ');
				i--;
				while (s[i] != ' ' && s[i])
					a[n][j++] = s[i++];
				a[n++][j] = 0;
				if (!s[i])
					break;
			}
		}
		if (feof(stdin))break;
		while (scanf("%s", s) && s[0] != '#')
		{
			i = 0;
			while (1)
			{
				j = 0;
				while (s[i++] == ' ');
				i--;
				while (s[i] != ' ' && s[i])
					b[m][j++] = s[i++];
				b[m++][j] = 0;
				if (!s[i])
					break;
			}
		}
		for (i = 0; i < n; i++)
			d[i][0] = 0;
		for (i = 0; i < m; i++)
			d[0][i] = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
				if (strcmp(a[i-1], b[j-1]) == 0)
				{
					p[i][j] = 0;
					d[i][j] = d[i-1][j-1]+1;
				}
				else
					if (d[i][j-1] > d[i-1][j])
					{
						p[i][j] = 1;
						d[i][j] = d[i][j-1];
					}
					else
					{
						p[i][j] = -1;
						d[i][j] = d[i-1][j];
					}
			}
		i = n;
		j = m;
		k = d[n][m]-1;
		while (k != -1)
		{
			if (p[i][j] == 0)
			{
				pr[k] = i-1;
				i--;
				j--;
				k--;
			}
			if (p[i][j] == 1)
				j--;
			if (p[i][j] == -1)
				i--;
		}
		for (i = 0; i < d[n][m]-1; i++)
			printf("%s ", a[pr[i]]);
		if (d[n][m])
			printf("%s\n", a[pr[i]]);
	}
	return 0;
}