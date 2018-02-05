/*
PROG: buylow
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define max(a, b) ((a)>(b)?(a):(b))

int w[5001], lds[5001];
char a[1000], b[1000];
char number[5001][1000], p[1000];
void sum(char *f, char *s, char *c)
{
	strcpy(a, f);
	strcpy(b, s);
	int n = strlen(a), m = strlen(b), d, k, i;
	reverse(a, a+n);
	reverse(b, b+m);
	for (i = n; i < m; i++)
		a[i] = '0';
	for (i = m; i < n; i++)
		b[i] = '0';
	n = max(m, n);
	a[n] = b[n] = 0;
	for (k = i = 0; i < n; i++)
	{
		d = (a[i]-'0')+(b[i]-'0')+k;
		c[i] = d%10+'0';
		k = d/10;
	}
	if (k)
		c[n++] = '1';
	c[n] = 0;
	reverse(c, c+n);
}
void subtract(char *f, char *s, char *c)
{
	strcpy(a, f);
	strcpy(b, s);
	int n = strlen(a), m = strlen(b), i, j;
	reverse(a, a+n);
	reverse(b, b+m);
	for (i = n; i < m; i++)
		a[i] = '0';
	for (i = m; i < n; i++)
		b[i] = '0';
	n = max(m, n);
	a[n] = b[n] = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] >= b[i])
			c[i] = (a[i]-'0')-(b[i]-'0')+'0';
		else
		{
			c[i] = 10+(a[i]-'0')-(b[i]-'0')+'0';
			j = i+1;
			while (a[j] == '0')
				a[j++] = '9';
			a[j]--;
		}
	}
	n--;
	while (c[n] == '0' && n > 0)
		c[n--] = 0;
	reverse(c, c+n+1);
}
FILE* fin = fopen("buylow.in", "r");
FILE* fout = fopen("buylow.out", "w");
int main()
{
	int n, m, i, j;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%d", w+i);
	for (i = 0; i <= n; i++)
	{
		lds[i] = 1;
		strcpy(number[i], "1\0");
	}
	w[n] = 0;
	for (i = 0; i <= n; i++, m = -1)
		for (j = 0; j < i; j++)
			if (w[j] > w[i])
				if (lds[i] < lds[j]+1)
				{
					lds[i] = lds[j]+1;
					strcpy(p, number[j]);
					strcpy(number[i], number[j]);
					m = w[j];
				}
				else
					if (lds[i] == lds[j]+1)
					{
						sum(number[i], number[j], number[i]);
						if (m == w[j])
							subtract(number[i], p, number[i]);
						m = w[j];
						strcpy(p, number[j]);
					}
	fprintf(fout, "%d %s\n", lds[n]-1, number[n]);
	return 0;
}