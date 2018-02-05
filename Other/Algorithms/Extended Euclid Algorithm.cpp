#include <stdio.h>

void rec(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	int x1, y1;
	rec(b, a%b, x1, y1);
	x = y1;
	y = x1-(a/b)*y1;
}
int main()
{
	int a, p, x, y;
	scanf("%d%d", &a, &p);
	rec(a, p, x, y);
	printf("%d\n", x);
	return 0;
}


/*#include <cstdio>
#include <algorithm>
using namespace std;

int d;
typedef pair<int, int> PII;
int gcd(int a, int b)
{
	while (a)
	{
		b %= a;
		swap(a, b);
	}
	return b;
}
PII rec(PII a)
{
	PII ret, b;
	if (a.second == 0)
	{
		ret.first = d/a.first;
		ret.second = 1;
		return ret;
	}
	b.first = a.second;
	b.second = a.first%a.second;
	b = rec(b);
	ret.first = b.second;
	ret.second = b.first-(a.first/a.second)*b.second;
	return ret;
}
int main()
{
	PII ans, a;
//	(a*b)%p == 1
	scanf("%d%d", &a.first, &a.second);
	d = gcd(a.first, a.second);
	ans = rec(a);
	printf("%d\n", ans.first);
	return 0;
}
*/
