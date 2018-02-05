/*
PROG: jigsaw
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

bool f;
int n, m;
bool t[110];
int num[110];
char s[110][10];
int rot[12][12], p[12][12];
void go(int i, int j)
{
	if (j-1 == m && s[p[i][j-1]][rot[i][j-1]+2] != '0' || i == n && s[p[i][j-1]][rot[i][j-1]+3] != '0')
		return;
	if (j > m)
	{
		i++;
		j = 1;
	}
	if (i > n)
	{
		f = 1;
		return;
	}
	int l, r;
	for (l = 1; l <= n*m; l++)
		if (!t[l])
		{
			for (r = 0; r < 4; r++)
				if (s[l][r] == s[p[i][j-1]][rot[i][j-1]+2] && s[l][r+1] == s[p[i-1][j]][rot[i-1][j]+3])
				{
					t[l] = 1;
					p[i][j] = l;
					rot[i][j] = r;
					go(i, j+1);
					if (f)
						return;
					t[l] = 0;
				}
		}
}
int main()
{
	freopen("jigsaw.in", "r", stdin);
	freopen("jigsaw.out", "w", stdout);
	int i, j;
	scanf("%d%d", &n, &m);
	s[0][0] = s[0][1] = s[0][2] = s[0][3] = '0';
	s[0][4] = 0;
	for (i = 1; i <= n*m; i++)
	{
		scanf("%d%s%s%s%s", num+i, s[i], s[i]+1, s[i]+2, s[i]+3);
		s[i][4] = s[i][0];
		s[i][5] = s[i][1];
		s[i][6] = s[i][2];
		s[i][7] = 0;
	}
	for (i = 0; i <= m; i++)
		rot[0][i] = p[0][i] = 0;
	for (i = 0; i <= n; i++)
		rot[i][0] = p[i][0] = 0;
	go(1, 1);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			printf("%d %c %c %c %c\n", num[p[i][j]], s[p[i][j]][rot[i][j]+1], s[p[i][j]][rot[i][j]+2], s[p[i][j]][rot[i][j]+3], s[p[i][j]][rot[i][j]]);
	return 0;
}
