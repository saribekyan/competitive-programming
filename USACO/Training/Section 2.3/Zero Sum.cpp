/*
PROB: zerosum
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

char **s, c;
int n, m, ans, t, a, b, i, j;

bool less(char *s1, char *s2)
{
	for (i = 0; i < 2*n-1; i++)
	{
		if (s1[i] < s2[i])return 1;
		if (s1[i] > s2[i])return 0;
	}
}

void find(int p, int q)
{
	if (q == n-1)
	{
		t = p;
		ans = 1;
		i = 2;
		while (t%10 == 3)
		{
			ans = ans*10+i;
			t /= 10;
			i++;
		}
		b = t%10;
		while (t)
		{
			t /= 10;
			a = i;
			while (t%10==3)
			{
				a = a*10+i+1;
				t /= 10;
				i++;
			}
			if (b == 1)
				ans += a;
			else
				ans -= a;
			b = t%10;
			i++;
		}
		if (ans == 0)
		{
			i = 1;
			j = 0;
			while (p)
			{
				s[m][j++] = i+'0';
				if (p%10==1)
					s[m][j++] = '+';
				if (p%10==2)
					s[m][j++] = '-';
				if (p%10==3)
					s[m][j++] = ' ';
				p /= 10;
				i++;
			}
			s[m][j++] = n+'0';
			s[m++][j] = 0;
		}
		return;
	}
	find(p*10+3, q+1);
	find(p*10+1, q+1);
	find(p*10+2, q+1);
}
FILE* fin = fopen("zerosum.in", "r");
FILE* fout = fopen("zerosum.out", "w");
int main()
{
	fscanf(fin, "%d", &n);
	m = 0;
	s = new char *[20];
	for (i = 0; i < 20; i++)
		s[i] = new char [20];
	find(0, 0);
	sort(s, s+m, less);
	for (i = 0; i < m; i++)
		fprintf(fout, "%s\n", s[i]);
	return 0;
}