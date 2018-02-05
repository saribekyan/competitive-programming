#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

queue<int> Q;
int t[100010];
int main()
{
	freopen("catchcow.in", "r", stdin);
	freopen("catchcow.out", "w", stdout);
	int n, p, q, m;
	scanf("%d%d", &n, &m);
	memset(t, -1, sizeof(t));
	t[n] = 0;
	Q.push(n);
	while (!Q.empty())
	{
		p = Q.front();
		if (p == m)
		{
			printf("%d\n", t[m]);
			return 0;
		}
		Q.pop();
		if (p > 0 && t[p-1] == -1)
		{
			t[p-1] = t[p]+1;
			Q.push(p-1);
		}
		if (p <= 100001 && t[p+1] == -1)
		{
			t[p+1] = t[p]+1;
			Q.push(p+1);
		}
		if (p <= 50000 && t[2*p] == -1)
		{
			t[2*p] = t[p]+1;
			Q.push(2*p);
		}
	}
	printf("-1\n");
	return 0;
}
