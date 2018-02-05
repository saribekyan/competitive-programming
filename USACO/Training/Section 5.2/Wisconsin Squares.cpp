/*
PROG: wissqu
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
int number;
int herds[5];
char s[4][5];
bool t[4][4];
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
struct order
{
	int row;
	int column;
	char herd;
} r[16];
bool check(int p, int q)
{
	int i;
	for (i = 0; i < 8; i++)
		if (p+di[i] >= 0 && p+di[i] < 5 && q+dj[i] >= 0 && q+dj[i] < 5)
			if (s[p+di[i]][q+dj[i]] == s[p][q])
				return 0;
	return 1;
}
FILE* fin = fopen("wissqu.in", "r");
FILE* fout = fopen("wissqu.out", "w");
void rec(int l)
{
	int i, j, k;
	if (l == 16)
	{
		number++;
		if (number == 1)
			for (i = 0; i < 16; i++)
				fprintf(fout, "%c %d %d\n", r[i].herd, r[i].row+1, r[i].column+1);
		return;
	}
	char ch;
	for (k = 0; k < 5; k++)
		if (herds[k])
		{
			herds[k]--;
			r[l].herd = k+'A';
			for (i = 0; i < 4; i++)
				for (j = 0; j < 4; j++)
					if (!t[i][j] && s[i][j] != k+'A')
					{
						ch = s[i][j];
						s[i][j] = k+'A';
						if (check(i, j))
						{
							r[l].row = i;
							r[l].column = j;
							t[i][j] = 1;
							rec(l+1);
							t[i][j] = 0;
						}
						s[i][j] = ch;
					}
			herds[k]++;
		}
}
int main()
{
	char ch;
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			fscanf(fin, "%c", s[i]+j);
			herds[s[i][j]-'A']++;
		}
		fgetc(fin);
	}
	herds[2]--;
	r[0].herd = 'D';
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (s[i][j] != 'D')
			{
				ch = s[i][j];
				s[i][j] = 'D';
				if (check(i, j))
				{
					t[i][j] = 1;
					r[0].row = i;
					r[0].column = j;
					rec(1);
					t[i][j] = 0;
				}
				s[i][j] = ch;
			}
	fprintf(fout, "%d\n", number);
	return 0;
}