#include <cstdio>
#include <algorithm>
using namespace std;
#define Max(a, b) ((a)>(b)?(a):(b))

int s[2][1000010];
int main()
{
	int n, p, k, l, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &p);
		for (k = i, l = 0; l < 2; l++, k = (n-i+2)%n)
			if (p >= k)
				if (p-k < n-p+k)
					s[l][i-1] = k-p;
				else
					s[l][i-1] = n-p+k;
			else
				if (k-p <= n-k+p)
					s[l][i-1] = k-p;
				else
					s[l][i-1] = k-p-n;
	}
	p = 0;
	for (l = 0; l < 2; l++)
	{
		sort(s[l], s[l]+n);
		for (i = 0; i < n-1; i++)
			p = Max(p, s[l][i+1]-s[l][i]-1);
		p = Max(p, n-s[l][i]+s[l][0]-1);
	}
	printf("%d\n", (n-p)/2);
	return 0;
}
