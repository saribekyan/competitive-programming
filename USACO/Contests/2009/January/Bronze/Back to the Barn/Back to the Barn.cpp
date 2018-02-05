/*
PROG: backbarn
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

int n, m, num;
char s[10][10];
int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};
void count(int i, int j, int l)
{
	if (i == n-1 && j == m-1)
	{
		num++;
		return;
	}
	if (l == 0)
		return;
	int k, p, q;
	for (k = 0; k < 4; k++)
	{
		p = i+di[k];
		q = j+dj[k];
		if (p >= 0 && p < n && q >= 0 && q < m && s[p][q] == '.')
		{
			s[p][q] = '#';
			count(p, q, l-1);
			s[p][q] = '.';
		}
	}
}
int main()
{
	freopen("backbarn.in", "r", stdin);
	freopen("backbarn.out", "w", stdout);
	int l, i;
	scanf("%d%d%d", &n, &m, &l);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);
	s[0][0] = '#';
	count(0, 0, l-1);
	printf("%d\n", num);
	return 0;
}
