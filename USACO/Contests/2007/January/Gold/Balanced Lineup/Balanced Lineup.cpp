#include <stdio.h>

int Q;
int n;
int s[50001];
int power[16];
int powertwo[50001];
int query[200001][2];
int minimum[17][50001];
int maximum[17][50001];
void read()
{
	int i;
	scanf("%d%d", &n, &Q);
	for (i = 0; i < n; i++)
		scanf("%d", s+i);
	for (i = 0; i < Q; i++)
		scanf("%d%d", query[i], query[i]+1);
}
void build()
{
	int log, i, j;
	power[0] = 1;
	for (power[0] = log = 1; power[log-1] < n; log++)
		power[log] = power[log-1]<<1;
	for (i = 0; i < n; i++)
		for (j = 0; j < log && power[j] < i; j++)
			powertwo[i] = j;
	for (i = 0; i < n; i++)
		minimum[0][i] = maximum[0][i] = i;
	for (i = 1; i < log; i++)
		for (j = 0; j <= n-power[i]; j++)
		{
			if (s[minimum[i-1][j]] < s[minimum[i-1][j+power[i-1]]])
				minimum[i][j] = minimum[i-1][j];
			else
				minimum[i][j] = minimum[i-1][j+power[i-1]];
			if (s[maximum[i-1][j]] > s[maximum[i-1][j+power[i-1]]])
				maximum[i][j] = maximum[i-1][j];
			else
				maximum[i][j] = maximum[i-1][j+power[i-1]];
		}
	for (i = 0; i < Q; i++)
	{
		query[i][0]--;
		query[i][1]--;
	}
}
int RMinQ(int p, int q)
{
	if (s[minimum[powertwo[q-p+1]][p]] < s[minimum[powertwo[q-p+1]][q-power[powertwo[q-p+1]]+1]])
		return s[minimum[powertwo[q-p+1]][p]];
	else
		return s[minimum[powertwo[q-p+1]][q-power[powertwo[q-p+1]]+1]];
}
int RMaxQ(int p, int q)
{
	if (s[maximum[powertwo[q-p+1]][p]] > s[maximum[powertwo[q-p+1]][q-power[powertwo[q-p+1]]+1]])
		return s[maximum[powertwo[q-p+1]][p]];
	else
		return s[maximum[powertwo[q-p+1]][q-power[powertwo[q-p+1]]+1]];
}
void print()
{
	int i;
	for (i = 0; i < Q; i++)
		printf("%d\n", RMaxQ(query[i][0], query[i][1])-RMinQ(query[i][0], query[i][1]));
}
int main()
{
	freopen("lineupg.in", "r", stdin);
	freopen("lineupg.out", "w", stdout);
	read();
	build();
	print();
	return 0;
}
