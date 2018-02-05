#include <iostream>
using namespace std;

int main()
{
	bool f;
	long long n, p;
	while (cin >> n)
	{
		f = true;
		p = 1;
		while (p < n)
			if (f)
			{
				p *= 9;
				f = false;
			}
			else
			{
				p *= 2;
				f = true;
			}
		if (f)
			cout << "Ollie wins." << endl;
		else
			cout << "Stan wins." << endl;
	}
	return 0;
}