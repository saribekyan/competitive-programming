#include <stdio.h>
#include <string.h>

int n;
int a[20];
int d[1<<20];
int solve(int t)
{
	int &it = d[t];
	if (it != -1)
		return it;
	if (t == 0)
		return it = 0;
	int s, w, p, i, j, k;
	s = 0;
	for (i = 0; i < n; i++)
		s += ((t>>i)&1)*a[i];
	it = 1000000000;
	for (i = 0; i < n; i++)
	{
		w = s;
		p = t;
		for (j = 0; j < 3; j++)
		{
			k = (i+j)%n;
			if ((t>>k)&1)
			{
				p ^= (1<<k);
				w -= a[k];
			}
		}
		if (p != t)
			if (it > solve(p)+w)
				it = solve(p)+w;
	}
	return it;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", a+i);
	memset(d, -1, sizeof(d));
	printf("%d\n", solve((1<<n)-1));
	return 0;
}
