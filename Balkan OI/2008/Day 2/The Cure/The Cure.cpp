#include <cstdio>
#include <queue>
using namespace std;
#define inf 1000000000

int d[(1<<20)+10];
struct node
{
	int p, d;
} p, q;
bool operator < (node a, node b)
{
	return a.d > b.d;
}
priority_queue<node> Q;
int t[110], a[110], b[110], x[110], y[110];
int main()
{
	char ch;
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", t+i);
		getchar();
		for (j = 0; j < n; j++)
		{
			ch = getchar();
			if (ch == '+')
				a[i] ^= 1<<j;
			if (ch == '-')
				b[i] ^= 1<<j;
		}
		ch = getchar();
		y[i] = (1<<n)-1;
		for (j = 0; j < n; j++)
		{
			ch = getchar();
			if (ch == '+')
				x[i] ^= 1<<j;
			if (ch == '-')
				y[i] ^= 1<<j;
		}
	}
	for (i = 0; i < (1<<n)-1; i++)
		d[i] = inf;
	p.p = (1<<n)-1;
	d[p.p] = p.d = 0;
	Q.push(p);
	while (!Q.empty())
	{
		p = Q.top(); Q.pop();
		if (p.d != d[p.p])
			continue;
		if (p.p == 0)
		{
			printf("%d\n", p.d);
			return 0;
		}
		for (i = 0; i < m; i++)
			if ((p.p&a[i]) == a[i] && (p.p&b[i]) == 0)
			{
				q.p = (p.p|x[i])&y[i];
				q.d = p.d+t[i];
				if (d[q.p] > q.d)
				{
					d[q.p] = q.d;
					Q.push(q);
				}
			}
	}
	printf("-1\n");
	return 0;
}
