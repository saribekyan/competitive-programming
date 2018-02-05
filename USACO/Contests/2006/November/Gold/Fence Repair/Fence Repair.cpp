#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int> > Q;
int main()
{
	freopen("plank.in", "r", stdin);
	freopen("plank.out", "w", stdout);
	int n, p, q;
	long long ans = 0;
	scanf("%d", &n);
	for (p = 0; p < n; p++)
	{
		scanf("%d", &q);
		Q.push(q);
	}
	while (Q.size() != 1)
	{
		p = Q.top(); Q.pop();
		q = Q.top(); Q.pop();
		ans += p+q;
		Q.push(p+q);
	}
	printf("%lld\n", ans);
	return 0;
}
