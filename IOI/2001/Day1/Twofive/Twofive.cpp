#include <stdio.h>
#include <string.h>

int t[26];
int mc[5], mr[5];
int dp[6][6][6][6][6];
int solve(int a, int b, int c, int d, int e)
{
	int &it = dp[a][b][c][d][e];
	if (it != -1)
		return it;
	if (e == 5)
		return it = 1;
	int l = a+b+c+d+e+1, i;
	for (i = 0; i < 25; i++)
		l -= t[i];
	for (i = 0; i < 25 && l; i++)
		l -= 1-t[i];
	i--;
	it = 0;
	if (a < 5 && i > mr[0] && i > mc[a])
		it += solve(a+1, b, c, d, e);
	if (b < a && i > mr[1] && i > mc[b])
		it += solve(a, b+1, c, d, e);
	if (c < b && i > mr[2] && i > mc[c])
		it += solve(a, b, c+1, d, e);
	if (d < c && i > mr[3] && i > mc[d])
		it += solve(a, b, c, d+1, e);
	if (e < d && i > mr[4] && i > mc[e])
		it += solve(a, b, c, d, e+1);
	return it;
}

int a[5];
int main()
{
	freopen("twofive.in", "r", stdin);
	freopen("twofive.out", "w", stdout);
	int n, l, k, i, j;
	memset(mr, -1, sizeof(mr));
	memset(mc, -1, sizeof(mc));
	if (getchar() == 'W')
	{
		n = 0;
		getchar();
		for (i = 0; i < 5; i++)
			for (j = 0; j < 5; j++)
			{
				a[i]++;
				l = getchar()-'A';
				for (k = 0; k < l; k++)
					if (t[k] == 0 && k > mr[i] && k > mc[j])
					{
						t[k] = 1;
						mr[i] = mc[j] = k;
						memset(dp, -1, sizeof(dp));
						n += solve(a[0], a[1], a[2], a[3], a[4]);
						t[k] = 0;
					}
				t[l] = 1;
				mr[i] = mc[j] = l;
			}
		printf("%d\n", n+1);
	}
	else
	{
		scanf("%d", &n);
		n--;
		for (i = 0; i < 5; i++)
			for (j = 0; j < 5; j++)
			{
				a[i]++;
				for (l = 0; l < 25 && n >= 0; l++)
					if (t[l] == 0 && l > mr[i] && l > mc[j])
					{
						t[l] = 1;
						mr[i] = mc[j] = l;
						memset(dp, -1, sizeof(dp));
						n -= solve(a[0], a[1], a[2], a[3], a[4]);
						t[l] = 0;
					}
				t[--l] = 1;
				putchar(l+'A');
				n += solve(a[0], a[1], a[2], a[3], a[4]);
			}
		putchar('\n');
	}
	return 0;
}
