#include <stdio.h>
#define Max(a, b) ((a)>(b)?(a):(b))

short n, m;
char s[1010][1010];
int d[2][1010][1010];
short di[4] = {-1, 0, 0, 1};
short dj[4] = {0, -1, 1, 0};
void solve(short i, short j)
{
	int &a = d[0][i][j];
	if (a != -1)
		return;
	short p, q, k;
	int &b = d[1][i][j], x, y;
	x = y = -1;
	for (k = 0; k < 4; k++)
	{
		p = i+di[k];
		q = j+dj[k];
		if (p >= 0 && p < n && q >= 0 && q < m && s[p][q] == '.')
		{
			s[p][q] = '*';
			solve(p, q);
			a = Max(a, d[0][p][q]);
			if (x < d[1][p][q])
			{
				y = x;
				x = d[1][p][q];
			}
			else
				y = Max(y, d[1][p][q]);
		}
	}
	if (a == -1)
	{
		a = b = 0;
		return;
	}
	b = x+1;
	a = Max(a, x+y+2);
}
int main()
{
	short t, i, j;
	scanf("%hd", &t);
	while (t)
	{
		scanf("%hd%hd", &m, &n);
		for (i = 0; i < n; i++)
			scanf("%s", s[i]);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				d[0][i][j] = d[1][i][j] = -1;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (s[i][j] == '.')
				{
					s[i][j] = '*';
					solve(i, j);
					printf("Maximum rope length is %d.\n", d[0][i][j]);
					i = n;
					break;
				}
		if (j == m)
			printf("Maximum rope length is 0.\n");
		t--;
	}
	return 0;
}
