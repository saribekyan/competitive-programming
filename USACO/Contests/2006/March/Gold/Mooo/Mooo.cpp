#include <cstdio>
#include <algorithm>
using namespace std;
#define Max(a, b) ((a)>(b)?(a):(b))

int n;
int h[50005];
int v[50005];
int hear[50005];
int d[2][50005];
void read()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", h+i, v+i);
}
void build(int s)
{
	int i, j;
	d[s][n-1] = n;
	for (i = n-2; i >= 0; i--)
	{
		j = i+1;
		while (j < n && h[j] <= h[i])
			j = d[s][j];
		d[s][i] = j;
		if (j != n)
			if (s == 0)
				hear[j] += v[i];
			else
				hear[n-j-1] += v[i];
	}
}
int solve()
{
	int m, i;
	build(0);
	reverse(h, h+n);
	reverse(v, v+n);
	build(1);
	for (m = i = 0; i < n; i++)
		m = Max(hear[i], m);
	return m;
}
int main()
{
	freopen("mooo.in", "r", stdin);
	freopen("mooo.out", "w", stdout);
	read();
	printf("%d\n", solve());
	return 0;
}
