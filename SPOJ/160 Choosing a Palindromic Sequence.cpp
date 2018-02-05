#include <stdio.h>
#include <string.h>

int n;
int len[2][31];
char w[2][31][410];
int d[31][31][2][2][410];
int solve(int i, int j, int s, int l, int x, int P)
{
	int &it = d[i][j][s][l][x];
	if (it != -1)
		return it;
	int k;
	it = 0;
	if (i == j+1)
	{
		if (s == 0)
		{
			for (k = 0; k < x; k++)
				if (w[l][P][len[l][P]-k-1] != w[l][P][len[l][P]-x+k])
					return 0;
			return it = 1;
		}
		for (k = 0; k < x; k++)
			if (w[l][P][k] != w[l][P][x-k-1])
				return 0;
		return it = 1;
	}
	int t;
	if (s == 0)
		for (t = 0; t < 2; t++)
		{
			for (k = 0; k < x && k < len[t][j] && w[l][P][len[l][P]-x+k] == w[t][j][len[t][j]-k-1]; k++);
			if (k == x)
				it += solve(i, j-1, 1, t, len[t][j]-x, j);
			else
				if (k == len[t][j])
					it += solve(i, j-1, 0, l, x-len[t][j], P);
		}
	else
		for (t = 0; t < 2; t++)
		{
			for (k = 0; k < x && k < len[t][i] && w[l][P][x-k-1] == w[t][i][k]; k++);
			if (k == x)
				it += solve(i+1, j, 0, t, len[t][i]-x, i);
			else
				if (k == len[t][i])
					it += solve(i+1, j, 1, l, x-len[t][i], P);
		}
	return it;
}
int main()
{
	int t, l, i;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (l = 0; l < 2; l++)
			for (i = 0; i < n; i++)
			{
				scanf("%s", w[l][i]);
				len[l][i] = strlen(w[l][i]);
			}
		memset(d, -1, sizeof(d));
		printf("%d\n", solve(1, n-1, 0, 0, len[0][0], 0)+solve(1, n-1, 0, 1, len[1][0], 0));
	}
	return 0;
}
