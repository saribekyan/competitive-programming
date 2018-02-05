/*
PROG: lexicon
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))

char s[1610];
int len[1010];
char w[1010][25];
int d[1610];
int t[30][1610];
int end(int k, int p)
{
	int i;
	for (i = 0; w[k][i] && t[w[k][i]-'a'][p] != -1; i++)
		p = t[w[k][i]-'a'][p]+1;
	if (w[k][i])
		return -1;
	return p-1;
}
int main()
{
	freopen("lexicon.in", "r", stdin);
	freopen("lexicon.out", "w", stdout);
	int n, l, m, i, j;
	scanf("%d%d%s", &n, &l, s);
	for (i = 0; i < n; i++)
	{
		scanf("%s", w[i]);
		len[i] = strlen(w[i]);
	}
	d[l] = 0;
	memset(t, -1, sizeof(t));
	for (i = 0; i < l; i++)
	{
		t[s[i]-'a'][i] = i;
		for (j = i-1; j >= 0 && s[j] != s[i]; j--)
			t[s[i]-'a'][j] = i;
	}
	for (i = l-1; i >= 0; i--)
	{
		d[i] = l-i;
		for (j = 0; j < n; j++)
		{
			m = end(j, i);
			if (m != -1)
				d[i] = Min(d[i], d[m+1]+m-i+1-len[j]);
		}
	}
	printf("%d\n", d[0]);
	return 0;
}
