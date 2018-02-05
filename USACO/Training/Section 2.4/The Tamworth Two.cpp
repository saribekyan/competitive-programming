/*
PROG: ttwo
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

char s[10][11];
struct P{int i, j, h;}f, c;
FILE* fin = fopen("ttwo.in", "r");
FILE* fout = fopen("ttwo.out", "w");
int main()
{
	int i, j;
	for (i = 0; i < 10; i++)
		fscanf(fin, "%s", s[i]);
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			if (s[i][j] == 'F')
			{
				f.i = i;
				f.j = j;
				f.h = 0;
				s[i][j] = '.';
			}
			if (s[i][j] == 'C')
			{
				c.i = i;
				c.j = j;
				c.h = 0;
				s[i][j] = '.';
			}
		}
	i = 1;
	while (i < 401)
	{
//		Cows
		if (c.h == 0)
			if (c.i > 0 && s[c.i-1][c.j] == '.')
				c.i--;
			else
				c.h = 1;
		else
			if (c.h == 1)
				if (c.j < 9 && s[c.i][c.j+1] == '.')
					c.j++;
				else
					c.h = 2;
			else
				if (c.h == 2)
					if (c.i < 9 && s[c.i+1][c.j] == '.')
						c.i++;
					else
						c.h = 3;
				else
					if (c.j > 0 && s[c.i][c.j-1] == '.')
						c.j--;
					else
						c.h = 0;
//		Farmer John
		if (f.h == 0)
			if (f.i > 0 && s[f.i-1][f.j] == '.')
				f.i--;
			else
				f.h = 1;
		else
			if (f.h == 1)
				if (f.j < 9 && s[f.i][f.j+1] == '.')
					f.j++;
				else
					f.h = 2;
			else
				if (f.h == 2)
					if (f.i < 9 && s[f.i+1][f.j] == '.')
						f.i++;
					else
						f.h = 3;
				else
					if (f.j > 0 && s[f.i][f.j-1] == '.')
						f.j--;
					else
						f.h = 0;
////////////////////////////////////////////////////////
		if (c.i == f.i && c.j == f.j)break;
		i++;
	}
	if (i == 401)
		fprintf(fout, "0\n");
	else
		fprintf(fout, "%d\n", i);
	return 0;
}