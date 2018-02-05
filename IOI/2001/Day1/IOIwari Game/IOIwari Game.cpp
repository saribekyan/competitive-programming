#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define V(b, a) (b[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]])
typedef vector<short> VS;

short d[6][6][6][6][6][6][6][21], p[6][6][6][6][6][6][6][21];
VS make_move(VS a, int i)
{
	short h = a[i];
	a[i] = 0;
	i = (i+1)%7;
	while (h)
	{
		if (h > 1)
			if (a[i] == 5)
			{
				a[7]++;
				a[i]--;
			}
			else
			{
				h--;
				a[i]++;
			}
		else
			if (a[i] > 0 && a[i] < 5)
			{
				a[7] += a[i]+1;
				a[i] = h = 0;
			}
			else
				h--;
		i = (i+1)%7;
	}
	return a;
}
short solve(VS a)
{
	short s=0, i;
	short &D = V(d,a), &P = V(p,a);
	if (D != -1)
		return D;
	for (i = 0; i < 8; i++)
		s += a[i];
	if (s == a[7])
	{
		if (s > 10)
			return D = 1;
		if (s < 10)
			return D = 0;
		return D = 2;
	}
	VS b;
	short x, j;
	for (i = 0; i < 7; i++)
		if (a[i])
		{
			b = make_move(a, i);
			for (s = j = 0; j < 8; j++)
				s += b[j];
			b[7] = 20-s;
			x = solve(b);
			if (x == 0)
			{
				D = 1;
				P = i;
			}
			if (x == 2 && D != 1)
			{
				D = 2;
				P = i;
			}
			if (x == 1 && D == -1)
			{
				D = 0;
				P = i;
			}
		}
	return D;
}
int main()
{
	VS a(8);
	short s, m, i;
	for (i = 0; i < 7; i++)
		cin >> a[i];
	a[7] = 0;
	memset(d, -1, sizeof(d));
	solve(a);
	while (1)
	{
		cout << V(p,a)+1 << '\n' << flush;
		a = make_move(a, V(p,a));
		cin >> m;
		for (s = i = 0; i < 8; i++)
			s += a[i];
		a[7] = 20-s;
		a = make_move(a, m-1);
		for (s = i = 0; i < 8; i++)
			s += a[i];
		a[7] = 20-s;
	}
	return 0;
}
