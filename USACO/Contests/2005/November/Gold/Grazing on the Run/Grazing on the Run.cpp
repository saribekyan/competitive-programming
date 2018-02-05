/*
PROG: ontherun
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define inf 1000000000

int c[1010];
int d[1010][1010][2];
int main()
{
	freopen("ontherun.in", "r", stdin);
	freopen("ontherun.out", "w", stdout);
	int n, l, i, j;
	scanf("%d%d", &n, &l);
	for (i = 0; i < n; i++)
		scanf("%d", c+i);
	c[n] = l;
	sort(c, c+n+1);
	for (i = 0; i <= n; i++)
		for (j = 0; j <= n; j++)
			d[i][j][0] = d[i][j][1] = inf;
	for (i = 0; i <= n; i++)
		if (c[i] == l)
			d[i][i][0] = d[i][i][1] = 0;
	for (l = 1; l <= n; l++)
		for (i = 0; i+l <= n+1; i++)
		{
			j = i+l-1;
			if (d[i][j][0] > inf)
				d[i][j][0] = inf;
			if (d[i][j][1] > inf)
				d[i][j][1] = inf;
			if (i > 0)
				if (d[i][j][0]+(c[i]-c[i-1])*(n-(j-i+1)+1) < d[i][j][1]+(c[j]-c[i-1])*(n-(j-i+1)+1))
					d[i-1][j][0] = d[i][j][0]+(c[i]-c[i-1])*(n-(j-i+1)+1);
				else
					d[i-1][j][0] = d[i][j][1]+(c[j]-c[i-1])*(n-(j-i+1)+1);
			if (j < n)
				if (d[i][j][1]+(c[j+1]-c[j])*(n-(j-i+1)+1) < d[i][j][0]+(c[j+1]-c[i])*(n-(j-i+1)+1))
					d[i][j+1][1] = d[i][j][1]+(c[j+1]-c[j])*(n-(j-i+1)+1);
				else
					d[i][j+1][1] = d[i][j][0]+(c[j+1]-c[i])*(n-(j-i+1)+1);
		}
	if (d[0][n][0] < d[0][n][1])
		printf("%d\n", d[0][n][0]);
	else
		printf("%d\n", d[0][n][1]);
	return 0;
}
