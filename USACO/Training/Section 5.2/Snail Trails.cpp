/*
PROG: snail
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int w;
int n;
char s[120][120];
void rec(int p, int q, int l, char h)
{
	if (h == 'd')
	{
		if (p+1 < n)
		{
			if (s[p+1][q] == '.')
			{
				s[p+1][q] = '+';
				rec(p+1, q, l+1, h);
				s[p+1][q] = '.';
				return;
			}
			if (s[p+1][q] == '+')
			{
				if (w < l)
					w = l;
				return;
			}
		}
		if (q+1 < n)
		{
			if (s[p][q+1] == '.')
			{
				s[p][q+1] = '+';
				rec(p, q+1, l+1, 'r');
				s[p][q+1] = '.';
			}
			if (s[p][q+1] == '+' || s[p][q+1] == '#')
				if (w < l)
					w = l;
		}
		if (q-1 >= 0)
		{
			if (s[p][q-1] == '.')
			{
				s[p][q-1] = '+';
				rec(p, q-1, l+1, 'l');
				s[p][q-1] = '.';
			}
			if (s[p][q-1] == '+' || s[p][q-1] == '#')
				if (w < l)
					w = l;
		}
		if (w < l)
			w = l;
		return;
	}
	if (h == 'u')
	{
		if (p-1 >= 0)
		{
			if (s[p-1][q] == '.')
			{
				s[p-1][q] = '+';
				rec(p-1, q, l+1, h);
				s[p-1][q] = '.';
				return;
			}
			if (s[p-1][q] == '+')
			{
				if (w < l)
					w = l;
				return;
			}
		}
		if (q+1 < n)
		{
			if (s[p][q+1] == '.')
			{
				s[p][q+1] = '+';
				rec(p, q+1, l+1, 'r');
				s[p][q+1] = '.';
			}
			if (s[p][q+1] == '+' || s[p][q+1] == '#')
				if (w < l)
					w = l;
		}
		if (q-1 >= 0)
		{
			if (s[p][q-1] == '.')
			{
				s[p][q-1] = '+';
				rec(p, q-1, l+1, 'l');
				s[p][q-1] = '.';
			}
			if (s[p][q-1] == '+' || s[p][q-1] == '#')
				if (w < l)
					w = l;
		}
		if (w < l)
			w = l;
		return;
	}
	if (h == 'r')
	{
		if (q+1 < n)
		{
			if (s[p][q+1] == '.')
			{
				s[p][q+1] = '+';
				rec(p, q+1, l+1, h);
				s[p][q+1] = '.';
				return;
			}
			if (s[p][q+1] == '+')
			{
				if (w < l)
					w = l;
				return;
			}
		}
		if (p-1 >= 0)
		{
			if (s[p-1][q] == '.')
			{
				s[p-1][q] = '+';
				rec(p-1, q, l+1, 'u');
				s[p-1][q] = '.';
			}
			if (s[p-1][q] == '+' || s[p-1][q] == '#')
				if (w < l)
					w = l;
		}
		if (p+1 < n)
		{
			if (s[p+1][q] == '.')
			{
				s[p+1][q] = '+';
				rec(p+1, q, l+1, 'd');
				s[p+1][q] = '.';
			}
			if (s[p+1][q] == '+' || s[p+1][q] == '#')
				if (w < l)
					w = l;
		}
		if (w < l)
			w = l;
		return;
	}
	if (h == 'l')
	{
		if (q-1 >= 0)
		{
			if (s[p][q-1] == '.')
			{
				s[p][q-1] = '+';
				rec(p, q-1, l+1, h);
				s[p][q-1] = '.';
				return;
			}
			if (s[p][q-1] == '+')
			{
				if (w < l)
					w = l;
				return;
			}
		}
		if (p-1 >= 0)
		{
			if (s[p-1][q] == '.')
			{
				s[p-1][q] = '+';
				rec(p-1, q, l+1, 'u');
				s[p-1][q] = '.';
			}
			if (s[p-1][q] == '+' || s[p-1][q] == '#')
				if (w < l)
					w = l;
		}
		if (p+1 < n)
		{
			if (s[p+1][q] == '.')
			{
				s[p+1][q] = '+';
				rec(p+1, q, l+1, 'd');
				s[p+1][q] = '.';
			}
			if (s[p+1][q] == '+' || s[p+1][q] == '#')
				if (w < l)
					w = l;
		}
		if (w < l)
			w = l;
		return;
	}
}
FILE* fin = fopen("snail.in", "r");
FILE* fout = fopen("snail.out", "w");
int main()
{
	char ch;
	int m, i, j;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			s[i][j] = '.';
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "\n%c%d", &ch, &j);
		s[j-1][ch-'A'] = '#';
	}
	w = 0;
	s[0][0] = '+';
	rec(0, 0, 1, 'd');
	rec(0, 0, 1, 'r');
	fprintf(fout, "%d\n", w);
	return 0;
}