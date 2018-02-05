#include <cstdio>
#include <algorithm>
using namespace std;

short s[10];
short sum, n;
short p[10][10];
void read()
{
	scanf("%d%d", &n, &sum);
}
void build()
{
	short i, j;
	for (i = 0; i < n; i++)
		s[i] = i+1;
	for (i = 1; i < n; i++)
		p[i][0] = p[i][i] = 1;
	for (i = 1; i < n; i++)
		for (j = 1; j < i; j++)
			p[i][j] = p[i-1][j]+p[i-1][j-1];
}
void solve()
{
	short w, i;
	do
	{
		for (w = i = 0; i < n; i++)
			w += p[n-1][i]*s[i];
		if (w == sum)
			return;
	}
	while (next_permutation(s, s+n));
}
void print()
{
	short i;
	for (i = 0; i < n-1; i++)
		printf("%d ", s[i]);
	printf("%d\n", s[n-1]);
}
int main()
{
	freopen("bdsum.in", "r", stdin);
	freopen("bdsum.out", "w", stdout);
	read();
	build();
	solve();
	print();
	return 0;
}
