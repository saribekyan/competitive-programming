#include <cstdio>
#include <algorithm>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))

short s[400][400];
int main()
{
	char ch;
	int ans, n, m, p, st, l, i, j, k;
	while (scanf("%d%d%d", &n, &m, &p) && (n || m || p))
	{
		memset(s, 0, sizeof(s));
		for (i = 0; i < n; i++)
		{
			getchar();
			for (j = 0; j < m; j++)
			{
				scanf("%c", &ch);
				s[i+1][j] = s[i][j]+(int)(ch == '.');
			}
		}
		ans = 123456789;
		for (i = 1; i <= n; i++)
			for (j = i; j <= n; j++)
			{
				ch = 1;
				st = l = 0;
				for (k = 0; k < m; k++)
				{
					if (ch)
						l += s[j][k]-s[i-1][k];
					if (l >= p)
						ans = Min(ans, (j-i+1)*(k-st+1));
					if (l >= p)
					{
						l -= s[j][st]-s[i-1][st];
						st++;
						k--;
						ch = 0;
						continue;
					}
					ch = 1;
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}
