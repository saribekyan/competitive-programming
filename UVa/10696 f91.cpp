#include <iostream>
using namespace std;

void main()
{
	int n, k;
	cin >> n;
	while (n)
	{
		if (n < 101)
			k = 91;
		else
			k = n - 10;
		cout << "f91(" << n << ") = " << k << endl;
		cin >> n;
	}
}
