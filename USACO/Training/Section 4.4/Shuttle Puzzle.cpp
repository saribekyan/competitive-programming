/*
PROG: shuttle
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

char s[26];
FILE* fin = fopen("shuttle.in", "r");
FILE* fout = fopen("shuttle.out", "w");
int main()
{
	bool jump, side, t;
	int n, m, w, r, p, pl, l, i;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		s[i] = '1';
	s[i++] = ' ';
	while (i < ((n<<1)|1))
		s[i++] = '0';
	p = n;
	side = t = 1;
	w = n+1;
	r = m = 0;
	l = 0;
	while (1)
	{
		if (p == n)
		{
			for (i = 0; i < n; i++)
				if (s[i] == '1')
					break;
			if (i == n)
				break;
		}
		if (s[n<<1] == ' ' && n%2)
		{
			t = 0;
			w = 0;
			side = !side;
		}
		if (s[0] == ' ' && n%2 == 0)
		{
			t = 0;
			w = n<<1;
			side = !side;
		}
		if (p == w)
		{
			side = !side;
			if (t)
				if (w > n)
					w = (n<<1)-w-1;
				else
					w = (n<<1)-w+1;
			else
				if (w > n)
					w = (n<<1)-w+1;
				else
					w = (n<<1)-w-1;
		}
		if (m == 0)
			jump = 0;
		if (jump)
		{
			if (side)
			{
				s[p] = s[p+2];
				p += 2;
				pl = p;
				s[p] = ' ';
			}
			else
			{
				s[p] = s[p-2];
				p -= 2;
				pl = p;
				s[p] = ' ';
			}
			m--;
		}
		else
		{
			if (side)
			{
				s[p] = s[p+1];
				p++;
				pl = p;
				s[p] = ' ';
			}
			else
			{
				s[p] = s[p-1];
				p--;
				pl = p;
				s[p] = ' ';
			}
			jump = 1;
			if (t)
				r++;
			else
				r--;
			m = r;
		}
		if (l%20 == 0 && l)
			fputc('\n', fout);
		if (l%20)
			fputc(' ', fout);
		fprintf(fout, "%d", (n<<1)-pl+1);
		l++;
	}
	fputc('\n', fout);
	return 0;
}