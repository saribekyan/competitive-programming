#include <iostream>
using namespace std;

int main()
{
	bool f;
	int n, i, j, k;
	cin >> n;
	while (n)
	{
		k = 0;
		for (i = 2; i <= n / 2; i++)
			if (n % i == 0)
			{
				f = true;
				for (j = 2; j <= i / 2; j++)
					if (i % j == 0)
					{
						f = false;
						break;
					}
				if (f)
					k++;
			}
		f = true;
		for (i = 2; i <= n / 2; i++)
			if (n % i == 0)
			{
				f = false;
				break;
			}
		if (f)
			k++;
		cout << n << " : " << k << endl;
		cin >> n;
	}
	return 0;
}