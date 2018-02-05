#include <iostream>
using namespace std;

void main()
{
	unsigned long long n, m;
	while (cin >> n >> m)
            if (m > n)
		cout << m - n << endl;
            else
                cout << n - m << endl;
}