#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

int ci, cj, l;
int d[400][400];
char s[200][200];
bool can(int k)
{
	int x1, y1, x2, y2;
	x1 = Min(ci+k, l);
	y1 = Min(cj+k, l);
	x2 = Max(ci-k-1, 0);
	y2 = Max(cj-k-1, 0);
	return (d[x1][y1]-d[x1][y2]-d[x2][y1]+d[x2][y2]!=0);
}
int main()
{
	int t, n, m, p, q, k, i, j;
	scanf("%d", &t);
	while (t)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
			scanf("%s", s[i]);
		l = Max(n, m);
		memset(d, 0, sizeof(d));
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (s[i][j] == '1')
					d[i-j+l][i+j+1] = 1;
		l <<= 1;
		for (i = 1; i <= l; i++)
			for (j = 1; j <= l; j++)
				d[i][j] += d[i-1][j]+d[i][j-1]-d[i-1][j-1];
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				p = 0;
				q = l;
				ci = i-j+(l>>1);
				cj = i+j+1;
				while (q-p > 1)
				{
					k = ((p+q)>>1);
					if (can(k))
						q = k;
					else
						p = k;
				}
				if (can(p))
					printf("%d", p);
				else
					printf("%d", q);
				if (j != m-1)
					putchar(' ');
			}
			putchar('\n');
		}
		t--;
	}
	return 0;
}
