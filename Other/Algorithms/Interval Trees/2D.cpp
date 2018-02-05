#define program 0
#define etalon 0
#define test 1

#if program
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 1048576

int c;
int d[MAX];
pair<int,int> s[MAX], e[MAX];
bool in(pair<int,int> a, pair<int,int> b, pair<int,int> c, pair<int,int> d)
{
	return a.first >= c.first && a.second >= c.second &&
		b.first <= d.first && b.second <= d.second;
}
void _do(pair<int,int> a, pair<int,int> b, int p, int t)
{
	if (t <= 1 && (a == s[p] && b == e[p] || d[p] == (!t)))
	{
		d[p] = !t;
		return;
	}
	if (t == 2 && a == s[p] && b == e[p] && d[p] != -1)
	{
		d[p] = !d[p];
		return;
	}
	if (t == 3 && d[p] != -1)
	{
		c += d[p]*(b.first-a.first+1)*(b.second-a.second+1);
		return;
	}
	int i;
	if (t != 3 && d[p] != -1)
		for (i = -2; i < 2; i++)
			_do(s[(p<<2)+i], e[(p<<2)+i], (p<<2)+i, !d[p]);
	for (i = -2; i < 2; i++)
		if (in(a, b, s[(p<<2)+i], e[(p<<2)+i]))
		{
			_do(a, b, (p<<2)+i, t);
			goto there;
		}
	if (in(a, b, s[p], e[(p<<2)-1]))
	{
		_do(a, make_pair(b.first, e[(p<<2)-2].second), (p<<2)-2, t);
		_do(make_pair(a.first, s[(p<<2)-1].second), b, (p<<2)-1, t);
		goto there;
	}
	if (in(a, b, s[(p<<2)-1], e[(p<<2)|1]))
	{
		_do(a, make_pair(e[(p<<2)-1].first, b.second), (p<<2)-1, t);
		_do(make_pair(s[(p<<2)|1].first, a.second), b, ((p<<2)|1), t);
		goto there;
	}
	if (in(a, b, s[p<<2], e[p]))
	{
		_do(a, make_pair(b.first, e[p<<2].second), (p<<2), t);
		_do(make_pair(a.first, s[(p<<2)|1].second), b, ((p<<2)|1), t);
		goto there;
	}
	if (in(a, b, s[p], e[p<<2]))
	{
		_do(a, make_pair(e[(p<<2)-2].first, b.second), (p<<2)-2, t);
		_do(make_pair(s[p<<2].first, a.second), b, (p<<2), t);
		goto there;
	}
	_do(a, e[(p<<2)-2], (p<<2)-2, t);
	_do(make_pair(a.first, s[(p<<2)-1].second), make_pair(e[(p<<2)-1].first, b.second), (p<<2)-1, t);
	_do(s[(p<<2)|1], b, ((p<<2)|1), t);
	_do(make_pair(s[p<<2].first, a.second), make_pair(b.first, e[p<<2].second), (p<<2), t);
there:;
	if (t != 3)
	{
		for (i = -2; i < 1 && d[(p<<2)+i] == d[(p<<2)+i+1]; i++);
		if (i != 1)
			d[p] = -1;
		else
			d[p] = d[p<<2];
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output_e.txt", "w", stdout);
	int i;
	char ch;
	pair<int,int> a, b;
	memset(d, 0, sizeof(d));
	s[1].first = s[1].second = 1;
	e[1].first = e[1].second = (1<<8);
	for (i = 1; i < (MAX>>2); i++)
	{
		s[(i<<2)-2] = s[i];
		e[(i<<2)-2].first = ((s[i].first+e[i].first)>>1);
		e[(i<<2)-2].second = ((s[i].second+e[i].second)>>1);
		s[(i<<2)-1].first = s[i].first;
		s[(i<<2)-1].second = e[(i<<2)-2].second+1;
		e[(i<<2)-1].first = e[(i<<2)-2].first;
		e[(i<<2)-1].second = e[i].second;
		s[i<<2].first = e[(i<<2)-2].first+1;
		s[i<<2].second = s[i].second;
		e[i<<2].first = e[i].first;
		e[i<<2].second = e[(i<<2)-2].second;
		s[(i<<2)|1].first = e[(i<<2)-2].first+1;
		s[(i<<2)|1].second = e[(i<<2)-2].second+1;
		e[(i<<2)|1] = e[i];
	}
	while (scanf("%c%d%d%d%d", &ch, &a.first, &a.second, &b.first, &b.second) == 5)
	{
		if (ch == 'T' || ch == 'F')
			_do(a, b, 1, (int)(ch == 'F'));
		if (ch == 'N')
			_do(a, b, 1, 2);
		if (ch == 'C')
		{
			c = 0;
			_do(a, b, 1, 3);
			printf("%d\n", c);
		}
		getchar();
	}
	return 0;
}
#endif
#if etalon
#include <cstdio>
#include <algorithm>
using namespace std;

int d[1030][1030];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output_e.txt", "w", stdout);
	char ch;
	int c, i, j;
	pair<int,int> a, b;
	memset(d, 0, sizeof(d));
	while (scanf("%c%d%d%d%d", &ch, &a.first, &a.second, &b.first, &b.second) == 5)
	{
		if (ch == 'T' || ch == 'F')
			for (i = a.first; i <= b.first; i++)
				for (j = a.second; j <= b.second; j++)
					d[i][j] = (int)(ch == 'T');
		if (ch == 'N')
			for (i = a.first; i <= b.first; i++)
				for (j = a.second; j <= b.second; j++)
					d[i][j] = !d[i][j];
		if (ch == 'C')
		{
			c = 0;
			for (i = a.first; i <= b.first; i++)
				for (j = a.second; j <= b.second; j++)
					c += d[i][j];
			printf("%d\n", c);
		}
		getchar();
	}
	return 0;
}
#endif
#if test
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int a, b, c, d, i;
	freopen("input.txt", "w", stdout);
	srand(time(0)+165651LL);
	for (i = 0; i < 10000; i++)
	{
		a = rand()%4;
		if (a == 0)
			putchar('T');
		if (a == 1)
			putchar('F');
		if (a == 2)
			putchar('N');
		if (a == 3)
			putchar('C');
		a = 1;
		b = 1;
		c = 250;
		d = 250;
		printf(" %d %d %d %d\n", a, b, c, d);
	}
	return 0;
}
#endif
