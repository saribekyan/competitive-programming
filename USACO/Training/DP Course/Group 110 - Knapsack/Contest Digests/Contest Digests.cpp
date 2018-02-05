/*
PROG: digest
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <string>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))

bool v[40010];
int m[11], t[11];
string d[40010], s;
int main()
{
	freopen("digest.in", "r", stdin);
	freopen("digest.out", "w", stdout);
	int n, p, t, r, i, j, k;
	scanf("%d%d", &n, &p);
	v[0] = 1;
	for (i = 0; i <= p; i++)
	{
		d[i] = "";
		for (j = 0; j < 100; j++)
			d[i] += ".";
	}
	r = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", m+i);
		for (j = 0; j < m[i]; j++)
		{
			scanf("%d", &t);
			for (k = p-t; k >= 0; k--)
				if (v[k])
				{
					s = d[k];
					s[r] = '*';
					d[k+t] = Min(d[k+t], s);
					v[k+t] = 1;
				}
			r++;
		}
	}
	for (i = j = 0; i < n; i++)
	{
		while (m[i]--)
			printf("%c", d[p][j++]);
		putchar('\n');
	}
	return 0;
}
