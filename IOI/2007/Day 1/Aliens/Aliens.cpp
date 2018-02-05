#include <iostream>
using namespace std;

typedef long long LL;
LL n;
bool query(LL x, LL y)
{
	if (x < 1 || x > n || y < 1 || y > n)
		return 0;
	char s[10];
	cout << "examine " << x << ' ' << y << '\n' << flush;
	cin >> s;
	return s[0] == 't';
}
LL find(LL x, LL y, LL dx, LL dy)
{
	LL l=1, p, q;
	while (query(x+dx*l, y+dy*l))
		l <<= 1;
	if (l == 1)
		return 0;
	p = l>>1;
	q = l;
	while (q-p > 1)
	{
		l = (p+q)>>1;
		if (query(x+dx*l, y+dy*l))
			p = l;
		else
			q = l-1;
	}
	if (p != q && query(x+dx*q, y+dy*q))
		return q;
	return p;
}
void solution(LL x, LL y)
{
	cout << "solution " << x << ' ' << y << '\n' << flush;
}
int main()
{
	LL x, y, m, a, b, c, d;
	cin >> n >> x >> y;
	a = find(x, y, -1, 0);
	b = find(x, y, 1, 0);
	c = find(x, y, 0, 1);
	m = a+b+1;
	x += m/2-a;
	y += c-m/2;
	a = b = c = d = 2;
	while (a <= 4 && query(x-a*m, y))
		a += 2;
	while (b <= 4 && query(x+b*m, y))
		b += 2;
	while (c <= 4 && query(x, y-c*m))
		c += 2;
	while (d <= 4 && query(x, y+d*m))
		d += 2;
	solution((2*x-a*m+b*m)/2, (2*y-c*m+d*m)/2);
	return 0;
}
