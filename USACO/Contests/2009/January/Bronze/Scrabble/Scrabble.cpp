/*
PROG: scrab
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>

char s[30], a[30];
int d[30], g[30];
int cost[30] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10, 0};
int main()
{
	FILE* dict = fopen("dict.txt", "r");
	freopen("scrab.in", "r", stdin);
	freopen("scrab.out", "w", stdout);
	char ch;
	int n, m, p, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		getchar();
		ch = getchar();
		if (ch == '#')
			d[26]++;
		else
			d[ch-'A']++;
	}
	m = 0;
	getc(dict);
	while (1)
	{
		fscanf(dict, "%s", a);
		if (feof(dict))
		{
			printf("%s\n", s);
			return 0;
		}
		memcpy(g, d, sizeof(d));
		for (p = i = 0; a[i]; i++)
			if (g[a[i]-'A'])
			{
				g[a[i]-'A']--;
				p += cost[a[i]-'A'];
			}
			else
				if (g[26])
					g[26]--;
				else
					break;
		if (a[i] == 0 && m < p)
		{
			strcpy(s, a);
			m = p;
		}
	}
	return 0;
}
