#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

struct P
{
	int p, i;
	bool open;
} g[200010];
bool operator < (P a, P b)
{
	if (a.p < b.p)
		return 1;
	if (a.p > b.p || a.open && b.open)
		return 0;
	return a.open;
}
int p[100010];
int d[100010][3];
multiset<int> s;

int two[20];
int lt[100010];
int r[18][100010];
void build(int n)
{
	int i, j;
	for (i = 0; i < 20; i++)
		two[i] = (1<<i);
	for (i = 1; i <= n; i++)
	{
		for (lt[i] = 0; (1<<lt[i]) <= i; lt[i]++);
		lt[i]--;
	}
	for (i = 1; i <= n; i++)
		r[0][i] = p[i];
	for (i = 1; i <= lt[n]; i++)
		for (j = 1; j <= n; j++)
			r[i][j] = Min(r[i-1][j], r[i-1][j+two[i-1]]);
}
int min_val(int a, int b)
{
	int l = lt[b-a+1];
	return Min(r[l][a], r[l][b-two[l]+1]);
}
int main()
{
	freopen("rmq.in", "r", stdin);
	freopen("rmq.out", "w", stdout);
	int n, m, w, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", d[i], d[i]+1, d[i]+2);
		g[i<<1].open = 1;
		g[i<<1].p = d[i][0];
		g[(i<<1)|1].open = 0;
		g[(i<<1)|1].p = d[i][1];
		g[i<<1].i = g[(i<<1)|1].i = i;
	}
	j = 0;
	sort(g, g+(m<<1));
	for (i = 1; i <= n; i++)
		if (i == g[j].p)
		{
			p[i] = -2147483648;
			while (i == g[j].p)
			{
				if (g[j].open)
				{
					s.insert(d[g[j].i][2]);
					w = *s.rbegin();
					p[i] = Max(p[i], w);
				}
				else
				{
					w = *s.rbegin();
					p[i] = Max(p[i], w);
					s.erase(s.find(d[g[j].i][2]));
				}
				j++;
			}
		}
		else
			if (!s.empty())
				p[i] = *s.rbegin();
			else
				p[i] = 2147483647;

	build(n);
	for (i = 0; i < m; i++)
		if (d[i][2] != min_val(d[i][0], d[i][1]))
		{
			printf("inconsistent\n");
			return 0;
		}
	printf("consistent\n%d", p[1]);
	for (i = 2; i <= n; i++)
		printf(" %d", p[i]);
	putchar('\n');
	return 0;
}
