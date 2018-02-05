#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	double k, l;
	long long n;
	cin >> n;
	while (n)
	{
		k = sqrt((double)n);
		l = ceil(k);
		if (l == k)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		cin >> n;
	}
}