#include <cstdio>
#include <algorithm>
using namespace std;
#define P 1993

char a[20010];
char *s[1000010];
int h[1000010], d[1000010], len[1000010];
int main()
{
	freopen("toponyms.in", "r", stdin);
	freopen("toponyms.out", "w", stdout);
	int n, p, m, l, i, j;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets(a);
		len[i] = strlen(a);
		s[i] = new char[len[i]+1];
		strcpy(s[i], a);
	}
	p = 1;
	for (i = 0; i < 20000; i++)
	{
		m = 0;
		for (j = 0; j < n; j++)
			if (i < len[j])
				d[m++] = h[j] = h[j]*P+s[j][i];
		if (m == 0)
			break;
		sort(d, d+m);
		for (l = j = 1; j < m; j++)
			if (d[j] == d[j-1])
				l++;
		else
		{
			if (p < l*(i+1))
				p = l*(i+1);
			l = 1;
		}
		if (p < l*(i+1))
			p = l*(i+1);
	}
	printf("%d\n", p);
	return 0;
}
