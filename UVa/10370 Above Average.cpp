#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double Av, S;
	int i, t, n, l, k;
	int *N;
	cin >> t;
	for (l = 0; l < t; l++)
	{
		cin >> n;
		N = new int [n];
		S = 0;
		for (i = 0; i < n; i++)
		{
			cin >> N[i];
			S += N[i];
		}
		S /= n;
		k = 0;
		for (i = 0; i < n; i++)
			if (N[i] > S)
				k++;
		Av = 100 / (double)n * (double)k;
		cout << setiosflags(ios::fixed) << setprecision(3);
		cout << Av << "%" << endl;
	}
	return 0;
}