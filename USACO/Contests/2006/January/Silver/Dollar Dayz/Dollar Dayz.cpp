#include <cstdio>
#include <algorithm>
using namespace std;

char d[1001][50], a[50], b[50];
void sum(int p, int q)
{
	int n, m, k, i;
	strcpy(a, d[p]);
	strcpy(b, d[q]);
	n = strlen(a);
	m = strlen(b);
	reverse(a, a+n);
	reverse(b, b+m);
	if (n > m)
		for (i = m; i < n; i++)
			b[i] = '0';
	else
	{
		for (i = n; i < m; i++)
			a[i] = '0';
		n = m;
	}
	a[n] = b[n] = 0;
	k = 0;
	for (i = 0; i < n; i++)
	{
		d[p][i] = ((a[i]-'0')+(b[i]-'0')+k)%10+'0';
		k = ((a[i]-'0')+(b[i]-'0')+k)/10;
	}
	if (k)
	{
		d[p][n] = '1';
		n++;
	}
	d[p][n] = 0;
	reverse(d[p], d[p]+n);
}
FILE* fin = fopen("ddayz.in", "r");
FILE* fout = fopen("ddayz.out", "w");
int main()
{
	int n, m, i, j;
	fscanf(fin, "%d%d", &n, &m);
	d[0][0] = '1';
	d[0][1] = 0;
	for (i = 1; i <= m; i++)
		for (j = 0; j <= n; j++)
			if (i+j <= n)
				sum(i+j, j);
	fprintf(fout, "%s\n", d[n]);
	return 0;
}