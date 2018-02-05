#include <stdio.h>
#include <string.h>

int n, l, h;
int d[110][110];
bool t[110][110];
int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};
void dfs(int i, int j)
{
	int p, q, k;
	for (k = 0; k < 4; k++)
	{
		p = i+di[k];
		q = j+dj[k];
		if (p >= 0 && p < n && q >= 0 && q < n && !t[p][q] && d[p][q] >= l && d[p][q] <= h)
		{
			t[p][q] = 1;
			dfs(p, q);
		}
	}
}
bool can(int k)
{
	for (l = 0; l <= 110-k; l++)
	{
		h = l+k;
		if (d[0][0] >= l && d[0][0] <= h)
		{
			memset(t, 0, sizeof(t));
			t[0][0] = 1;
			dfs(0, 0);
			if (t[n-1][n-1])
				return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("mtwalk.in", "r", stdin);
	freopen("mtwalk.out", "w", stdout);
	int p, q, k, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", d[i]+j);
	p = 0;
	q = 110;
	while (q-p > 1)
	{
		k = ((p+q)>>1);
		if (can(k))
			q = k;
		else
			p = k;
	}
	if (can(p))
		printf("%d\n", p);
	else
		printf("%d\n", q);
	return 0;
}
