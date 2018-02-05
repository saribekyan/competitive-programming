#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))

int n;
int a[210];
vector<vector<pair<int,int> > > g(210);
struct node
{
	int i;
	int N, L, R;
	node *l, *r;
} *head;
void construct(node *p, int i)
{
	p->i = i;
	p->r = p->l = NULL;
	if (g[i].size() == 0)
	{
		p->N = 1;
		return;
	}
	p->l = new node;
	p->L = g[i][0].second;
	construct(p->l, g[i][0].first);
	if (g[i].size() == 1)
	{
		p->N = p->l->N+1;
		return;
	}
	p->r = new node;
	if (g[i].size() == 2)
	{
		p->R = g[i][1].second;
		construct(p->r, g[i][1].first);
		p->N = p->l->N+p->r->N+(int)(p->i == 0 || a[p->i] != 0);
		return;
	}
	int j;
	p->R = a[n] = 0;
	for (j = 1; j < g[i].size(); j++)
		g[n].push_back(g[i][j]);
	construct(p->r, n++);
	p->N = p->l->N+p->r->N+(int)(p->i == 0 || a[p->i] != 0);
}
int dp[210][55][210];
int solve(node *p, int k, int d, int dist)
{
	int &it = dp[p->i][k][d];
	if (it != -1)
		return it;
	if (k == p->N)
		return it = 0;
	it = 1000000000;
	if (k > p->N)
		return it;
	if (p->l == NULL)
		return it = dist*a[p->i];
	int i;
	if (p->l != NULL && p->r != NULL)
	{
		for (i = 0; i <= k; i++)
			it = Min(it, solve(p->l, i, d, dist+p->L)+solve(p->r, k-i, d, dist+p->R)+dist*a[p->i]);
		if (a[p->i])
			for (i = 0; i < k; i++)
				it = Min(it, solve(p->l, i, p->i, p->L)+solve(p->r, k-i-1, p->i, p->R));
		return it;
	}
	if (a[p->i] && k)
		it = solve(p->l, k-1, p->i, p->L);
	return it = Min(it, solve(p->l, k, d, dist+p->L)+dist*a[p->i]);
}
int main()
{
	int m, v, d, i;
	scanf("%d%d", &n, &m);
	a[0] = 0;
	for (n++, i = 1; i < n; i++)
	{
		scanf("%d%d%d", a+i, &v, &d);
		g[v].push_back(make_pair(i, d));
	}
	head = new node;
	construct(head, 0);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(head, m, 0, 0));
	return 0;
}
