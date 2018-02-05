#include <iostream>
using namespace std;

int main()
{
	int n, k, i;
	while (cin >> n)
	{
		k = 0;
		while (n % 2 == 0)
		{
			n /= 2;
			k++;
		}
		if (k)
			cout << "2^" << k << "\n";
		for (i = 3; i*i<=n; i += 2)
		{
			k = 0;
			while (n % i == 0)
			{
				n /= i;
				k++;
			}
			if (k)
				cout << i << "^" << k << "\n";
		}
		if (n != 1)
			cout << n << "^1\n";
	}
	return 0;
}