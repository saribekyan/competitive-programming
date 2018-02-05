#include <stdio.h>

int st, end;
int d[35][35];
void read()
{
	scanf("%d%d", &st, &end);
}
void build()
{
	int i, j;
	for (i = 0; i < 32; i++)
		d[i][0] = d[i][1] = d[i][i] = 1;
	for (i = 1; i < 32; i++)
		for (j = 1; j < i; j++)
			d[i][j] = d[i-1][j]+d[i-1][j-1];
}
int number(int p)
{
	int bit, s, i, j, l, k;
	for (bit = 0; (p>>bit); bit++);
	s = 1;
	for (i = 1; i < bit; i++)
		for (j = 1; j <= (i>>1); j++)
			s += d[i-1][j-1];
	for (l = i = 0; i < bit; i++)
		l += (p>>i)&1;
	if (l > (bit>>1))
		for (i = 0; l > (bit>>1); i++)
		{
			l -= (p>>i)&1;
			p = (p>>(i+1))<<(i+1);
		}
	if (p == 0)
		return 1;
	for (i = bit-2, k = 1; i >= 0; i--)
		if ((p>>i)&1)
		{
			for (j = 0; j <= i && (k+j <= (bit>>1)); j++)
				s += d[i][j];
			k++;
		}
	return s+1;
}
int solve()
{
	int i, j, l, s;
	return (number(end)-number(st-1));
	for (s = 0, i = st; i <= end; i++)
	{
		for (l = j = 0; (i>>j); j++)
			l += (i>>j)&1;
		if (l <= (j>>1))
			s++;
	}
	return s;
}
int main()
{
	freopen("rndnum.in", "r", stdin);
	freopen("rndnum.out", "w", stdout);
	read();
	build();
	printf("%d\n", solve());
	return 0;
}
