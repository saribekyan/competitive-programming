#include <cstdio>
#include <algorithm>
using namespace std;

int k;
int c[31];
int *d[100010];
bool cmp(int *a, int *b)
{
	int i;
	for (i = 0; i < k; i++)
	{
		if (a[i] < b[i])
			return 1;
		if (a[i] > b[i])
			return 0;
	}
	return 0;
}
int main()
{
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	int n, m, p, q, i, j;
	scanf("%d%d", &n, &k);
	d[0] = new int[k];
	for (j = 0; j+1 < k; j++)
		d[0][j] = 0;
	d[0][k-1] = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &p);
		for (j = 0; j < k; j++)
			c[j] += (p>>j)&1;
		d[i] = new int[k];
		for (j = 0; j+1 < k; j++)
			d[i][j] = c[j]-c[j+1];
		d[i][k-1] = i;
	}
	m = 0;
	sort(d, d+n+1, cmp);
	for (p = 0; p <= n; p = q)
	{
		q = p;
		while (q <= n)
		{
			for (i = 0; i+1 < k && d[q][i] == d[p][i]; i++);
			if (i+1 < k)
				break;
			if (m < abs(d[p][k-1]-d[q][k-1]))
				m = abs(d[p][k-1]-d[q][k-1]);
			q++;
		}
	}
	printf("%d\n", m);
	return 0;
}
