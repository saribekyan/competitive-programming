#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;
int main()
{
	LL a, b, c, d;
	scanf("%lld%lld%lld", &a, &b, &c);
	if (a == 0)
	{
		if (b == 0 && c == 0)
		{
			printf("-1\n");
			return 0;
		}
		if (b == 0)
		{
			printf("0\n");
			return 0;
		}
		printf("1\n%.3lf\n", -1.0*c/b);
		return 0;
	}
	d = b*b-4*a*c;
	if (d < 0)
	{
		printf("0\n");
		return 0;
	}
	if (d == 0)
	{
		printf("1\n%.3lf\n", -1.0*b/(2*a));
		return 0;
	}
	if (a > 0)
		printf("2\n%.3lf\n%.3lf\n", (-b-sqrt(d*1.0))/(2.0*a), (-b+sqrt(d*1.0))/(2.0*a));
	else
		printf("2\n%.3lf\n%.3lf\n", (-b+sqrt(d*1.0))/(2.0*a), (-b-sqrt(d*1.0))/(2.0*a));
	return 0;
}
