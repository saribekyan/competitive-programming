/*
PROG: frameup
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int len;
int num;
int n, m;
bool t[26];
char* ans[10000];
char s[30][31], r[27];
struct frame
{
	int i1, j1;
	int i2, j2;
	char letter;
} frames[26];
bool cmp(char *a, char *b)
{
	if (strcmp(a, b) < 0)
		return 1;
	return 0;
}
void rec(int l)
{
	if (l == num)
	{
		ans[len] = new char[27];
		strcpy(ans[len], r);
		r[l] = 0;
		reverse(ans[len], ans[len]+l);
		len++;
		return;
	}
	int i, j;
	char h[30][31];
	for (i = 0; i < n; i++)
		strcpy(h[i], s[i]);
	for (i = 0; i < num; i++)
		if (!t[i])
		{
			for (j = frames[i].j1; j <= frames[i].j2; j++)
				if (s[frames[i].i1][j] != '?' && s[frames[i].i1][j] != frames[i].letter ||
					s[frames[i].i2][j] != '?' && s[frames[i].i2][j] != frames[i].letter)
					break;
			if (j != frames[i].j2+1)
				continue;
			for (j = frames[i].i1; j <= frames[i].i2; j++)
				if (s[j][frames[i].j1] != '?' && s[j][frames[i].j1] != frames[i].letter ||
					s[j][frames[i].j2] != '?' && s[j][frames[i].j2] != frames[i].letter)
					break;
			if (j == frames[i].i2+1)
			{
				for (j = frames[i].j1; j <= frames[i].j2; j++)
					s[frames[i].i1][j] = s[frames[i].i2][j] = '?';
				for (j = frames[i].i1; j <= frames[i].i2; j++)
					s[j][frames[i].j1] = s[j][frames[i].j2] = '?';
				r[l] = frames[i].letter;
				t[i] = 1;
				rec(l+1);
				t[i] = 0;
				for (j = 0; j < n; j++)
					strcpy(s[j], h[j]);
			}
		}
}
FILE* fin = fopen("frameup.in", "r");
FILE* fout = fopen("frameup.out", "w");
int main()
{
	int i, j, k;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
		fscanf(fin, "%s", s[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (s[i][j] != '.')
			{
				for (k = 0; k < num; k++)
					if (frames[k].letter == s[i][j])
						break;
				if (k == num)
					frames[num++].letter = s[i][j];
			}
	for (k = 0; k < num; k++)
	{
		frames[k].i1 = frames[k].j1 = 31;
		frames[k].i2 = frames[k].j2 = -1;
	}
	for (k = 0; k < num; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (s[i][j] == frames[k].letter)
				{
					if (frames[k].i1 > i)
						frames[k].i1 = i;
					if (frames[k].j1 > j)
						frames[k].j1 = j;
					if (frames[k].i2 < i)
						frames[k].i2 = i;
					if (frames[k].j2 < j)
						frames[k].j2 = j;
				}
	rec(0);
	sort(ans, ans+len, cmp);
	for (i = 0; i < len; i++)
		fprintf(fout, "%s\n", ans[i]);
	return 0;
}