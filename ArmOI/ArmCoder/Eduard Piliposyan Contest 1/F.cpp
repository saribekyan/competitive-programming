#include <cstdio>
#include <algorithm>
using namespace std;

int deg[110];
struct interval
{
	int a, b;
} r[110][10010];
struct P
{
	int c;
	bool open;
} d[10010];
bool operator < (P a, P b)
{
	return a.c < b.c || a.c == b.c && a.open && !b.open;
}
int main()
{
	int n, m, k, a, b, c, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &k);
		while (k--)
		{
			scanf("%d%d%d", &a, &b, &c);
			r[c-1][deg[c-1]].a = a;
			r[c-1][deg[c-1]++].b = b;
		}
	}
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (a = 0; a < deg[i]; a++)
		{
			d[k].c = r[i][a].a;
			d[k++].open = 1;
			d[k].c = r[i][a].b;
			d[k++].open = 0;
		}
		b = 0;
		sort(d, d+k);
		for (c = a = 0; a < k; a++)
		{
			if (c)
				b += d[a].c-d[a-1].c;
			if (d[a].open)
				c++;
			else
				c--;
		}
		printf("%d", b);
		if (i+1 != n)
			putchar(' ');
		else
			putchar('\n');
	}
	return 0;
}
