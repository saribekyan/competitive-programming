#include <iostream>
using namespace std;

void main()
{
	unsigned long long n, i, k;
	while (cin >> n)
	{
		i = 1;
		while (i < n)
		{
			i *= 9;
			if (i < n)
			{
				i *= 2;
				k = 1;
			}
			else
			{
				k = 0;
				break;
			}
		}
		if (k)
			cout << "Ollie wins." << endl;
		else
			cout << "Stan wins." << endl;
	}
}