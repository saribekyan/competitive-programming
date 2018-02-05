#include <cstdio>
#include <algorithm>
using namespace std;

int d[1010][110], ld[1010], d1[10010];
int g[1010][1010], w[1010][1010], deg[1010];
int main()
{
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	int n, m, k, p, q, l, i, j, r;
	scanf("%d%d%d", &n, &m, &k);
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &p, &q, &l);
		g[p-1][deg[p-1]] = q-1;
		w[p-1][deg[p-1]++] = l;
	}
	memset(ld, 0, sizeof(ld));
	ld[0]++;
	d[0][0] = 0;
	for (i = 1; i < n; i++)
	{
		l = 0;
		for (j = 0; j < deg[i]; j++)
			for (r = 0; r < ld[g[i][j]]; r++)
				d1[l++] = d[g[i][j]][r]+w[i][j];
		sort(d1, d1+l);
		for (j = 0; j < k && j < l; j++)
			d[i][j] = d1[j];
		ld[i] = min(k, l);
	}
	for (i = 0; i < ld[n-1]; i++)
		printf("%d\n", d[n-1][i]);
	for (i = ld[n-1]; i < k; i++)
		printf("-1\n");
	return 0;
}
