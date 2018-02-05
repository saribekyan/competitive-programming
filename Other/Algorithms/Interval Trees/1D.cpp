// Interval Trees
// While not end of file gets queries
// "T a b" - fills the interval [a,b] with 1
// "F a b" - fills the interval [a,b] with 0
// "N a b" - for every element of the interval [a,b] if it is 0 makes it 1 else makes it 0
// "C a b" - c is the number of 1-s in the interval [a,b]
#include <stdio.h>
#include <string.h>

int c;
int d[100000];
int start[100000], end[100000];
void _do(int a, int b, int p, int t)
{
	if (t <= 1 && (a == start[p] && b == end[p] || d[p] == (!t)))
	{
		d[p] = !t;
		return;
	}
	if (t == 2 && a == start[p] && b == end[p] && d[p] != -1)
	{
		d[p] = !d[p];
		return;
	}
	if (t == 3 && a >= start[p] && b <= end[p] && d[p] != -1)
	{
		c += d[p]*(b-a+1);
		return;
	}
	if (d[p] != -1 && t != 3)
	{
		_do(start[p<<1], end[p<<1], (p<<1), !d[p]);
		_do(start[(p<<1)|1], end[(p<<1)|1], ((p<<1)|1), !d[p]);
	}
	if (b <= end[p<<1])
		_do(a, b, (p<<1), t);
	else
		if (a >= start[(p<<1)|1])
			_do(a, b, ((p<<1)|1), t);
		else
		{
			_do(a, end[p<<1], (p<<1), t);
			_do(start[(p<<1)|1], b, ((p<<1)|1), t);
		}
	if (t != 3)
	{
		if (d[p<<1] != d[(p<<1)|1])
			d[p] = -1;
		else
			d[p] = d[p<<1];
	}
}
int main()
{
	char ch;
	int a, b, i;
	memset(d, 0, sizeof(d));
	start[1] = 1;
	end[1] = (1<<15);
	for (i = 1; i <= (1<<15); i++)
	{
		start[i<<1] = start[i];
		end[i<<1] = ((start[i]+end[i])>>1);
		start[(i<<1)|1] = end[i<<1]+1;
		end[(i<<1)|1] = end[i];
	}
	while (scanf("%c%d%d", &ch, &a, &b) == 3)
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
