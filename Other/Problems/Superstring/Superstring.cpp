#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))

short n;
short len[21];
short in[21][21];
char w[21][110], sw[110];
short d[21][1<<20], pr[21][1<<20];
short solve(short p, int t)
{
	short &it = d[p][t];
	if (it)
		return it;
	if (t == (1<<p))
		return it = len[p];
	short s, i;
	it = 20000;
	t ^= (1<<p);
	for (i = 0; i < n; i++)
		if ((t>>i)&1)
		{
			s = solve(i, t)+len[p]-in[p][i];
			if (it > s)
			{
				it = s;
				pr[p][t] = i;
			}
		}
	return it;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	short s, i, j, k, l;
	scanf("%hd", &n);
	for (i = 0; i < n; i++)
		scanf("%s", w[i]);
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
			if (strcmp(w[i], w[j]) > 0)
			{
				strcpy(sw, w[i]);
				strcpy(w[i], w[j]);
				strcpy(w[j], sw);
			}
	for (i = 0; i < n; i++)
		len[i] = strlen(w[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i != j)
			{
				for (k = 0; k+len[j] <= len[i]; k++)
				{
					for (l = 0; l < len[j] && w[j][l] == w[i][k+l]; l++);
					if (l == len[j])
						break;
				}
				if (k+len[j] <= len[i])
				{
					for (k = j+1; k < n; k++)
					{
						strcpy(w[k-1], w[k]);
						len[k-1] = len[k];
					}
					j--;
					i -= (int)(i>j);
					n--;
				}
			}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i != j)
				for (in[i][j] = Min(len[i], len[j])-1; in[i][j] > 0; in[i][j]--)
				{
					if (i == 6 && j == 5 && in[i][j] == 26)
						i = i;
					for (k = 0; k < in[i][j] && w[j][k] == w[i][len[i]-in[i][j]+k]; k++)
					{
						i = i;
						j = j;
					}
					if (k == in[i][j])
						break;
				}
	l = 20000;
	t = (1<<n)-1;
	for (i = 0; i < n; i++)
	{
		s = solve(i, t);
		if (l > s)
		{
			l = s;
			k = i;
		}
	}
	printf("%s", w[k]);
	t ^= (1<<k);
	while (t)
	{
		for (i = in[k][pr[k][t]]; i < len[pr[k][t]]; i++)
			putchar(w[pr[k][t]][i]);
		k = pr[k][t];
		t ^= (1<<k);
	}
	putchar('\n');
	return 0;
}
