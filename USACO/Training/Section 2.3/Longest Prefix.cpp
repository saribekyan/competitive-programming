/*
PROG: prefix
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <string.h>

int len[200];
bool d[200001];
char pr[201][10], s[200000], r[77];
FILE* fin = fopen("prefix.in", "r");
FILE* fout = fopen("prefix.out", "w");
int main()
{
	int n, m, i, j, l, k;
	n = 0;
	while (1)
	{
		fscanf(fin, "%s", pr[n]);
		if (pr[n][0] == '.')
			break;
		len[n] = strlen(pr[n]);
		n++;
	}
	m = 0;
	while (fscanf(fin, "%s", r) == 1)
	{
		l = strlen(r);
		for (i = 0; i < l; i++, m++)
			s[m] = r[i];
	}
	s[m] = 0;
	d[0] = 1;
	for (i = 1; i <= m; i++)
		for (j = 0; j < n; j++)
			if (i-len[j] >= 0)
				if (d[i-len[j]])
				{
					for (k = 0; k < len[j] && i+k <= m; k++)
						if (s[i-len[j]+k] != pr[j][k])
							break;
					if (k == len[j])
					{
						d[i] = 1;
						break;
					}
				}
	for (i = m; i >= 0; i--)
		if (d[i])
			break;
	fprintf(fout, "%d\n", i);
	return 0;
}