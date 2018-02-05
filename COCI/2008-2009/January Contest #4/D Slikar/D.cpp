#include <stdio.h>
#define Min(a, b) ((a)<(b)?(a):(b))

int n, m;
int ans[1000000];
int pr[1000000][2];
int ones[550][550];
char s[550][550], x[550][550];
int a[1000000], b[1000000], c[1000000], d[1000000];
void build()
{
	int i;
	m = 1;
	a[1] = b[1] = 1;
	c[1] = d[1] = n;
	for (i = 1; a[m] != n || b[m] != n; i++)
	{
		a[i*4-2] = a[i];
		b[i*4-2] = b[i];
		c[i*4-2] = (a[i]+c[i])/2;
		d[i*4-2] = (b[i]+d[i])/2;

		a[i*4-1] = a[i];
		b[i*4-1] = d[i*4-2]+1;
		c[i*4-1] = c[i*4-2];
		d[i*4-1] = d[i];

		a[i*4] = c[i*4-2]+1;
		b[i*4] = b[i];
		c[i*4] = c[i];
		d[i*4] = d[i*4-2];

		a[i*4+1] = c[i*4-2]+1;
		b[i*4+1] = d[i*4-2]+1;
		c[i*4+1] = c[i];
		d[i*4+1] = d[i];
		m += 4;
	}
}
int n_ones(int p)
{
	return ones[c[p]][d[p]]-ones[c[p]][b[p]-1]-ones[a[p]-1][d[p]]+ones[a[p]-1][b[p]-1];
}
void set_ch(int p, char ch)
{
	int i, j;
	for (i = a[p]; i <= c[p]; i++)
		for (j = b[p]; j <= d[p]; j++)
			x[i][j] = ch;
}
void calc(int p)
{
	if (a[p] == c[p])
	{
		set_ch(p, s[a[p]][b[p]]);
		return;
	}
	int i, j, k;
	for (k = 0; k < 2; k++)
		set_ch(p*4+pr[p][k], k+'0');
	for (k = -2; k <= 1; k++)
		if (k != pr[p][0] && k != pr[p][1])
			calc(p*4+k);
}
int main()
{
	int i, j, k, l, w, p, q;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%s", s[i]+1);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			ones[i][j] = s[i][j]-'0'+ones[i-1][j]+ones[i][j-1]-ones[i-1][j-1];
	build();
	for (i = 0; i <= m; i++)
		pr[i][0] = pr[i][1] = -1;
	for (i = m; i >= 1; i--)
	{
		if (a[i] == c[i])
		{
			ans[i] = 0;
			continue;
		}
		w = 0;
		ans[i] = n*n;
		for (k = -2; k <= 1; k++)
			w += ans[i*4+k];
		for (k = -2; k <= 1; k++)
		{
			p = n_ones(i*4+k);
			for (l = -2; l <= 1; l++)
				if (k != l)
				{
					q = (c[i]-a[i]+1)*(d[i]-b[i]+1)/4-n_ones(i*4+l);
					if (ans[i] > p+q+w-ans[i*4+k]-ans[i*4+l])
					{
						pr[i][0] = k;
						pr[i][1] = l;
						ans[i] = p+q+w-ans[i*4+k]-ans[i*4+l];
					}
				}
		}
	}
	calc(1);
	printf("%d\n", ans[1]);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			putchar(x[i][j]);
		putchar('\n');
	}
	return 0;
}
