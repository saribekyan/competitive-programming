/*
PROG: coggle
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>

int n;
bool f;
char s[25];
char b[6][6];
bool t[6][5];
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void rec(int p, int q, int k)
{
	if (k == n)
	{
		f = 1;
		return;
	}
	int i, u, v;
	for (i = 0; i < 8; i++)
	{
		u = p+di[i];
		v = q+dj[i];
		if (u >= 0 && u < 5 && v >= 0 && v < 5 && b[u][v] == s[k] && !t[u][v])
		{
			t[u][v] = 1;
			rec(u, v, k+1);
			if (f)
				return;
			t[u][v] = 0;
		}
	}
}
int main()
{
	freopen("coggle.in", "r", stdin);
	freopen("coggle.out", "w", stdout);
	FILE* dict = fopen("dict.txt", "r");
	int m=0, i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
		{
			b[i][j] = getchar();
			if (i+j != 8)
				getchar();
		}
	while (fscanf(dict, "%s", s) == 1)
	{
		n = strlen(s);
		for (i = 0; i < 5; i++)
			for (j = 0; j < 5; j++)
				if (b[i][j] == s[0])
				{
					f = 0;
					memset(t, 0, sizeof(t));
					t[i][j] = 1;
					rec(i, j, 1);
					if (f)
					{
						m++;
						goto there;
					}
				}
there:;
	}
	printf("%d\n", m);
	return 0;
}
