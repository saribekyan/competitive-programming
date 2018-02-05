#include <stdio.h>
#include <string.h>

int len[20], n;
char w[20][110];
int d[20][1<<17];
int C(int t)
{
	int r=0, i;
	for (i = 0; i < n; i++)
		if ((t>>i)&1)
			r += len[i];
	return r;
}
int solve(int s, int t)
{
	int &it = d[s][t];
	if (it != -1)
		return it;
	int p=0, i;
	for (i = 0; i < n; i++)
		p += ((t>>i)&1);
	if (p == 1)
		return it = 1;
	it = 0;
	for (i = 0; i < n; i++)
		if (i != s && ((t>>i)&1))
			if (w[s][len[s]-1] == w[i][0])
				if (solve(i, t^(1<<s)))
					return it = 1;
	return 0;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m, p, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", w[i]);
		len[i] = strlen(w[i]);
	}
	m = -1;
	memset(d, -1, sizeof(d));
	for (i = 0; i < n; i++)
		for (j = 0; j < (1<<n); j++)
			if ((j>>i)&1)
				if (solve(i, j))
				{
					p = C(j);
					if (m < p)
						m = p;
				}
	printf("%d\n", m);
	return 0;
}

