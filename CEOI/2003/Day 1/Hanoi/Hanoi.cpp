#include <stdio.h>
#define MOD 1000000

int two[100010];
int d[100010][3];
int pos[100010], l[3];
int main()
{
	freopen("hanoi.in", "r", stdin);
	freopen("hanoi.out", "w", stdout);
	int n, v, i, j;
	scanf("%d%d%d%d", &n, l, l+1, l+2);
	for (i = 0; i < 3; i++)
		for (j = 0; j < l[i]; j++)
		{
			scanf("%d", &v);
			pos[v] = i;
		}
	two[0] = 1;
	for (i = 1; i <= n; i++)
		two[i] = (two[i-1]<<1)%MOD;
	for (i = 1; i <= n; i++)
		for (j = 0; j < 3; j++)
			if (pos[i] == j)
				d[i][j] = d[i-1][j];
			else
				d[i][j] = (d[i-1][3-j-pos[i]]+two[i-1])%MOD;
	printf("%d\n%d\n", pos[n]+1, d[n][pos[n]]);
	return 0;
}
