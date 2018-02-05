#include <cstdio>
#include <algorithm>
using namespace std;

int len[10010];
short d[1010];
short p[1010];
short wi[1010];
short sc[1010][26];
short sw[10010][26];
char s[1010];
char w[10010][110];
char ans[1010][110];
int main()
{
	int t, m, n, i, j, k;
	scanf("%d", &t);
	p[0] = -1;
	while (t)
	{
		memset(s, 0, sizeof(s));
		memset(w, 0, sizeof(w));
		memset(d, 0, sizeof(d));
		memset(sc, 0, sizeof(sc));
		memset(sw, 0, sizeof(sw));
		scanf("%s%d", s+1, &n);
		s[0] = '#';
		for (i = 0; i < n; i++)
		{
			scanf("%s", w[i]);
			len[i] = strlen(w[i]);
			for (j = 0; j < len[i]; j++)
				sw[i][w[i][j]-'a']++;
		}
		m = strlen(s);
		for (i = 1; i < m; i++)
		{
			for (j = 0; j < 26; j++)
				sc[i][j] = sc[i-1][j];
			sc[i][s[i]-'a']++;
		}
		d[0] = 1;
		for (i = 1; i < m; i++)
			for (j = 0; j < n; j++)		
				if (len[j] <= i)
				{
					if (s[i] != w[j][len[j]-1] || s[i-len[j]+1] != w[j][0])
						continue;
					for (k = 0; k < 26 && sc[i][k]-sc[i-len[j]][k] == sw[j][k]; k++);
					if (k == 26)
					{
						d[i] += d[i-len[j]];
						if (d[i] > 2)
							d[i] = 2;
						if (d[i-len[j]])
						{
							p[i] = i-len[j];
							wi[i] = j;
						}
					}
				}
		if (d[m-1] == 0)
		{
			printf("impossible\n");
			t--;
			continue;
		}
		if (d[m-1] > 1)
		{
			printf("ambiguous\n");
			t--;
			continue;
		}
		k = 0;
		for (i = m-1; p[i] != -1; i = p[i])
			strcpy(ans[k++], w[wi[i]]);
		printf("%s", ans[--k]);
		while (k--)
			printf(" %s", ans[k]);
		putchar('\n');
		t--;
	}
	return 0;
}
