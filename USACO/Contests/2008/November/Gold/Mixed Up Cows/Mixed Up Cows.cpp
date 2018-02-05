#include <stdio.h>
#include <math.h>
#include <string.h>

int w[16], n, k;
long long d[16][1<<16];
long long solve(int s, int t)
{
	long long &it = d[s][t];
	if (it != -1)
		return it;
	int l=0, i;
	for (i = 0; i < n; i++)
		l += ((t>>i)&1);
	if (l == 1)
		return it = 1;
	it = 0;
	for (i = 0; i < n; i++)
		if (i != s && ((t>>i)&1) && abs(w[i]-w[s]) > k)
			it += solve(i, t^(1<<s));
	return it;
}
int main()
{
	freopen("mixup2.in", "r", stdin);
	freopen("mixup2.out", "w", stdout);
	int i;
	long long ans=0;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", w+i);
	memset(d, -1, sizeof(d));
	for (i = 0; i < n; i++)
		ans += solve(i, (1<<n)-1);
	printf("%lld\n", ans);
	return 0;
}
