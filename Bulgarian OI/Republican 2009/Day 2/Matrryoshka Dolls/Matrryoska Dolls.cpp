#include <stdio.h>

char s[10010];
short t[1010];
short d[1010][1010];
short x[1000010], y[1000010];
int main()
{
	int nn, p;
	short ans, n, m, mj, i, j;
	scanf("%hd", &n);
	getchar();
	for (i = 1; i <= n; i++)
	{
		m = 1;
		gets(s);
		for (p = j = 0; m < n; j++)
			if (s[j] == 32)
			{
				x[p] = i;
				y[p] = m++;
				p = 0;
			}
			else
				p = p*10+s[j]-'0';
		p = 0;
		while (s[j] < '0' || s[j] > '9')
			j++;
		while (s[j] >= '0' && s[j] <= '9')
			p = p*10+s[j++]-'0';
		x[p] = i;
		y[p] = n;
	}
	ans = 0;
	for (i = 1; i <= n; i++)
		t[i] = ((i^(i-1))+1)>>1;
	nn = n*n;
	for (p = 1; p <= nn; p++)
	{
		m = 0;
		for (i = x[p]; i > 0; i-=t[i])
			for (j = y[p]; j > 0; j-=t[j])
				if (m < d[i][j])
				{
					m = d[i][j];
					if (m == ans)
						i = j = 0;
				}
		m++;
		mj = n+1;
		for (i = x[p]; i <= n; i+=t[i])
			for (j = y[p]; j < mj; j+=t[j])
				if (d[i][j] < m)
					d[i][j] = m;
				else
					mj = j;
		if (ans < m)
			ans = m;
	}
	printf("%hd\n", ans);
	return 0;
}
