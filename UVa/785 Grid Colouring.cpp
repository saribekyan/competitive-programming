#include <stdio.h>
#include <string.h>
#define RMAX 35
#define CMAX 85
int dx[4] = {-1,  0, 0, 1};
int dy[4] = { 0, -1, 1, 0};
char c[RMAX][CMAX], q;
void rec(int x, int y)
{
	int i;
	for (i = 0; i < 4; i++)
		if (c[x+dx[i]][y+dy[i]]==' ')
		{
			c[x+dx[i]][y+dy[i]] = q;
			rec(x+dx[i], y+dy[i]);
		}
}
int main()
{
	bool f;
	int i, j, n;
	while (1)
	{
		for (i = 0; i < RMAX; i++)
			for (j = 0; j < CMAX; j++)
				c[i][j] = '\0';
		n = 0;
		while (gets(c[n]))
		{
			f = true;
			for (i = 0; i < strlen(c[n]); i++)
				if (c[n][i]!='_')
				{
					f = false;
					break;
				}
			n++;
			if (f)
				break;
		}
		if (feof(stdin))
			break;
		n--;
		for (i = 0; i < n; i++)
		{
			j = 0;
			while (c[i][j]!='\0')
			{
				if (c[i][j]!='X'&&c[i][j]!=' ')
				{
					q = c[i][j];
					rec(i, j);
				}
				j++;
			}
		}
		for (i = 0; i <= n; i++)
			printf("%s\n", c[i]);
	}
	return 0;
}