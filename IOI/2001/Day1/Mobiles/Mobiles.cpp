#include <iostream>
using namespace std;

int n;
int two[1025];
int d[1025][1025];
void add(int x, int y, int s)
{
	int i, j;
	for (i = x; i <= n; i += two[i])
		for (j = y; j <= n; j += two[j])
			d[i][j] += s;
}
int sum(int x, int y)
{
	int s, i, j;
	s = 0;
	for (i = x; i > 0; i -= two[i])
		for (j = y; j > 0; j -= two[j])
			s += d[i][j];
	return s;
}
int main()
{
	int s, x1, y1, x2, y2, i;
	cin >> s >> n;
	for (i = 1; i <= n; i++)
	{
		s = i;
		two[i] = 1;
		while (s%2 == 0)
		{
			two[i] <<= 1;
			s >>= 1;
		}
	}
	while (cin >> s && s != 3)
		if (s == 1)
		{
			cin >> x1 >> y1 >> s;
			add(x1+1, y1+1, s);
		}
		else
		{
			cin >> x1 >> y1 >> x2 >> y2;
			cout << sum(x2+1, y2+1)-sum(x2+1, y1)-sum(x1, y2+1)+sum(x1, y1) << '\n';
		}
	return 0;
}
