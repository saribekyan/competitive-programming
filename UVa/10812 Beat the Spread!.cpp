#include <iostream>
using namespace std;

int main()
{
	int n, m, l, t;
	cin >> t;
	for (l = 0; l < t; l++)
	{
		cin >> n >> m;
		if (n >= m && n % 2 == m % 2)
			cout << (n + m) / 2 << " " << n - (n + m) / 2 << endl;
		else
			cout << "impossible" << endl;
	}
	return 0;
}