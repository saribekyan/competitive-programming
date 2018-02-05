#include <iostream>
using namespace std;

int main()
{
	int k, t, l, L, U, n, i, D, div, P, j;
	cin >> t;
	for (l = 0; l < t; l++)
	{
		cin >> L >> U;
		D = 1;
		P = L;
		for (j = L; j <= U; j++)
		{
			div = 1;
			n = j;
			k = 0;
			while (n % 2 == 0)
			{
				n /= 2;
				k++;
			}
			if (k)
				div *= k+1;
			for (i = 3; i*i<=n; i += 2)
			{
				k = 0;
				while (n % i == 0)
				{
					n /= i;
					k++;
				}
				if (k)
					div *= k+1;
			}
			if (n != 1)
				div *= 2;
			if (D < div)
			{
				D = div;
				P = j;
			}
		}
		cout << "Between " << L << " and " << U << ", " << P << " has a maximum of " << D << " divisors.\n";
	}
	return 0;
}