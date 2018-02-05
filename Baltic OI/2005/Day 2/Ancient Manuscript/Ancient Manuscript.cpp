#include <stdio.h>
#include <string.h>

char s[20];
int vow[27];
int c[2], e[2];
long long d[20][2][5][5][27];
int main()
{
	freopen("ancient.in", "r", stdin);
	freopen("ancient.out", "w", stdout);
	long long ans;
	int n, v, i, j, k, l, r;
	scanf("%d%d%d%d%s", e+1, c+1, e, c, s);
	vow['a'-'a'] = vow['e'-'a'] = vow['i'-'a'] = vow['o'-'a'] = vow['u'-'a'] = 1;
	n = strlen(s);
	if (s[0] != '*')
		d[0][vow[s[0]-'a']][1][1][s[0]-'a'] = 1;
	else
		for (i = 0; i < 26; i++)
			d[0][vow[i]][1][1][i] = 1;
	for (i = 0; i+1 < n; i++)
		for (v = 0; v < 2; v++)
			for (j = 1; j <= c[v]; j++)
				for (k = 1; k <= j && k <= e[v]; k++)
					for (l = 0; l < 26; l++)
						if (vow[l] == v && d[i][v][j][k][l])
						{
							if (s[i+1] != '*')
								if (vow[s[i+1]-'a'] == v)
								{
									if (j < c[v])
									{
										if (s[i+1] == l+'a' && k < e[v])
											d[i+1][v][j+1][k+1][s[i+1]-'a'] += d[i][v][j][k][l];
										if (s[i+1] != l+'a')
											d[i+1][v][j+1][1][s[i+1]-'a'] += d[i][v][j][k][l];
									}
								}
								else
									d[i+1][v^1][1][1][s[i+1]-'a'] += d[i][v][j][k][l];
							else
								for (r = 0; r < 26; r++)
									if (vow[r] == v)
									{
										if (j < c[v])
										{
											if (r == l && k < e[v])
												d[i+1][v][j+1][k+1][r] += d[i][v][j][k][l];
											if (r != l)
												d[i+1][v][j+1][1][r] += d[i][v][j][k][l];
										}
									}
									else
										d[i+1][v^1][1][1][r] += d[i][v][j][k][l];
						}
	ans = 0;
	for (v = 0; v < 2; v++)
		for (i = 1; i <= c[v]; i++)
			for (j = 1; j <= e[v]; j++)
				for (l = 0; l < 26; l++)
					if (vow[l] == v)
						ans += d[n-1][v][i][j][l];
	printf("%lld\n", ans);
	return 0;
}
