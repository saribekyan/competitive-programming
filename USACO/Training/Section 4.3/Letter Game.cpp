/*
PROG: lgame
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int fc, ic, jc, kc, lc;
char str[8];
char dict[40001][8], *ans[40000], sa[16], sb[16];
int letter[26];
int value[26] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
struct word
{
	int value;
	char str[8];
	int letter[26];
} d[40000];
bool operator <(word a, word b){return a.value > b.value;}
bool cmp(char *a, char *b)
{
	ic = jc = 0;
	while (a[ic] != ' ' && a[ic])
		sa[ic] = a[ic++];
	while (b[jc] != ' ' && b[jc])
		sb[jc] = b[jc++];
	sa[ic] = sb[jc] = 0;
	fc = strcmp(sa, sb);
	if (fc < 0)return 1;
	if (fc > 0)return 0;
	kc = lc = 0;
	while (a[ic])
		sa[kc++] = a[ic++];
	while (b[jc])
		sb[lc++] = b[jc++];
	sa[kc] = sb[lc] = 0;
	if (strcmp(sa, sb) < 0)
		return 1;
	return 0;
}
FILE* fin = fopen("lgame.in", "r");
FILE* fout = fopen("lgame.out", "w");
FILE* fdict = fopen("lgame.dict", "r");
int main()
{
	int n, m, l, v, l1, l2, i, j;
	m = 0;
	fscanf(fin, "%s", str);
	while (fscanf(fdict, "%s", dict[m]) && dict[m][0] != '.')
		m++;
	l = strlen(str);
	for (i = 0; i < l; i++)
		letter[str[i]-'a']++;
	for (n = i = 0; i < m; i++)
	{
		l = strlen(dict[i]);
		memset(d[n].letter, 0, 104);
		for (j = 0; j < l; j++)
			d[n].letter[dict[i][j]-'a']++;
		for (j = 0; j < 26; j++)
			if (d[n].letter[j] > letter[j])
				break;
		if (j == 26)
		{
			for (d[n].value = j = 0; j < l; j++)
				d[n].value += value[dict[i][j]-'a'];
			strcpy(d[n].str, dict[i]);
			n++;
		}
	}
	sort(d, d+n);
	m = 0;
	v = d[0].value;
	while (d[m].value == v)
	{
		ans[m] = new char[16];
		strcpy(ans[m], d[m].str);
		m++;
	}
	v = d[0].value;
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
		{
			for (l = 0; l < 26; l++)
				if (d[i].letter[l]+d[j].letter[l] > letter[l])
					break;
			if (l == 26)
			{
				if (d[i].value+d[j].value > v)
				{
					m = 0;
					v = d[i].value+d[j].value;
				}
				if (d[i].value+d[j].value == v)
				{
					ans[m] = new char[16];
					if (strcmp(d[i].str, d[j].str) < 0)
					{
						strcpy(ans[m], d[i].str);
						l1 = strlen(ans[m]);
						l2 = strlen(d[j].str);
						ans[m][l1] = ' ';
						for (l = 0; l < l2; l++)
							ans[m][l1+l+1] = d[j].str[l];
						ans[m][l1+l2+1] = 0;
					}
					else
					{
						strcpy(ans[m], d[j].str);
						l1 = strlen(ans[m]);
						l2 = strlen(d[i].str);
						ans[m][l1] = ' ';
						for (l = 0; l < l2; l++)
							ans[m][l1+l+1] = d[i].str[l];
						ans[m][l1+l2+1] = 0;
					}
					m++;
				}
			}
		}
	fprintf(fout, "%d\n", v);
	sort(ans, ans+m, cmp);
	for (i = 0; i < m; i++)
		fprintf(fout, "%s\n", ans[i]);
	return 0;
}