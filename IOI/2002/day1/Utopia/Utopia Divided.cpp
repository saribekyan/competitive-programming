#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int d[2][10010];
int s[2][10010];
int ans[2][10010];
void getans(int l)
{
	int m, p, q, i;
	for (m = i = 0; i < n-1; i++)
		m += (int)(s[l][i] != s[l][i+1]);
	p = q = n-m-1;
	m = ans[l][0] = s[l][0]*d[l][p];
	for (i = 1; i < n; i++)
	{
		if (s[l][i-1] != s[l][i])
			ans[l][i] = s[l][i]*d[l][++q];
		else
			if ((m-s[l][i]*d[l][--p])*s[l][i] > 0)
				ans[l][i] = -s[l][i]*d[l][p];
			else
				ans[l][i] = s[l][i]*d[l][p];
		m += ans[l][i];
	}
}
int main()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < 2*n; i++)
		scanf("%d", d[i/n]+i-n*(i/n));
	for (i = 0; i < n; i++)
		scanf("%d", s[0]+i);
	sort(d[0], d[0]+n);
	sort(d[1], d[1]+n);
	memcpy(s[1], s[0], sizeof(s[1]));
	for (i = 0; i < n; i++)
	{
		if (s[0][i] == 4)
			s[0][i] = 1;
		if (s[0][i] == 3 || s[0][i] == 2)
			s[0][i] = -1;
	}
	for (i = 0; i < n; i++)
	{
		if (s[1][i] == 2)
			s[1][i] = 1;
		if (s[1][i] == 3 || s[1][i] == 4)
			s[1][i] = -1;
	}
	getans(0);
	getans(1);
	for (i = 0; i < n; i++)
		printf("%+d %+d\n", ans[0][i], ans[1][i]);
	return 0;
}
