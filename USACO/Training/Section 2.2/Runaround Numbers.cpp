/*
PROG: runround
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#define MAX 1000000

int d[MAX], n, m, min;

bool runaround(int p)
{
	bool t[9] = {0};
	char s[10], c;
	int q, k, i, j, l;
	q = 0;
	while (p)
	{
		if (t[p%10-1] || p%10==0)break;
		t[p%10-1] = 1;
		s[q++] = p%10+'0';
		p /= 10;
	}
	for (i = 0; i < (q+1)/2; i++)
	{
		c = s[i];
		s[i] = s[q-i-1];
		s[q-i-1] = c;
	}
	for (i = 0; i < 9; i++)
		t[i] = 0;
	k = i = 0;
	while (k != q)
	{
		j = 0;
		l = s[i]-'0';
		while (j < l)
		{
			i++;
			j++;
			if (i==q)
				i = 0;
		}
		if (t[i])
			return 0;
		t[i] = 1;
		k++;
	}
	return 1;
}

void rec(int p)
{
	int i;
	bool t[10] = {0};
	i = p;
	while (i)
	{
		if (t[i%10-1])return;
		t[i%10-1] = 1;
		i /= 10;
	}
	for (i = 0; i < 9; i++)
		if (!t[i] && 10*p+i+1 <= 10000000)
		{
			d[m++] = 10*p+i+1;
			rec(d[m-1]);
		}
}
FILE* fin = fopen("runround.in", "r");
FILE* fout = fopen("runround.out", "w");
int main()
{
	int t, i;
	fscanf(fin, "%d", &n);
	min = 2000000000;
	m = 9;
	for (i = 1; i <= 9; i++)
	{
		d[i-1] = i;
		rec(i);
	}
	for (i = 0; i < m; i++)
		if (n < d[i] && min > d[i])
			if (runaround(d[i]))
				min = d[i];
	fprintf(fout, "%d\n", min);
	return 0;
}